#ifndef COMMAND_H
#define COMMAND_H

#include <string>

#include "Messages.h"
#include "Os.h"
#include "StringOperations.h"

using std::string;

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
	void usage(string command_string)			const;

	bool yes(string message, string reply)			const;

	void add(int argc, char *argv[]);
	void remove(int argc, char *argv[]);

private:
	
	Messages messages;

	Os os;

	StringOperations str_o;

	void _makeClassTemplates(string const &class_name);
};

#endif
