#ifndef MESSAGES_H
#define MESSAGES_H

/*
===============================================================================

Class to abstract the large text used in the program.

Keep the messages and file templates clean and organized.

===============================================================================
*/

#include <string>
#include <list>

using std::string;
using std::list;

class Messages {

public:

	Messages();

	~Messages();
	
	const char *getHelp()		const;
	const char *getUsage()		const;
	const char *getMakefile()	const;
	const char *getGitignore()	const;
	const char *getGitkeep() 	const;
	const char *getHelloWorld()	const;

	// TODO decouple to other class
	bool in(string const &substring, string const &text);

	void removeChar(string &str, char c);

	list<string> *split(string const &str, char delim);

	string join(list<string> *tokens, char delim);

	string createClassTemplate(string const &class_name);
	string createClassModule(string const &class_name);

	string makeHeader(string const &str);
	void replaceLine(string &text, const int LINE_POSITION, string line);
};

#endif
