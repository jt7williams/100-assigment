#ifndef _right_hpp__
#define _right_hpp__
#include "base.hpp"
#include "connector.hpp"

using namespace std;

class Right: public connector {//>
public:
        Right();
        bool compute(bool* flag);
        void setLeft(base* b);
        void setRight(base* b);
        int type();
private:
        base* command_left;
        base* command_right;
};
#endif
