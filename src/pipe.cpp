#include "pipe.hpp"

Pipe::Pipe() {

}

bool Pipe::compute(bool* flag) {
	return true;
}

void Pipe::setLeft(base* b) {
	command_left=b;
}

void Pipe::setRight(base* b) {
	command_right=b;	
}

int Pipe::type() {
	return 8;
}
