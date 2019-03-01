#include "paren.hpp"

Paren::Paren() {

}

Paren::Paren(int type) {
	id=type;
}

bool Paren::compute(bool* f) {
        if(f) {
		return wrap->compute(f);
	} else {
		return true;
	}
}

void Paren::setWrap(base* b) {
	wrap = b;
}

int Paren::type() {
	if(id == 0)
        	return 6;
	else 
		return 7;
}

void Paren::setRight(base* b) {
        command_right=b;
}

void Paren::setLeft(base* b) {
        command_left=b;
}
