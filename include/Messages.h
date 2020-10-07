#ifndef MESSAGES_H
#define MESSAGES_H

#include <string>

using std::string;

/*
===============================================================================

Class to abstract the large text used in the program.

Keep the messages and file templates clean and organized.

===============================================================================
*/

class Messages {

public:
	Messages();
	~Messages();
	
	string getHelp()	const;
	string getUsage()	const;
	string getMakefile()	const;
	string getGitignore()	const;
	string getGitkeep() 	const;
	string getHelloWorld()	const;

	string getMakefileEntry(string const &file);

	string createClassTemplate(string const &class_name);
	string createClassModule(string const &class_name);
	string makeHeader(string const &str);
};

#endif
