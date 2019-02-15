#ifndef __exit_hpp__
#define __exit_hpp__
#include "base.hpp"

using namespace std;

class Exit : public base {
public:
	Exit();
	bool compute();
	int type();
};
#endif
