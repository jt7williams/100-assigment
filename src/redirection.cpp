#include "redirection.hpp"

//>>

Redirection::Redirection() {

}

bool Redirection::compute(bool* flag) {
	
	int saveSTD = dup(1);
        set_command(command_right->getName());

        int fd = open(argu[0], O_CREAT|O_WRONLY|O_APPEND);
        if(fd < 0) {
                cout<<"stream error"<<endl;
                return false;
        }
        else {
                dup2(fd, 1);
                command_left->compute(flag);
                dup2(saveSTD, 1);
        }


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
