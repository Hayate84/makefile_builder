#include <cstdio>
#include <cstring>
#include <cctype>

#include <iterator>

#include "Messages.h"

/*
==============
Messages::capitalize
==============
*/
//TODO capitalize
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
		"class " + class_name + "{\n" 								+
		"\n" 											+
		"public:\n" 										+
		"\t"  + class_name + "();\n"								+
		"\t~" + class_name + "();\n" 								+
		"};\n" 											+
		"\n" 											+
		"#endif\n";
}

/*
==============
Messages::in
==============
*/
bool Messages::in(string const &substring, string const &text) {
	
	list<string> *tokens = this->split(text, ' ');

	list<string>::iterator it; 

	for (it = tokens->begin(); it != tokens->end(); ++it) {
		
		string current_string(*it);

		if (current_string == substring) {
			
			delete tokens;
			
			return true;
		}
	}
	
	delete tokens;

	return false;
}

/*
==============
Messages::removeChar
==============
*/
void Messages::removeChar(string &str, char delim) {
	
	const int LENGTH = str.length();
		
	string current_token("");
	
	for (int i = 0; i < LENGTH; i++) {
		
		char c = str[i];
		
		if (c != delim) {
			
			current_token = current_token + c;
		}
	}
	
	str = current_token;
}

/*
==============
Messages::replaceLine
==============
*/
void Messages::replaceLine(string &text, const int LINE_POSITION, string line) {
	
	list<string> *tokens = this->split(text, '\n');

	int i = 0;

	for (list<string>::iterator it = tokens->begin(); it != tokens->end(); ++it) {

		if (i == LINE_POSITION) {
		
			*it = line;	
		
			break;
		}

		++i;
	}

	text = this->join(tokens, '\n');

	delete tokens;
}

/*
==============
Messages::join
==============
*/
string Messages::join(list<string> *tokens, char delim) {
	
	string joined_message("");

	for (list<string>::iterator it = tokens->begin(); it != tokens->end(); ++it) {

		string current_string = *it;
		
		joined_message = joined_message + current_string + delim;	
	}
	
	return joined_message;
}

/*
==============
Messages::split
==============
*/
list<string> *Messages::split(string const &str, char delim) {

	list<string> *tokens = new list<string>();

	const int LENGTH = str.length();
		
	string current_token("");
	
	for (int i = 0; i < LENGTH; i++) {
		
		char c = str[i];
		
		if (c == delim) {
			
			tokens->push_back(current_token);			
			
			current_token = "";

		} else {

			current_token = current_token + c;
		}
	}

	if (delim != '\n') {
		
		tokens->push_back(current_token);			
	}
	
	return tokens;
}

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
		"\tmv main.o ./build/main.o\n";

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
