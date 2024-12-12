const fs = require('fs');

function readFilePromise(path, encoding) {
    return new Promise((resolve, reject) => {
        fs.readFile(path, encoding, (err, data) => {
            if (err) {
                reject(err);
            } else {
                resolve(data);
            }
        });
    });
}

readFilePromise('example.txt', 'utf8')
    .then(data => {
        console.log('Zawartość pliku:', data);
    })
    .catch(err => {
        console.error('Błąd odczytu pliku:', err);
    });
