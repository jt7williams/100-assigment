#ifndef __pipe_hpp_
#define __pipe_hpp_
#include "base.hpp"
#include "connector.hpp"

using namespace std;

class Pipe: public connector {
public:
        Pipe();
        bool compute(bool* flag);
        void setLeft(base* b);
        void setRight(base* b);
        int type();
private:
        base* command_left;
        base* command_right;                
};
#endif
