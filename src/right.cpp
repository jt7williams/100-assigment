#include "right.hpp"

//>

Right::Right() {

}

bool Right::compute(bool* flag) {
        return true;
}

void Right::setLeft(base* b) {
        command_left=b;
}

void Right::setRight(base* b) {
        command_right=b;
}

int Right::type() {
        return 8;
}
