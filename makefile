execute: main.o
	g++ -o execute main.o

main.o: main.cpp ArrayList.h
	g++ -c main.cpp

make clean:
	rm *.o execute