g++ -c test.cpp -ISFML-2.4.2/include; g++ test.o -o sfml-app -LSFML-2.4.2/lib -lsfml-graphics -lsfml-window -lsfml-system
export LD_LIBRARY_PATH=SFML-2.4.2/lib
