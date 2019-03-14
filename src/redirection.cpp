#include "redirection.hpp"

//>>

Redirection::Redirection() {

}

bool Redirection::compute(bool* flag) {
        return true;
}

void Redirection::setLeft(base* b) {
        command_left=b;
}

void Redirection::setRight(base* b) {
        command_right=b;
}

int Redirection::type() {
        return 8;
}
