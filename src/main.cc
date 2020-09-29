#include <cstdio>
#include <cstring>

#include "Command.h"

int main(int argc, char *argv[]) {

	Command command;
	
	if (argc == 1) {
		
		command.noCommand();		

	} else {
		
		++argv;

		const char *command_string = *argv;
		
		if (strcmp(command_string, "build") == 0) {

			command.build();
	
		} else if ((strcmp(command_string, "--help") == 0) || (strcmp(command_string, "-h") == 0)) {

			command.help();		

		} else if ((strcmp(command_string, "remove") == 0)) {

			printf("TODO remove\n");

		} else if ((strcmp(command_string, "add") == 0)) {
			
			++argv;			
	
			printf("TODO add file %s\n", *argv);
		
		} else {

			command.usage(command_string);
		
		}	
	}
	
	return 0;
}
