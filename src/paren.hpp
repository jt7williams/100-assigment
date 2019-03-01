#ifndef __paren_hpp__
#define __paren_hpp__
#include "base.hpp"
#include "base.hpp"

class Paren: public base {
public:
        Paren();
	Paren(int id);
        bool compute(bool* flag);
	void setWrap(base* b);
        void setLeft(base* b);
        void setRight(base* b);
        int type();
private:
	int id;
	base* wrap;
        base* command_left;
        base* command_right;
};
#endif
