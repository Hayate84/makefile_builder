#ifndef COMMAND_H
#define COMMAND_H

#include "Messages.h"

/*
===============================================================================

Class to encapsulate all commands used in the program.

===============================================================================
*/

class Command {

public:

	Command();

	~Command();
	
	void noCommand()			const;
	void help()				const;
	void build()				const;
	void usage(const char * command_string)	const;

private:
	
	Messages messages;


	void _writeToFile(const char *filename, const char *data) const;
};

#endif
