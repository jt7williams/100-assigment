#include "exit.hpp"

Exit::Exit() {

}

bool Exit::compute(bool* flag) {
	*flag = false;
	return true;
}

int Exit::type() {
	return 5;
}
