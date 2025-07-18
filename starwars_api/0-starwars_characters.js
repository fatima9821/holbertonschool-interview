#!/usr/bin/env node

/**
 * Script that prints all characters of a given Star Wars movie
 * Usage: ./0-starwars_characters.js <movie_id>
 */

const request = require('request');

const movieId = process.argv[2];
if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <movie_id>');
  process.exit(1);
}

const apiUrl = `https://swapi-api.alx-tools.com/api/films/${movieId}`;

request(apiUrl, (err, res, body) => {
  if (err) return;

  const film = JSON.parse(body);
  const characters = film.characters;

  // Fetch each character in the same order (asynchronous handling)
  const fetchCharacter = (index) => {
    if (index >= characters.length) return;

    request(characters[index], (err, res, body) => {
      if (!err) {
        const character = JSON.parse(body);
        console.log(character.name);
        fetchCharacter(index + 1);
      }
    });
  };

  fetchCharacter(0);
});