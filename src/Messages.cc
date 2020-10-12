#include <cctype>

#include "Messages.h"

/*
==============
Messages::getHelloWorld
==============
*/
string Messages::getHelloWorld() const {

	return "#include <cstdio>\n"
		"\n"
		"int main(void) {\n"
		"\n"
		"\tprintf(\"Hello World\\n\");\n"
		"\n"
		"\treturn 0;\n"
		"}\n";
}

/*
==============
Messages::getGitignore
==============
*/
string Messages::getGitignore() const {

	return "build/*\nbin/*\n";
}

/*
==============
Messages::getGitkeep
==============
*/
string Messages::getGitkeep() const {

	return "*\n!.gitignore";
}

/*
==============
Messages::getMakeFile
==============
*/
string Messages::getMakefile() const {
	
	return "CC = g++\n"
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
		"\tmv main.o ./build/main.o\n";
}

/*
==============
Messages::getUsage
==============
*/
string Messages::getUsage() const {

	return "usage: makefile_builder build\n"
		"   or: makefile_builder add [file1 file2 ...]\n"
		"   or: makefile_builder remove [file1 file2 ...]\n"
		"   or: makefile_builder --help (-h)\n";
}

/*
==============
Messages::getHelp
==============
*/
string Messages::getHelp() const {
	
	return "Common commands:\n"
		"\n"
		"  makefile_builder build                    will build the project and a basic makefile\n"
		"  makefile_builder add [file1 file2 ...]    will add a files to the makefile\n"
		"  makefile_builder remove [file1 file2 ...] will remove files from the makefile\n"
		"\n"
		"Global options:\n"
		"  --help (-h)         show detailed help message\n";
}

/*
==============
Messages::createClassModule
==============
*/
string Messages::createClassModule(string const &class_name) {
	
	return	"#include \"" + class_name + ".h\"\n" 		+
		"\n"						+
		"/*\n"						+
		"==============\n"				+
		class_name + "::" + class_name + "()\n"		+
		"==============\n"				+
		"*/\n"						+
		class_name + "::" + class_name + "() {\n"	+
		"\n"						+
		"}\n"						+
		"\n"						+
		"/*\n"						+
		"==============\n"				+
		class_name + "::~" + class_name + "()\n"	+
		"==============\n"				+
		"*/\n"						+
		class_name + "::~" + class_name + "() {\n"	+
		"\n"						+
		"}\n";			
}

/*
==============
Messages::createClassTemplate
==============
*/
string Messages::createClassTemplate(string const &class_name) {

	return	"#ifndef " + makeHeader(class_name) + "\n" 						+
		"#define " + makeHeader(class_name) + "\n" 						+
		"\n"											+
		"/*\n" 											+
		"===============================================================================\n"	+
		"\n" 											+
		"===============================================================================\n" 	+
		"*/\n"											+
		"\n" 											+
		"class " + class_name + " {\n" 								+
		"\n" 											+
		"public:\n" 										+
		"\t"  + class_name + "();\n"								+
		"\t~" + class_name + "();\n" 								+
		"};\n\n#endif";
}

/*
==============
Messages::getMakefileEntry
==============
*/
string Messages::getMakefileEntry(string const &file) {

	return "\n./build/" + file + ".o: ./src/" + file + ".cc ./include/" + file + ".h\n\t$(CC) $(FLAGS) ./src/" 	+ 
		file + ".cc $(INCLUDE)\n\tmv " + file + ".o ./build/" + file + ".o\n";
}

string Messages::makeHeader(string const &str) {
	
	const int LENGTH = str.length();

	string str_cap("");

	char c = toupper(str[0]);

	str_cap = str_cap + c;
	
	for (int i = 1; i < LENGTH; i++) {
		
		c = str[i];
		
		if (isupper(c)) {
			
			str_cap = str_cap + "_";		
		}

		c = toupper(str[i]);

		str_cap = str_cap + c;
	}
	
	return str_cap + "_H";
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
