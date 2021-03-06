#include <cctype>
#include <iterator>

#include "StringOperations.h"

/*
==============
StringOperations::StringOperations()
==============
*/
StringOperations::StringOperations() {

}

/*
==============
StringOperations::~StringOperations()
==============
*/
StringOperations::~StringOperations() {

}

/*
==============
StringOperations::in
==============
*/
bool StringOperations::in(string const &substring, string const &text) {
	
	list<string> *tokens = this->split(text, ' ');

	for (list<string>::iterator it = tokens->begin(); it != tokens->end(); ++it) {
		
		string current_string(*it);

		if (current_string == substring) {
			
			delete tokens;	return true;
		}
	}
	
	delete tokens;	return false;
}

/*
==============
StringOperations::removeChar
==============
*/
void StringOperations::removeChar(string &text, char delim) {
	
	const int LENGTH = text.length();
		
	string current_token("");
	
	for (int i = 0; i < LENGTH; i++) {
		
		char c = text[i];
		
		if (c != delim) {
			
			current_token = current_token + c;
		}
	}
	
	text = current_token;
}

/*
==============
StringOperations::replaceLine
==============
*/
void StringOperations::replaceLine(string &text, const int LINE_POSITION, string line) {
	
	list<string> *tokens = this->split(text, '\n');

	int i = 0;

	for (list<string>::iterator it = tokens->begin(); it != tokens->end(); ++it) {

		if (i == LINE_POSITION) {
		
			*it = line;	
		
			break;
		}

		++i;
	}

	text = this->join(tokens, '\n');

	delete tokens;
}

/*
==============
StringOperations::join
==============
*/
string StringOperations::join(list<string> *tokens, char delim) {
	
	string joined_message("");

	for (list<string>::iterator it = tokens->begin(); it != tokens->end(); ++it) {

		string current_string = *it;
		
		joined_message = joined_message + current_string + delim;	
	}
	
	return joined_message;
}

/*
==============
StringOperations::removeOccurence
==============
*/
void StringOperations::removeOccurence(string &text, string const &occurence, char delim) {
	
	list<string> *tokens = this->split(text, delim);
	
	string joined_message("");

	for (list<string>::iterator it = tokens->begin(); it != tokens->end(); ++it) {

		string current_string = *it;

		if (current_string != occurence) {
		
			joined_message = joined_message + current_string + delim;	
		}
	}
	
	delete tokens;	
	
	text = removeLastChar(joined_message);
}

/*
==============
StringOperations::split
==============
*/
list<string> *StringOperations::split(string const &text, char delim) {

	list<string> *tokens = new list<string>();

	const int LENGTH = text.length();
		
	string current_token("");
	
	for (int i = 0; i < LENGTH; i++) {
		
		char c = text[i];
		
		if (c == delim) {
			
			tokens->push_back(current_token);			
			
			current_token = "";

		} else {

			current_token = current_token + c;
		}
	}

	if (delim != '\n') {
		
		tokens->push_back(current_token);			
	}
	
	return tokens;
}

/*
==============
StringOperations::removeLastChar
==============
*/
string StringOperations::removeLastChar(string &text) {
	
	return text.substr(0, text.size() - 1);
}
