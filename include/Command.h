#ifndef COMMAND_H
#define COMMAND_H

#include "Messages.h"
#include "Os.h"

/*
===============================================================================

Class to encapsulate all commands used in the program.

===============================================================================
*/

class Command {

public:

	Command();
	~Command();
	
	void noCommand()					const;
	void help()						const;
	void build()						const;

	void usage(const char * command_string)			const;

	void add(int argc, char *argv[])			const;
	void remove(int argc, char *argv[])			const;

	bool yes(const char *message, const char *reply)	const;

private:
	
	Messages messages;

	Os os;
	void _writeToFile(const char *filename, const char *data) 	const;
	void _makeDirectory(const char *dirname) 			const;
};

#endif
