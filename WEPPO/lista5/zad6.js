const fs = require('fs');
const readline = require('readline');

const ipRequests = {};

const rl = readline.createInterface({
    input: fs.createReadStream('server.log')
});

rl.on('line', (line) => {
    const ipAddress = line.split(' ')[1];
    ipRequests[ipAddress] = ipRequests[ipAddress] ? ipRequests[ipAddress] + 1 : 1;
});

rl.on('close', () => {
    const sortedIPs = Object.entries(ipRequests)
        .sort((a, b) => b[1] - a[1])
        .slice(0, 3);

    console.log('Top 3 adresy IP:');
    sortedIPs.forEach(([ip, count]) => {
        console.log(`${ip} ${count}`);
    });
});
