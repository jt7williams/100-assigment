#ifndef __and_hpp__
#define __and_hpp__
#include "connector.hpp"
#include "base.hpp"

class And: public connector {
public:
	And();
	void compute();
private:
	base* command_left;
	base* command_right;
};
#endif
