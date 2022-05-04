const axios = require('axios');
const fs = require('fs');
const stateMap = require('./StateMap.json')

const competitionId = 'HeartlandChampionship2022';
const Authorization = '';

const EVENTS = [
  {id: '333', resultType: 'average'},
  {id: '222', resultType: 'average'},
  {id: '444', resultType: 'average'},
  {id: '555', resultType: 'average'},
  {id: '666', resultType: 'average'},
  {id: '777', resultType: 'average'},
  {id: '333bf', resultType: 'best'},
  {id: '333fm', resultType: 'average'},
  {id: '333oh', resultType: 'average'},
  {id: 'clock', resultType: 'average'},
  {id: 'minx', resultType: 'average'},
  {id: 'pyram', resultType: 'average'},
  {id: 'skewb', resultType: 'average'},
  {id: 'sq1', resultType: 'average'},
  {id: '444bf', resultType: 'best'},
  {id: '555bf', resultType: 'best'},
  {id: '333mbf', resultType: 'best'}
];

const STATES = [
 'Georgia', 'Alabama', 'South Carolina', 'North Carolina', 'Florida', 'Tennessee', 'Puerto Rico', 'United States Virgin Islands'
]

const getLiveResults = async () => {
  try {
    const config = {
      method: 'get',
      url: 'https://www.worldcubeassociation.org/api/v0/competitions/'+competitionId+'/wcif',
      headers: { 'Authorization': Authorization }
    }
    return await axios(config);
  } catch (error) {
    console.error(error);
  }
}

const convertTime = (milliseconds) => {
  if (milliseconds === -1) return "DNF";                  
  var seconds = Math.floor((milliseconds) / 100);
  var minutes = Math.floor((seconds) / 60);
  var milliseconds = milliseconds % 100;                                       
  return (!!minutes ? `${minutes}:` : "") + `${seconds}.${milliseconds.toString().padStart(2, '0')}`                                        
}      

const calculateChampions = async () => {
  const response = [];
  const liveResults = await getLiveResults();

  if (liveResults.data) {
    let persons = liveResults.data.persons;
    liveResults.data.events.forEach(event => {
      let eventResponse = {id: event.id};

      // Top 3
      let finalRound = event.rounds[event.rounds.length-1];
      eventResponse.first = finalRound.results.filter(r => r.ranking === 1).map(r => ({person: persons.find(p => p.registrantId === r.personId).name, result: convertTime(r[EVENTS.find(e => e.id === event.id).resultType])}));
      eventResponse.second = finalRound.results.filter(r => r.ranking === 2).map(r => ({person: persons.find(p => p.registrantId === r.personId).name, result: convertTime(r[EVENTS.find(e => e.id === event.id).resultType])}));
      eventResponse.third = finalRound.results.filter(r => r.ranking === 3).map(r => ({person: persons.find(p => p.registrantId === r.personId).name, result: convertTime(r[EVENTS.find(e => e.id === event.id).resultType])}));
      
      // SE Champ
      event.rounds.slice().reverse().forEach(r => {
        r.results.forEach(result => {
          if (!eventResponse['Southeast']) {
            let person = persons.find(p => p.registrantId === result.personId).name;
            let pState = stateMap.find(m => m.name === person)?.state;
            if(STATES.includes(pState)) {
              eventResponse['Southeast'] = {person, result: convertTime(result[EVENTS.find(e => e.id === event.id).resultType])}
            }
          }
        })
      })

      // State Champions
      STATES.forEach(state => {
        event.rounds.slice().reverse().forEach(r => {
          r.results.forEach(result => {
            if (!eventResponse[state]) {
              let person = persons.find(p => p.registrantId === result.personId).name;
              let pState = stateMap.find(m => m.name === person)?.state;
              if(pState === state) {
                eventResponse[state] = {person, result: convertTime(result[EVENTS.find(e => e.id === event.id).resultType])}
              }
            }
          })
        })
        if (!eventResponse[state]) {
          eventResponse[state] = {person: "None", result: "DNF"}
        }
      });

      response.push(eventResponse);

    });
  }

  fs.writeFile('./export.json', JSON.stringify(response), err => {
    if (err) {
      console.error(err);
    }
  });
}

calculateChampions();