const http = require('https');

function promiseGet(url) {
    return new Promise(function (resolve, reject) {
        var client = http.get(url, function(resp) {
            var buf = '';

            resp
                .on('data', function(data) {
                    buf += data.toString();
            })
                .on('end', function() {
                    resolve(buf);
            });
        });
    });
}

(async function() {
    var result = await promiseGet('https://ii.uni.wroc.pl/');
    console.log(result);
})();