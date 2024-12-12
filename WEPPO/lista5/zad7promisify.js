const fs = require('fs');
const util = require('util');

const readFileAsync = util.promisify(fs.readFile);

readFileAsync('example.txt', 'utf8')
    .then(data => {
        console.log('Zawartość pliku:', data);
    })
    .catch(err => {
        console.error('Błąd odczytu pliku:', err);
    });
