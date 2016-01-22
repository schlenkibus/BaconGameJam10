all:
	g++ -std=c++0x -w *.cpp *.h -o SFML-Game -I/home/jscheil/.sfml/include -L/home/jscheil/.sfml/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	./SFML-Game
