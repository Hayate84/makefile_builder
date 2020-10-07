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

	void removeChar(string &str, char c);

	void replaceLine(string &text, const int LINE_POSITION, string line);

	list<string> *split(string const &str, char delim);

	string join(list<string> *tokens, char delim);
};

#endif
