#include "left.hpp"

//<

Left::Left() {

}

bool Left::compute(bool* flag) {
	int saveSTD = dup(0);
	set_command(command_right->getName());

	int fd = open(argu[0], O_RDONLY);
	//printf("%s\n", argu[0]);
	if(fd < 0) {
		cout<<"stream error"<<endl;
		return false;
	}
	 else {
		dup2(fd, 0);
		command_left->compute(flag);
		dup2(saveSTD, 0);
	}
	close(fd);	
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
