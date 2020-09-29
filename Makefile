CC = g++
FLAGS = -c -Wall
INCLUDE = -I ./include
OBJECTS = ./build/main.o ./build/Messages.o

all: program

clean:
	rm ./build/*.o
	rm ./bin/program 
 
program: $(OBJECTS)	
	$(CC) -o $@ $?
	mv program ./bin/program

./build/main.o: ./src/main.cc
	$(CC) $(FLAGS) ./src/main.cc $(INCLUDE)
	mv main.o ./build/main.o

./build/Messages.o: ./src/Messages.cc ./include/Messages.h
	$(CC) $(FLAGS) ./src/Messages.cc $(INCLUDE)
	mv Messages.o ./build/Messages.o


