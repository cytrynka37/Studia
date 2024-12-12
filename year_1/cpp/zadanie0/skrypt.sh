if [ $? -eq 0 ]; then
    echo "Kompilacja zakonczona sukcesem. Uruchamiam program..."
    ./main
else
    echo "Kompilacja zakonczona niepowodzeniem."
fi
