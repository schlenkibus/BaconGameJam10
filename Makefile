all:
	g++ -std=c++0x -w *.cpp *.h -o Game-U -I/home/jscheil/.sfml/include -L/home/jscheil/.sfml/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	./Game-U

optimize:
	g++ -std=c++0x -O3 -w *.cpp *.h -o Game-O -I/home/jscheil/.sfml/include -L/home/jscheil/.sfml/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	./Game-O
