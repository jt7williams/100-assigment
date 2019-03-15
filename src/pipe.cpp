#include "pipe.hpp"

Pipe::Pipe() {

}

bool Pipe::compute(bool* flag) {
	int saveSTDout = dup(1);
	set_command("src/window.hpp");
	int fd = open(argu[0], O_CREAT|O_WRONLY|O_TRUNC);
	if(fd < 0) {
		cout<<"stream error"<<endl;
		return false;
	} else {
		dup2(fd, 1);
		command_left->compute(flag);
		dup2(saveSTDout, 1);
		
	}
	close(fd);
	int saveSTDin = dup(0);
	fd = open(argu[0], O_RDONLY);
	if(fd < 0) {
		cout<<"stream error"<<endl;
		return false;
	} else {
		dup2(fd, 0);
		command_right->compute(flag);
		dup2(saveSTDin, 0);
	}
	close(fd);
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
