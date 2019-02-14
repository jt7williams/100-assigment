#ifndef __or_hpp__
#define __or_hpp__
#include "connector.hpp"
#include "base.hpp"

class Or: public connector {
public:
	Or();
	bool compute();
	void setLeft(base* b);
	void setRight(base* b);
	int type();
private:
	base* command_left;
	base* command_right;
};
#endif
