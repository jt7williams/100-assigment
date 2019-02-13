#include "semiColon.hpp"

semiColon::semiColon() {

}

bool semiColon::compute() {
	return true;
}

void semiColon::setLeft(base* b) {
	command_left=b;
}

void semiColon::setRight(base* b) {
	command_right=b;
}
