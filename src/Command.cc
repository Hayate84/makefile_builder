#include <cstdio>
#include <fstream>

#include "Command.h"

/*
==============
Command::Command
==============
*/
Command::Command() {
	

}

/*
==============
Command::~Command
==============
*/
Command::~Command() {

}

/*
==============
Command::build
==============
*/
void Command::build() const {
	
	this->_writeToFile("Makefile", messages.getMakefile());
	this->_writeToFile(".gitignore", messages.getGitignore());

}

/*
==============
Command::noCommand
==============
*/
void Command::noCommand() const {

	printf("%s", "error: no command supplied\n\n");
	printf("%s", messages.getUsage());

}

/*
==============
Command::help
==============
*/
void Command::help() const {

	printf("%s", messages.getHelp());

}

/*
==============
Command::usage
==============
*/
void Command::usage(const char *command_string) const {
	
	printf("error: invalid command '%s'\n\n", command_string);
	printf("%s", messages.getUsage());

}

/*
==============
Command::_writeToFile
==============
*/
void Command::_writeToFile(const char *filename, const char *data) const {

	std::ofstream file(filename);
	file << data;

}
