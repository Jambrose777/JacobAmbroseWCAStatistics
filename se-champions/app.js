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
    let maxRanks = {};
    liveResults.data.events.forEach(event => {
      let eventResponse = {id: event.id};
      maxRanks[event.id] = event.rounds[0].results.length + 1;

      // Top 3
      let finalRound = event.rounds[event.rounds.length-1];
      eventResponse.first = finalRound.results.filter(r => r.ranking === 1).map(r => ({person: persons.find(p => p.registrantId === r.personId).name, result: convertTime(r[EVENTS.find(e => e.id === event.id).resultType])}))[0];
      eventResponse.second = finalRound.results.filter(r => r.ranking === 2).map(r => ({person: persons.find(p => p.registrantId === r.personId).name, result: convertTime(r[EVENTS.find(e => e.id === event.id).resultType])}))[0];
      eventResponse.third = finalRound.results.filter(r => r.ranking === 3).map(r => ({person: persons.find(p => p.registrantId === r.personId).name, result: convertTime(r[EVENTS.find(e => e.id === event.id).resultType])}))[0];
      
      event.rounds.slice().reverse().forEach(r => {
        r.results.forEach(result => {

          // SE Champ
          if (!eventResponse['Southeast']) {
            let person = persons.find(p => p.registrantId === result.personId).name;
            let pState = stateMap.find(m => m.name === person)?.state;
            if(STATES.includes(pState)) {
              eventResponse['Southeast'] = {person, result: convertTime(result[EVENTS.find(e => e.id === event.id).resultType])}
            }
          }

          // State Champions
          STATES.forEach(state => {
            if (!eventResponse[state]) {
              let person = persons.find(p => p.registrantId === result.personId).name;
              let pState = stateMap.find(m => m.name === person)?.state;
              if(pState === state) {
                eventResponse[state] = {person, result: convertTime(result[EVENTS.find(e => e.id === event.id).resultType])}
              }
            }
          })


          if(event.id === '333'){
            // Fastest Female
            if (!eventResponse['Female']) {
              let person = persons.find(p => p.registrantId === result.personId);
              if(person.gender === 'f') {
                eventResponse['Female'] = {person: person.name, result: convertTime(result[EVENTS.find(e => e.id === event.id).resultType])}
              }
            }

            // Fastest Newcomer
            if (!eventResponse['Newcomer']) {
              let person = persons.find(p => p.registrantId === result.personId);
              if(person.wcaId === null) {
                eventResponse['Newcomer'] = {person: person.name, result: convertTime(result[EVENTS.find(e => e.id === event.id).resultType])}
              }
            }
          }

        })
      })

      // State Champion blanks
      STATES.forEach(state => {
        if (!eventResponse[state]) {
          eventResponse[state] = {person: "None", result: "None"}
        }
      });

      response.push(eventResponse);

    });

    // Sum of Ranks
    const SorWinner = liveResults.data.persons.map(p => {
      let sor = liveResults.data.events.map(e => {
        let eventRank = 0
        e.rounds.slice().reverse().forEach(round => {
          if (eventRank === 0){
            result = round.results.find(r => r.personId === p.registrantId);
            if(result) eventRank = result.ranking;
          }
        })
        if(eventRank === 0) {
          eventRank = maxRanks[e.id];
        }
        return eventRank;
      }).reduce((sumOfRanks, eventRank) => sumOfRanks + eventRank, 0);
      return {name: p.name, sor}
    }).reduce((best, p) => {
      if(!best || best.sor > p.sor) return p;
      return best;
    }, null);

    // fs.writeFile('./export.json', JSON.stringify(response), err => {
    //   if (err) {
    //     console.error(err);
    //   }
    // });

    let responseString = '';
    response.forEach(e => {
      responseString += e.id + '  - 1st Place - ' + e.first.person + ' - ' + e.first.result + '\n';
      responseString += e.id + '  - 2nd Place - ' + e.second.person + ' - ' + e.second.result + '\n';
      responseString += e.id + '  - 3rd Place - ' + e.third.person + ' - ' + e.third.result + '\n';
      responseString += e.id + '  - Southeast Champion - ' + e.Southeast.person + ' - ' + e.Southeast.result + '\n';
      responseString += e.id + '  - Georgia Champion - ' + e.Georgia.person + ' - ' + e.Georgia.result + '\n';
      responseString += e.id + '  - Alabama Champion - ' + e.Alabama.person + ' - ' + e.Alabama.result + '\n';
      responseString += e.id + '  - South Carolina Champion - ' + e['South Carolina'].person + ' - ' + e['South Carolina'].result + '\n';
      responseString += e.id + '  - North Carolina Champion - ' + e['North Carolina'].person + ' - ' + e['North Carolina'].result + '\n';
      responseString += e.id + '  - Florida Champion - ' + e.Florida.person + ' - ' + e.Florida.result + '\n';
      responseString += e.id + '  - Tennessee Champion - ' + e.Tennessee.person + ' - ' + e.Tennessee.result + '\n';
      if (e.id === '333') {
        responseString += e.id + '  - Fastest Female - ' + e.Female.person + ' - ' + e.Female.result + '\n';
        responseString += e.id + '  - Fastest Newcomer - ' + e.Newcomer.person + ' - ' + e.Newcomer.result + '\n';
      }
    });
    responseString += 'SOR - ' + SorWinner.name + ' - ' + SorWinner.sor + '\n';

    fs.writeFile('./export.txt', responseString, err => {
      if (err) {
        console.error(err);
      }
    });

  }
}

calculateChampions();