#ifndef __and_hpp__
#define __and_hpp__
#include "connector.hpp"
#include "base.hpp"

class And: public connector {
public:
	And();
	bool compute();
	void setRight(base* b);
	void setLeft(base* b);
private:
	base* command_left;
	base* command_right;
};
#endif
