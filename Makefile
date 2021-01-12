CC = g++
FLAGS = -c -Wall
INCLUDE = -I ./include
OBJECTS = ./build/main.o ./build/Messages.o ./build/Command.o ./build/Os.o ./build/StringOperations.o

all: makefile_builder

clean:
	rm ./build/*.o
	rm ./bin/makefile_builder

makefile_builder: $(OBJECTS)
	$(CC) -o $@ $?
	mv makefile_builder ./bin/makefile_builder

./build/main.o: ./src/main.cc
	$(CC) $(FLAGS) ./src/main.cc $(INCLUDE)
	mv main.o ./build/main.o

./build/Messages.o: ./src/Messages.cc ./include/Messages.h
	$(CC) $(FLAGS) ./src/Messages.cc $(INCLUDE)
	mv Messages.o ./build/Messages.o

./build/Command.o: ./src/Command.cc ./include/Command.h
	$(CC) $(FLAGS) ./src/Command.cc $(INCLUDE)
	mv Command.o ./build/Command.o

./build/Os.o: ./src/Os.cc ./include/Os.h
	$(CC) $(FLAGS) ./src/Os.cc $(INCLUDE)
	mv Os.o ./build/Os.o

./build/StringOperations.o: ./src/StringOperations.cc ./include/StringOperations.h
	$(CC) $(FLAGS) ./src/StringOperations.cc $(INCLUDE)
	mv StringOperations.o ./build/StringOperations.o
