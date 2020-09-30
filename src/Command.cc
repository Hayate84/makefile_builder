#include <cstdio>

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
				
			os.make_directory(folders[i]);
		}
	
		os.write_to_file("Makefile", messages.getMakefile());

		os.write_to_file(".gitignore", messages.getGitignore());

		os.write_to_file("build/.gitignore", messages.getGitkeep());
		os.write_to_file("bin/.gitignore", messages.getGitkeep());
		
		os.write_to_file("src/main.cc", messages.getHelloWorld());

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
Command::add
==============
*/
void Command::add(int argc, char *argv[]) const {

	for (int i = 0; i < argc; i++)	printf("%s\n", argv[i]);
}

/*
==============
Command::remove
==============
*/
void Command::remove(int argc, char *argv[]) const {
	
	printf("TODO remove\n");
}
