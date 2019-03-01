#include "or.hpp"

Or::Or() {

}

bool Or::compute(bool* f) {
	if(*f) {
		bool flag = true;
		flag = command_left->compute(f);
		if(!flag) {
			flag = command_right->compute(f);
		} else {
			return flag;
		}
		return flag;
	} else {
		return true;
	}
}

int Or::type() {
	return 2;
}

void Or::setRight(base* b) {
	command_right=b;
}

void Or::setLeft(base* b) {
	command_left=b;
}
