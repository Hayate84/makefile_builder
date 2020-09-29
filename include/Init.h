#ifndef MAKEFILE_BUILDER_H
#define MAKEFILE_BUILDER_H

/**********************************************************
 *                                                        *
 **********************************************************/

class MakefileBuilder {

public:

	MakefileBuilder(int argc, char *argv[]);

	~MakefileBuilder()

	const char * USAGE;
	const char * HELP;

	void showHelp();
	void showUsage();
};

#endif
