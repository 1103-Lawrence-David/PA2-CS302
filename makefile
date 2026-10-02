execute: main.o SnakeGame.o
	g++ -o execute main.o SnakeGame.o

main.o: main.cpp SnakeGame.h 
	g++ -c main.cpp

SnakeGame.o: SnakeGame.h SnakeGame.cpp Node.h Position.h LinkedList.h ArrayList.h tests.h
	g++ -c SnakeGame.cpp
make clean:
	rm *.o execute