#include "paren.hpp"

Paren::Paren() {

}

Paren::Paren(int type) {
	id=type;
}

bool Paren::compute(bool* f) {
        return true;
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
