#include <cstdio>
#include <fstream>

#include <sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

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

	const char * message = "This command will build a C++ project. Do you want to continue? [Y/n] ";	
	const char * reply   = "Building C++ project...";

	if (this->yes(message, reply)) {
	
		const int FOLDERS_NUM = 5;
	
		const char *folders[] = {"bin", "build", "include", "src", "test"};
	
		for (int i = 0; i < FOLDERS_NUM; i++) {
				
			this->_makeDirectory(folders[i]);
		
		}
	
		this->_writeToFile("Makefile", messages.getMakefile());

		this->_writeToFile(".gitignore", messages.getGitignore());

		this->_writeToFile("build/.gitignore", messages.getGitkeep());
		this->_writeToFile("bin/.gitignore", messages.getGitkeep());
		
		this->_writeToFile("src/main.cc", messages.getHelloWorld());

		printf("Project builded successfully!\n");
	}
}

/*
==============
Command::yes
==============
*/
bool Command::yes(const char *message, const char *reply) const {

	printf("%s", message);
	
	char input = getchar();
	
	if((input == '\n') || (input == 'Y') || (input == 'y')) {
		
		printf("%s\n", reply);

		return true;
		
	} else {
	
		printf("%s\n", "abort");
		
		return false;
	}

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
Command::_makeDirectory
==============
*/
void Command::_makeDirectory(const char *dirname) const {

	struct stat st;
	
	if (lstat(dirname, &st) == -1) {

		mkdir(dirname, 0777);

	}	

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
