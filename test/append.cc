#include <fstream>

int main() {  
  std::ofstream outfile;

  outfile.open("Makefile", std::ios_base::app); // append instead of overwrite
  outfile << "Data" << std::endl << std::endl; 
  return 0;
}
