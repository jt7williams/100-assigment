#include <iostream>
#include <string>
#include "base.hpp"
#include "connector.hpp"
#include "or.hpp"
#include "and.hpp"
#include "semiColon.hpp"
#include "command.hpp"
#include "exit.hpp"
#include <queue>

using namespace std;

void execute(queue<base*> order, bool* flag);
queue<base*> parsing(string input);

int main (int argv, char* argc[]){
	//queue<base*> order;
	string input;
	cout<<"$ ";
	getline(cin, input);
	bool flag = true;
	while(flag) {
		//base* b;
		queue<base*> order;
		order=parsing(input);
		//cout<<"made it out"<<endl;
		execute(order, &flag);
		if(flag) {
			cout<<"$ ";
			getline(cin, input);
		}
	}		
	//execute(b);
	//cout<<input<<endl;
	
	return 0;
}

void execute(queue<base*> order, bool* flag) {
	bool decision = true;
	//cout<<"just inside compute: "<<order.size()<<endl;
	while(!order.empty()) {
		//cout<<"just inside compute: "<<order.size()<<endl;
		//decision = order.front()->compute();
		int type = order.front()->type();
		//cout<<"after type"<<endl;
		if(type == 1) { //command
			//cout<<"inside copmpute"<<endl;
			decision = order.front()->compute();
			decision = !decision;
			order.pop();
		}
		if(type == 2 && decision == true) { //or
			order.pop();
			order.pop();
		} else if (type ==2 && decision == false) {
			order.pop();
		}
		if(type == 3 && decision == true) { //and
			order.pop();
		} else if(type == 3 && decision == false) {
			order.pop();
			order.pop();
		}
		if(type == 4) { //semiColon
			order.pop();
		}
		if(type == 5) {
			*flag = false;
			return;
		}
	}
}

queue<base*> parsing(string input) {
	queue<base*> order;
	base* currentLeft;
	base* currentRoot=nullptr;
	base* currentRight;
	base* b;
	while(!input.empty()) {
		size_t comment = input.find("#");
		size_t first_quote = input.find("\"");
		if(comment < first_quote || first_quote == string::npos) {
			if(comment != string::npos) {
				input = input.substr(0,comment);
				//cout<<input<<endl;
			}
		}
		size_t a = input.find("&&");
		size_t o = input.find("||");
		size_t s = input.find(";");
		if(a != string::npos || o != string::npos || s != string::npos) {
			size_t first = input.find_first_of("&|;");
			
			if(input.substr(0,first-1).compare("exit") == 0) {
				b = new Exit();
				order.push(b);
			} else {
				char tester = input.at(first-1);
				size_t quote = input.find("\"");
				string possible = "";
				if(quote != string::npos) { //looking for quotation marks
					if(quote < first) {
						
						possible = input.substr(0,quote+1);
						input = input.substr(quote+1);
						quote = input.find("\"");
						if(quote != string::npos) {
							possible = possible+input.substr(0,quote+1);
							input = input.substr(quote+1);
						}
						//cout<<"possible: "<<possible<<endl;
						first = input.find_first_of("&|;");
						if(!input.empty()) {
							if(first != 0) {
								tester = input.at(first-1);
								if(tester == ' ') {
                                        				b = new command(possible);
                                				} else {
                                        				b = new command(possible);
									
                                				}
							} else {
								b = new command(possible);
							}
						} else {
							b = new command(possible);
						}
						order.push(b);
					}
					
					//cout<<"here: "<<input<<endl;
				}
				else {
					if(tester == ' ') {
						b = new command(input.substr(0,first-1));
					} else {
						b = new command(input.substr(0,first));
					}
					order.push(b);
				}
				//order.push(b);
				if(input.empty()) {
					//cout<<"returning"<<endl;
					return order;
				}
			}
			//currentLeft->set_command(input.substr(0,first));
			//cout<<input.substr(0,first-1)<<endl;
			input = input.substr(first);
			//order.push(b);
			//cout<<input<<endl;
			//.now get connector
			base* c;
			if(input.at(0) == '&') {
				c = new And();
				if(input.at(2) == ' ') {
					input = input.substr(3);
				}
				else { 
					input = input.substr(2);
				}
				order.push(c);
			} else if(input.at(0) == '|') {
				c = new Or();
				if(input.at(2) == ' ') {
					input = input.substr(3);
				}
				else {
					input = input.substr(2);
				}
				order.push(c);
			} else if(input.at(0) == ';') {
				c = new semiColon();
				if(input.size() < 2) {
					input.clear();
				} else {
					if(input.at(1) == ' ') {
						input = input.substr(2);
					}
					else {
						input = input.substr(1);
					}
				}
				order.push(c);
			}
			//a = input.find("&&");
                	//o = input.find("||");
                	//s = input.find(";");
		} else {
			//b = new command(input);
			if(input.compare("exit") == 0) {
                                b = new Exit();
				order.push(b);
                        } else {
				b= new command(input);
				order.push(b);
			}
			//currentRoot->set_command(input);
			//order.push(b);
			//cout<<input<<endl;
			input.clear();
		} 
	}
	return order;
}
