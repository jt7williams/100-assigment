#include "semiColon.hpp"

semiColon::semiColon() {

}

bool semiColon::compute() {
	return true;
}

int semiColon::type() {
	return 4;
}

void semiColon::setLeft(base* b) {
	command_left=b;
}

void semiColon::setRight(base* b) {
	command_right=b;
}
