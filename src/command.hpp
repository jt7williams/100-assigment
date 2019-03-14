#ifndef __command_hpp__
#define __command_hpp__
#include "base.hpp"
#include <string>
#include <iostream>
#include <sys/types.h>
#include <stdio.h> 
#include <sys/wait.h>
#include <unistd.h> 

class command : public base {
private:
	std::string name;
public:
	command();
	command(std::string n);
	bool compute(bool* flag);
	int type();
	std::string cutComments(std::string input);
	std::string getName();
};
#endif
