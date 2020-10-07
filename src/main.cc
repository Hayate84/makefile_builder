#include <cstring>

#include "Command.h"

int main(int argc, char *argv[]) {

	Command command;
	
	if (argc == 1) {
		
		command.noCommand();		

	} else {
		
		++argv;
		--argc;

		if (strcmp(*argv, "build") == 0) {

			command.build();
	
		} else if ((strcmp(*argv, "--help") == 0) || (strcmp(*argv, "-h") == 0)) {

			command.help();		

		} else if ((strcmp(*argv, "remove") == 0)) {

			command.remove(--argc, ++argv);

		} else if ((strcmp(*argv, "add") == 0)) {
			
			command.add(--argc, ++argv);		
		
		} else {

			command.usage(*argv);
		}
	}
	
	return 0;
}
