#include <iostream>
#include <fstream>

#include <cstdlib>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "Os.h"

using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::ofstream;

/*
================
Os::file_to_string
================
*/
string Os::file_to_string(const char * fileName) const {

	ifstream in_file;

	in_file.open(fileName);

	if (in_file.is_open() == false) handle_error("ERROR::READ_FILE.CC::COULD_NOT_OPEN_FILE");

	string rv, temp = "";

	while (getline(in_file, temp) != NULL) rv = rv + temp + '\n';

	in_file.close();

	return rv;
}

/*
================
Os::handle_error 
================
*/
void Os::handle_error(const char * message) const {
	
	//simple handles error by exiting the program
	cout << message << endl;

	exit(EXIT_FAILURE);
}

/*
==============
Command::_makeDirectory
==============
*/
void Os::make_directory(const char *dirname) const {

	struct stat st;
	
	if (lstat(dirname, &st) == -1) {

		mkdir(dirname, 0777);
	}	
}

/*
==============
Os::write_to_file
==============
*/
void Os::write_to_file(const char *filename, const char *data) const {

	ofstream file(filename);

	file << data;
}

/*
==============
Os::Os
==============
*/
Os::Os() {

}

/*
==============
Os::~Os
==============
*/
Os::~Os() {

}
