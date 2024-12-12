const randomNumber = Math.floor(Math.random() * 101);

process.stdout.write("Podaj swoją liczbę: ");


process.stdin.on('data', (data) => {
    const userGuess = parseInt(data.toString().trim(), 10);

    if (isNaN(userGuess)) {
        console.log("Proszę podać liczbę.");
    } else if (userGuess === randomNumber) {
        console.log("To jest właśnie ta liczba! Gratulacje!");
        process.stdin.pause();
        return;
    } else if (userGuess < randomNumber) {
        console.log("Moja liczba jest większa.");
    } else {
        console.log("Moja liczba jest mniejsza.");
    }
     
    process.stdout.write("Spróbuj jeszcze raz: ");
});
