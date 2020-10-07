#ifndef OS_H
#define OS_H

#include <string>

using std::string;

/*
===============================================================================

Class wrapper of simple operations of linux os.

Methods for writing to a file, reading from a file, making directories etc.

===============================================================================
*/

class Os {

public:
	Os();
	~Os();

	string file_to_string(string fileName)				const;
	
	string get_line_from_string(string const &text, int n_line)	const;

	void write_to_file(string filename, string data)		const;

	void handle_error(string message)				const; 

	void make_directory(string) 					const;
};

#endif
