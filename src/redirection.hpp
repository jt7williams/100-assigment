#ifndef __redirection_hpp__
#define __redirection_hpp__
#include "base.hpp"
#include "connector.hpp"

class Redirection: public connector {
public:
        Redirection();
        bool compute(bool* flag);
        void setLeft(base* b);
        void setRight(base* b);
        int type();
private:
        base* command_left;
        base* command_right;
};
#endif
