LINKER = -lsfml-graphics -lsfml-window -lsfml-system


programa: main.o
	g++ main.o -o Game-app $(LINKER)

main.o: main.cpp
	g++ -c main.cpp

#game.o: game.cpp
#	g++ -c game.cpp

clean:
	rm -f *.o *.out Game-app
