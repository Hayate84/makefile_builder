#ifndef __READ_FILE__
#define __READ_FILE__

/*
===============================================================================

Class to read a file.

Method string file_to_string(const char * fileName) takes a file name as an 
input and returns the contents of the file as a string


Method void handleError(const char * message); to handle file errors

===============================================================================
*/

#include <string>

using std::string;

class ReadFile {

public:

  string file_to_string(const char * fileName);

  void handleError(const char * message); 

};

#endif
