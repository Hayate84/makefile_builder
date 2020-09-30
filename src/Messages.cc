#include "Messages.h"

/*
==============
Messages::getHelloWorld
==============
*/
const char *Messages::getHelloWorld() const {

	const char *str = "#include <cstdio>\n"
		"\n"
		"int main(void) {\n"
		"\n"
		"\tprintf(\"Hello World\\n\");\n"
		"\n"
		"\treturn 0;\n"
		"}\n";

	return str;
}

/*
==============
Messages::getGitignore
==============
*/
const char *Messages::getGitignore() const {

	const char *str = "build/*\nbin/*\n";

	return str;
}

/*
==============
Messages::getGitkeep
==============
*/
const char *Messages::getGitkeep() const {

	const char *str = "*\n!.gitignore";

	return str;
}

/*
==============
Messages::getMakeFile
==============
*/
const char *Messages::getMakefile() const {
	
	const char *str = "CC = g++\n"
		"FLAGS = -c -Wall\n"
		"INCLUDE = -I ./include\n"
		"OBJECTS = ./build/main.o\n"
		"\n"
		"all: program\n"
		"\n"
		"clean:\n"
		"\trm ./build/*.o\n"
		"\trm ./bin/program\n"
		"\n"
		"program: $(OBJECTS)\n"
		"\t$(CC) -o $@ $?\n"
		"\tmv program ./bin/program\n"
		"\n"
		"./build/main.o: ./src/main.cc\n"
		"\t$(CC) $(FLAGS) ./src/main.cc $(INCLUDE)\n"
		"\tmv main.o ./build/main.o\n"
		"\n";

	return str;
}

/*
==============
Messages::getUsage
==============
*/
const char *Messages::getUsage() const {

	const char *str = "usage: makefile_builder build\n"
		"   or: makefile_builder add [file1 file2 ...]\n"
		"   or: makefile_builder remove [file1 file2 ...]\n"
		"   or: makefile_builder --help (-h)\n";

	return str;
}

/*
==============
Messages::getHelp
==============
*/
const char *Messages::getHelp() const {
	
	const char *str = "Common commands:\n"
		"\n"
		"  makefile_builder build                    will build the project and a basic makefile\n"
		"  makefile_builder add [file1 file2 ...]    will add a files to the makefile\n"
		"  makefile_builder remove [file1 file2 ...] will remove files from the makefile\n"
		"\n"
		"Global options:\n"
		"  --help (-h)         show detailed help message\n";

	return str;
}

/*
==============
Messages::Messages
==============
*/
Messages::Messages() { 

}

/*
==============
Messages::~Messages
==============
*/
Messages::~Messages() {

}
