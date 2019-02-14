#include "and.hpp"

And::And() {

}

bool And::compute() {
	return true;
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
