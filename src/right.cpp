#include "right.hpp"

//>

Right::Right() {

}

bool Right::compute(bool* flag) {
   	
	int saveSTD = dup(1);
        set_command(command_right->getName());
        
        int fd = open(argu[0], O_CREAT|O_WRONLY|O_TRUNC); 
	if(fd < 0) {
                cout<<"stream error"<<endl;
                return false;
        } 
	else {	
                dup2(fd, 1);
                command_left->compute(flag);
                dup2(saveSTD, 1);
        }
	close(fd);
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
