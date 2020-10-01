#ifndef OS_H
#define OS_H

#include <string>

using std::string;

/*
===============================================================================

Class wrapper of simple operations of linux os.

Methods for writing to a file, reading from a file, making directories etc

===============================================================================
*/

class Os {

public:
	
	Os();

	~Os();

	string file_to_string(const char *fileName)			const;
	
	string get_line_from_string(string const &text, int n_line) 	const;

	void write_to_file(const char *filename, const char *data)	const;

	void handle_error(const char *message)				const; 

	void make_directory(const char *dirname) 			const;

};

#endif
