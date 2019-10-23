#include "or.hpp"

Or::Or() {
	status = 0;
}
int Or::get_status(){
	return status;

}
bool Or::compute(bool* f) {

	if(command_left->compute(f)){
		status = 1;
		return true;

	}
	else{
	
		if(command_right->compute(f)){
			status = 2;
			return true;
		}
		else
			return false;
						
	}
/*	if(*f) {i
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
	}*/
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
