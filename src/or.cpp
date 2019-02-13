#include "or.hpp"

Or::Or() {

}

bool Or::compute() {
	return true;
}

void Or::setRight(base* b) {
	command_right=b;
}

void Or::setLeft(base* b) {
	command_left=b;
}
