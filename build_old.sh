g++ -std=c++11 -ISFML-2.4.2/include -c test.cpp
g++ -std=c++11 -IBall -ISFML-2.4.2/include -c Ball/Ball.cpp
g++ -std=c++11 -o sfml-app test.o -LSFML-2.4.2/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
export LD_LIBRARY_PATH=SFML-2.4.2/lib
