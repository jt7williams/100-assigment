#ifndef __base_hpp__
#define __base_hpp__
#include <string>

class base {

	public:
		base(){};
		virtual bool compute() {return 0;}
		virtual int type() {return 0;}

};
#endif
