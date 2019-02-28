#ifndef __and_hpp__
#define __and_hpp__
#include "connector.hpp"
#include "base.hpp"
#include <string>
#include <iostream>

class And: public connector {
public:
	And();
	bool compute(bool* flag);
	void setRight(base* b);
	void setLeft(base* b);
	int type();
private:
	base* command_left;
	base* command_right;
};
#endif
