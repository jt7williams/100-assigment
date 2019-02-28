#include "semiColon.hpp"

semiColon::semiColon() {
	command_left = nullptr;
	command_right= nullptr;
}

bool semiColon::compute(bool* f) {
	if(f) {
		command_left->compute(f);
		command_right->compute(f);
		return true;
	} else {
		return true;
	}
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
