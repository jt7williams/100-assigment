#ifndef __test_hpp__
#define __test_hpp__
#include "base.hpp"
#include <string>
#include <iostream>
#include "command.hpp"
#include <sys/stat.h>
class test: public command {
private:
public:
        test();
        test(std::string n);
        bool compute(bool* flag);
        int type();
};

#endif
