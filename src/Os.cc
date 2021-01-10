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
Os::get_line_from_string
================
*/
string Os::get_line_from_string(string const &text, int n_line) const {

	const int LENGTH      = text.length();
	const int NOT_IN_LINE = 0;
	const int IN_LINE     = 1;

	int mode  = NOT_IN_LINE;
	int lines = 0;
	
	string str("");
	
	for (int i = 0; i < LENGTH; i++) {
			
		char c = text[i];	

		if (mode == NOT_IN_LINE) {		

			if (c == '\n') {

				++lines;
			
				if (lines == n_line) {
				
					mode = IN_LINE;
				}
			}		

		} else {

			str = str + c;
			
			if (c == '\n') { 

				return str;
			}
		}
	}

	return str;
}	

/*
================
Os::file_to_string
================
*/
string Os::file_to_string(string filename) const {

	ifstream in_file;

	in_file.open(filename.c_str());

	if (in_file.is_open() == false) handle_error("ERROR::OS.CC::COULD_NOT_OPEN_FILE::" + filename);

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
void Os::handle_error(string message) const {
	
	//simple handles error by exiting the program
	cout << message << endl;

	exit(EXIT_FAILURE);
}

/*
==============
Command::_makeDirectory
==============
*/
void Os::make_directory(string dirname) const {

	struct stat st;
	
	if (lstat(dirname.c_str(), &st) == -1) {

		mkdir(dirname.c_str(), 0777);
	}	
}

/*
==============
Os::write_to_file
==============
*/
void Os::write_to_file(string filename, string data) const {

	ofstream out_file;

	out_file.open(filename.c_str());

	if (out_file.is_open() == false) handle_error("ERROR::OS.CC::COULD_NOT_OPEN_FILE::" + filename);

	out_file << data;

	out_file.close();
}

/*
==============
Os::delete_file
==============
*/
void Os::delete_file(string filename) const {
	
	int error_code = remove(filename.c_str());

	if (error_code != 0) handle_error("ERROR::OS.CC::COULD_NOT_DELETE_FILE::" + filename);
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
