#!/usr/local/bin/node
const request = require('request');
const movieId = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/' + movieId;

request(url, async (err, response, body) => {
  if (err) {
    console.log(err);
  }
  for (const charId of JSON.parse(body).characters) {
    await new Promise((resolve, reject) => {
      request(charId, (err, response, body) => {
        if (err) {
          reject(err);
        }
        console.log(JSON.parse(body).name);
        resolve();
      });
    });
  }
});