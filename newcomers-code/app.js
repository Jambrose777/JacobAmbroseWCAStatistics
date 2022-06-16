const axios = require('axios');
const fs = require('fs');

const competitionId = 'GaCubersPride2022';
const Authorization = 'Bearer 5Rk-UMkiXYzMphNUikWwna9XdpjHAFv7Tcg_RFsYeVk';

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

const calculateFastestNewcomers = async () => {
  const response = [];
  const liveResults = await getLiveResults();

  if (liveResults.data) {
    let persons = liveResults.data.persons;
    results3x3 = liveResults.data.events.find(event => event.id === '333');
    if (results3x3) {
      results3x3.rounds.slice().reverse().forEach(r => {
        r.results.forEach(result => {
          let person = persons.find(p => p.registrantId === result.personId);
          if(person.wcaId === null && !response.find(rs => rs.name === person.name)) {
            response.push({name: person.name, result: convertTime(result.average), round: r.id})
          }
        })
      })
    }
  }

  fs.writeFile('./export.json', JSON.stringify(response), err => {
    if (err) {
      console.error(err);
    }
  });
}

calculateFastestNewcomers();