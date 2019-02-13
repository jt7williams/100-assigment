#ifndef __semiColon_hpp__
#define __semiColon_hpp__
#include "connector.hpp"
#include "base.hpp"

class semiColon : public connector {
public:
	semiColon();
	void compute();
private:
	base* command_left;
	base* command_right;

};
#endif
