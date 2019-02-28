#ifndef __command_hpp__
#define __command_hpp__
#include "base.hpp"
#include <string>
#include <iostream>
#include <sys/types.h>


class command : public base {
private:
	char* argu[3];
	char* one;
	char* two;
public:
	command();
	command(std::string n);
	bool compute(bool* flag);
	void set_command(std::string n);
	int type();
	std::string cutComments(std::string input);
};
#endif
