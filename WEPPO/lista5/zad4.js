const fs = require('fs');

fs.promises.readFile('example.txt', 'utf8')
    .then(data => {
        console.log('Zawartość pliku:\n', data);
    })
    .catch(err => {
        console.error('Błąd :', err);
    });