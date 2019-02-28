#ifndef __paren_hpp__
#define __paren_hpp__
#include "connector.hpp"
#include "base.hpp"

class Paren: public connector {
public:
        Paren();
	Paren(int id);
        bool compute(bool* flag);
        void setLeft(base* b);
        void setRight(base* b);
        int type();
private:
	int id;
        base* command_left;
        base* command_right;
};
#endif
