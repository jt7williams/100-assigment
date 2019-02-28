#ifndef __test_hpp__
#define __test_hpp__
#include "base.hpp"
#include <string>
#include <iostream>
#include <sys/types.h>

using namespace std;

class test : public base {
private:
        char* argu[3];
        char* one;
        char* two;
public:
        test();
        test(string n);
        bool compute();
        void set_command(string n);
        int type();
};

#endif
