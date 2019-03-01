#include "and.hpp"

And::And() {

}

bool And::compute(bool* f) {
	if(*f) {
		bool flag = true;
		flag = command_left->compute(f);
		//std::cout<<*f<<std::endl;
		if(flag && *f) {
			//std::cout<<"before second"<<std::endl;
			flag = command_right->compute(f);
			//std::cout<<"after second"<<std::endl;
		} else {
			//std::cout<<1<<std::endl;
			return flag;
		}
		return flag;
	} else {
		return true;
	}
}

int And::type() {
	return 3;
}

void And::setRight(base* b) {
	command_right = b;
}

void And::setLeft(base* b) {
	command_left=b;
}
