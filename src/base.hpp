#ifndef __base_hpp__
#define __base_hpp__
#include <string>

class base {

	public:
		base(){};
		virtual bool compute(bool* flag) {return 0;}
		virtual int type() {return 0;}
		virtual void setLeft(base* b) {return;}
		virtual void setRight(base* b) {return;}
};
#endif
