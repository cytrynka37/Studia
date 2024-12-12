g++ main.cpp -o program
if [ $? -eq 0 ]; then
    echo "Kompilacja zakończona sukcesem. Podaj argumenty: "
    read -r arguments
    ./program $arguments
else
    echo "Błąd podczas kompilacji programu."
fi
