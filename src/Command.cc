#include <iostream>

#include <cstdio>

#include "Command.h"

using std::cout;
using std::endl;

/*
==============
Command::Command
==============
*/
Command::Command() {
	
}

/*
==============
Command::~Command
==============
*/
Command::~Command() {

}

/*
==============
Command::build
==============
*/
void Command::build(int argc, char *argv[]) {

	if (argc == 0) {

		cout << "error: build command need an extra argument [program_name]" << endl << endl;
		cout << messages.getUsage();
		return;
	}
	
	string program_name(*argv);

	string message = "This command will build a C++ project. Do you want to continue? [Y/n] ";	
	string reply   = "Building C++ project...";

	if (this->yes(message, reply)) {
	
		const int FOLDERS_NUM = 5;
	
		const char *folders[] = {"bin", "build", "include", "src", "test"};
	
		for (int i = 0; i < FOLDERS_NUM; i++) {
			
			string current_folder(folders[i]);
				
			os.make_directory(current_folder);
		}
	
		os.write_to_file("Makefile", messages.getMakefile(program_name));

		os.write_to_file(".gitignore", messages.getGitignore());

		os.write_to_file("build/.gitignore", messages.getGitkeep());
		os.write_to_file("bin/.gitignore", messages.getGitkeep());
		
		os.write_to_file("src/main.cc", messages.getHelloWorld());

		cout << "Project builded successfully!" << endl;
	}
}

/*
==============
Command::_makeClassTemplates
==============
*/
void Command::_makeClassTemplates(string const &class_name) {
	
	string FILENAME_H	= "include/"	+ class_name + ".h";
	string FILENAME_CC	= "src/" 	+ class_name + ".cc";	

	string CLASS_H	= messages.createClassTemplate(class_name);
	string CLASS_CC	= messages.createClassModule(class_name);

	os.write_to_file(FILENAME_H, CLASS_H);
	os.write_to_file(FILENAME_CC, CLASS_CC);
}

/*
==============
Command::yes
==============
*/
bool Command::yes(string message, string reply) const {

	cout << message;
	
	char input = getchar();
	
	if((input == '\n') || (input == 'Y') || (input == 'y')) {
		
		cout << reply << endl;

		return true;
		
	} else {
	
		cout << "abort" << endl;
		
		return false;
	}
}

/*
==============
Command::noCommand
==============
*/
void Command::noCommand() const {

	cout << "error: no command supplied" << endl << endl;
	cout << messages.getUsage();
}

/*
==============
Command::help
==============
*/
void Command::help() const {

	cout << messages.getHelp();
}

/*
==============
Command::usage
==============
*/
void Command::usage(string command_string) const {
	cout << "error: invalid command '" << command_string << "'" << endl << endl;
	cout << messages.getUsage();
}

/*
==============
Command::add
==============
*/
void Command::add(int argc, char *argv[]) {

	const int OBJECT_FILES_LINE = 3;

	string makefile    = os.file_to_string("Makefile");
	string object_line = os.get_line_from_string(makefile, OBJECT_FILES_LINE);

	for (int i = 0; i < argc; i++) {
		
		str_o.removeChar(object_line, '\n');

		string current_arg(*argv++);
	
		string object_to_add = "./build/" + current_arg + ".o";
			
		bool in = str_o.in(object_to_add, object_line);
		
		if (in == false) {
						
			//replace the line 
			object_line = object_line + " " + object_to_add;	
			str_o.replaceLine(makefile, OBJECT_FILES_LINE, object_line);	

			//add entries to the makefile 
			makefile = makefile + messages.getMakefileEntry(current_arg);

			//make the files
			this->_makeClassTemplates(current_arg);				
		}
	}

	//finally write the string to the disc
	os.write_to_file("Makefile", makefile);
}

/*
==============
Command::remove
==============
*/
void Command::remove(int argc, char *argv[]) {

	const int OBJECT_FILES_LINE = 3;

	for (int i = 0; i < argc; i++) {
		
		string makefile = os.file_to_string("Makefile");

	        string object_line = os.get_line_from_string(makefile, OBJECT_FILES_LINE);
		str_o.removeChar(object_line, '\n');

		string current_arg(*argv++);
	
		string object_to_remove = "./build/" + current_arg + ".o";

		bool in = str_o.in(object_to_remove, object_line);
		
		if (in == true) {

			//replace the line 
			str_o.removeOccurence(object_line, object_to_remove, ' ');	
			str_o.replaceLine(makefile, OBJECT_FILES_LINE, object_line);	

			this->_remove_entry(makefile, object_to_remove);				

			//delete the files
			this->_delete_files(current_arg);
		}

		//finally write the string to the disc
		os.write_to_file("Makefile", makefile);
	}
}

/*
==============
Command::_removeEntry
==============
*/
void Command::_remove_entry(string &makefile, string object_to_remove) {
	
	bool removed		= false;
	object_to_remove	= object_to_remove + ":";
				
	list<string> *lines = str_o.split(makefile, '\n');

	string newMakefile = "";
	for (list<string>:: iterator it = lines->begin(); it != lines->end(); ++it) {

		string current_string(*it);

		bool in = str_o.in(object_to_remove, current_string);
				
		if (in == true) {

			removed = true;

			++it;	++it; 							//we dont need the next three lines

			if (++it == lines->end()) { 					//check if we reached eof

				newMakefile	= str_o.removeLastChar(newMakefile); 	//skip next entry line	
				makefile	= str_o.removeLastChar(newMakefile);	

				delete lines; return;
			}

			current_string = *it;						 //get next entry to add
		}

		if (removed == true) {

			newMakefile = newMakefile + current_string; 
			removed = false;			
		} else {			

			newMakefile = newMakefile + current_string + "\n";
		}
	}	

	makefile = str_o.removeLastChar(newMakefile);	delete lines;	
}

/*
==============
Command::_delete_files
==============
*/
void Command::_delete_files(string const &current_arg) {

	string SOURCE_PATH  = "src/"     + current_arg + ".cc";
	string INCLUDE_PATH = "include/" + current_arg + ".h";

	os.delete_file(SOURCE_PATH);
	os.delete_file(INCLUDE_PATH);
}
