#include <cstdio>
#include <cstring>

#include "Messages.h"

int main(int argc, char *argv[]) {

	Messages messages;
	
	if (argc == 1) {
		
		printf("%s", "error: no command supplied\n\n");
		printf("%s", messages.getUsage());

	} else {
		
		++argv;

		const char *command = *argv;

		if (strcmp(command, "build") == 0) {

			printf("%s", messages.getMakefile());

		} else if ((strcmp(command, "--help") == 0) || (strcmp(command, "-h") == 0)) {

			printf("%s", messages.getHelp());
		
		} else if ((strcmp(command, "remove") == 0)) {

			printf("TODO remove\n");

		} else if ((strcmp(command, "add") == 0)) {
			
			printf("TODO add\n");

		} else {

			printf("error: invalid command '%s'\n\n", command);
			printf("%s", messages.getUsage());

		}	
	}
	
	return 0;
}
