#ifndef OS_H
#define OS_H

/*
===============================================================================

Class wrapper of simple operations of linux os.

Methods for writing to a file, reading from a file, making directories etc

===============================================================================
*/

#include <string>

using std::string;

class Os {

public:
	
	Os();

	~Os();

	string file_to_string(const char *fileName)			const;

	void write_to_file(const char *filename, const char *data)	const;

	void handle_error(const char *message)				const; 

	void make_directory(const char *dirname) 			const;

};

#endif
