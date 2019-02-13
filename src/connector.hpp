#ifndef __connector_hpp__
#define __connector_hpp__
#include "base.hpp"

class connector: public base {

public:
	connector();
	bool compute();

private:
	base* command_left;
	base* command_right;
};
#endif
