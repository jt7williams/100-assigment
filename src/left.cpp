#include "left.hpp"

//<

Left::Left() {

}

bool Left::compute(bool* flag) {
        return true;
}

void Left::setLeft(base* b) {
        command_left=b;
}

void Left::setRight(base* b) {
        command_right=b;
}

int Left::type() {
        return 8;
}
