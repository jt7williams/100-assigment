#include "paren.hpp"

Paren::Paren() {

}

bool Paren::compute() {
        return true;
}

int Paren::type() {
        return 6;
}

void Paren::setRight(base* b) {
        command_right=b;
}

void Paren::setLeft(base* b) {
        command_left=b;
}
