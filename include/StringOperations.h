#ifndef STRING_OPERATIONS_H
#define STRING_OPERATIONS_H

#include <string>
#include <list>

using std::string;
using std::list;

/*
===============================================================================

Common operations on a string.

===============================================================================
*/

class StringOperations {

public:

	StringOperations();
	~StringOperations();

	bool in(string const &substring, string const &text);

	void removeChar(string &text, char c);

	void removeOccurence(string &text, string const &occurence, char delim);

	void replaceLine(string &text, const int LINE_POSITION, string line);

	list<string> *split(string const &text, char delim);
	
	string join(list<string> *tokens, char delim);

	string removeLastChar(string &text);
};

#endif
