#include <iostream>
#include <fstream>

#include <cstdlib>

#include "ReadFile.h"

using std::cout;
using std::endl;
using std::getline;
using std::ifstream;

/*
================
file_to_string
================
*/

string ReadFile::file_to_string(const char * fileName) {

  ifstream in_file;

  in_file.open(fileName);

  if (in_file.is_open() == false) handleError("ERROR::READ_FILE.CC::COULD_NOT_OPEN_FILE");

  string rv, temp = "";

  while (getline(in_file, temp) != NULL) rv = rv + temp + '\n';

  in_file.close();

  return rv;
}

/*
================
handleError 

 simple handles error by exiting the program
================
*/

void ReadFile::handleError(const char * message) {

  cout << message << endl;

  exit(EXIT_FAILURE);
}
