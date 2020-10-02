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
void Command::add(int argc, char *argv[]) {

	const int OBJECT_FILES_LINE = 3;

	string makefile    = os.file_to_string("Makefile");
	string object_line = os.get_line_from_string(makefile, OBJECT_FILES_LINE);

	for (int i = 0; i < argc; i++) {
		
		messages.removeChar(object_line, '\n');

		string current_arg(*argv++);
	
		string object_to_add = "./build/" + current_arg + ".o";
			
		bool in = messages.in(object_to_add, object_line);
		
		if (in == false) {
						
			object_line = object_line + " " + object_to_add + "\n";
		
			printf("%s", object_line.c_str());

		} else printf("%s", messages.createClassTemplate("someBigClassToImport").c_str());
	}

}

/*
==============
Command::remove
==============
*/
void Command::remove(int argc, char *argv[]) {
	
	printf("TODO remove\n");
}
