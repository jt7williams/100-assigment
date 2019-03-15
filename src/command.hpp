#ifndef __command_hpp__
#define __command_hpp__
#include "base.hpp"

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
