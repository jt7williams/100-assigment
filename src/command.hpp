#ifndef __command_hpp__
#define __command_hpp__
#include "base.hpp"
#include <string>
#include <iostream>
#include <sys/types.h>


class command : public base {
private:
	char* argu[3];
public:
	command();
	command(std::string n);
	bool compute();
	void set_command(std::string n);


};
#endif
