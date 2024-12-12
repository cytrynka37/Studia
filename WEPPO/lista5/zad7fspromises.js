const fs = require('fs');

fs.promises.readFile('example.txt', 'utf8')
    .then(data => {
        console.log('Zawartość pliku:', data);
    })
    .catch(err => {
        console.error('Błąd odczytu pliku:', err);
    });

    /*
async function readFileAndLog() {
    try {
        const data = await fs.promises.readFile('example.txt', 'utf8');
        console.log('Zawartość pliku:', data);
    } catch (err) {
        console.error('Błąd odczytu pliku:', err);
    }
}

readFileAndLog();*/