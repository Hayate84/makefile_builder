#ifndef MESSAGES_H
#define MESSAGES_H

/*
===============================================================================

Class to abstract the large text used in the program.

Keep the messages and file templates clean and organized.

===============================================================================
*/

class Messages {

public:

	Messages();

	~Messages();
	
	const char *getHelp()		const;
	const char *getUsage()		const;
	const char *getMakefile()	const;
	const char *getGitignore()	const;

};

#endif
