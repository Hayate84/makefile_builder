/*
===============================================================================

Driver program to test ReadFile class.

Behaves as the cat program

===============================================================================
*/

#include <iostream>

#include "ReadFile.h"

using std::cout;     
using std::endl; 

int main(int argc, char ** argv) {

  ReadFile readFile;
  
  if (argc != 2) readFile.handleError("ERROR::MAIN.CC::INVALID_NUMBER_OF_PARAMETERS");

  string fileString = readFile.file_to_string (argv[1]);

  cout << fileString;

  return 0;
}
