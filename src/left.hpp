#ifndef _left_hpp__
#define _left_hpp__
#include "base.hpp"
#include "connector.hpp"
#include <stdio.h>

using namespace std;

class Left: public connector { //<
public:
        Left();
        bool compute(bool* flag);
        void setLeft(base* b);
        void setRight(base* b);
        int type();
private:
        base* command_left;
        base* command_right;
};
#endif
