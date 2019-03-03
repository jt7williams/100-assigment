#include <iostream>
#include <string>
#include "base.hpp"
#include "connector.hpp"
#include "or.hpp"
#include "and.hpp"
#include "semiColon.hpp"
#include "command.hpp"
#include "exit.hpp"
#include "paren.hpp"
#include "test.hpp"
#include <queue>

using namespace std;

void execute(queue<base*> order, bool* flag);
base* parsing(string & input, int* count);

int main (int argv, char* argc[]){
	//queue<base*> order;
	string input;
	//cout<<"$ ";
	//getline(cin, input);
	bool flag = true;
	while(flag) {
		base* b = new semiColon();
		base* s;
		int count = 0;
		queue<base*> order;
		do {
			cout<<"$ ";
			getline(cin, input);
			count = 0;
			s = parsing(input, &count);
			//cout<<"here"<<endl;
			if(count%2 != 0) {
				cout<<"Error: uneven parentheses"<<endl;
			}
		} while(count%2 !=0);	
		//execute(order, &flag);
		//cout<<"before compute"<<endl;
		//b = new command("echo hello");
		s->compute(&flag);
		//cout<<"after compute"<<endl;
	}
	
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
			decision = order.front()->compute(&decision);
			decision = !decision;
			order.pop();
		}
		if(type == 2 && decision == true) { //or
			order.pop();
		} else if (type ==2 && decision == false) {
			order.pop();
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

base* parsing(string & input, int* count) {
	queue<base*> order;
	base* currentHead=nullptr;
	base* currentRoot=nullptr;
	base* b;
	int round = 0;
	while(!input.empty()) {
		while(input.at(0) == ' ') {
			input = input.substr(1);
		}
		if(input.at(0) == '#') {
			return new command("");
		}
		size_t comment = input.find("#");
		size_t first_quote = input.find("\"");
		if(comment < first_quote || first_quote == string::npos) { //errase comments
			if(comment != string::npos) {
				input = input.substr(0,comment);
			}
		}
		size_t a = input.find("&&");
		size_t o = input.find("||");
		size_t s = input.find(";");
		size_t ep = input.find(")");
		if(a != string::npos || o != string::npos || s != string::npos || ep != string::npos) {
			size_t first = input.find_first_of("&|;)");
		if(input.at(0) == '(') {
			int k = *count;
			k=k+1;
			*count = k;
                        Paren* p = new Paren(); 
                        input = input.substr(1);
			//cout<<"inside paren main: "<<input<<endl;
			p->setWrap(parsing(input, count));
			//cout<<"after paren main: "<<input<<endl;
			if(currentRoot == nullptr) {
				currentRoot=p;  
			} else {
				currentRoot->setRight(p);
			}
                } else {
			if(input.substr(0,first-1).compare("exit") == 0 || input.substr(0,first).compare("exit") == 0) {
				//cout<<"inside exit"<<endl;
				b = new Exit();
				if(currentRoot == nullptr) {
					currentRoot=b;
					round++;
				} else {
					currentRoot->setRight(b);
				}
				input = input.substr(first);
				order.push(b);
			} else {
				char tester = input.at(first-1);
				size_t quote = input.find("\"");
				string possible = "";
				if(quote != string::npos && quote < first) { //looking for quotation marks
					possible = input.substr(0,quote+1);
					input = input.substr(quote+1);
					quote = input.find("\"");
					if(quote != string::npos) {
						possible = possible+input.substr(0,quote+1);
						input = input.substr(quote+1);
					}
					first = input.find_first_of("&|;)");
					
					possible.erase(possible.find("\""), 1);
					possible.erase(possible.find("\""), 1);
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
					if(currentRoot == nullptr) {
						currentRoot=b;
						round++;
					} else {
						currentRoot->setRight(b);
					}
					order.push(b);	
				}
				else {
					if(tester == ' ') {
						string test_tester = "";
						test_tester = input.substr(0,first-1);
						if(test_tester.substr(0,4).compare("test") == 0) {
							test_tester = test_tester.substr(5);
							b = new test(test_tester);
							cout<<test_tester<<endl; 
						} else if (test_tester.at(0) == '[') {
							test_tester = test_tester.substr(1);
							if(test_tester.at(0) == ' ') {
								test_tester=test_tester.substr(1);
							}
							test_tester = test_tester.substr(0,test_tester.size()-1);
							cout<<test_tester<<endl;
							b = new test(test_tester);
						} else {
							b = new command(test_tester);
						}
					} else {
						//cout<<"no here: "<<input.substr(0,first)<<endl;
						string test_tester = input.substr(0,first);
                                                if(test_tester.substr(0,4).compare("test") == 0) {
                                                        test_tester = test_tester.substr(5);
                                                        b = new test(test_tester);
                                                        //cout<<test_tester<<endl;
                                                } else if (test_tester.at(0) == '[') {
                                                        test_tester = test_tester.substr(1);
                                                        if(test_tester.at(0) == ' ') {
                                                                test_tester=test_tester.substr(1);
                                                        }
                                                        test_tester = test_tester.substr(0,test_tester.size()-1);
                                                        if(test_tester.at(test_tester.size()-1) == ' ')
								test_tester = test_tester.substr(0, test_tester.size()-1);
							//cout<<test_tester<<endl;
                                                        b = new test(test_tester);
                                                } else {
							b = new command(test_tester);
						}
					}
					if(currentRoot == nullptr) {
						currentRoot=b;
						round++;
					} else {
						currentRoot->setRight(b);
					}
					order.push(b);
				}
				if(input.empty()) {
					return currentRoot;
				}
				input = input.substr(first);
			}//
		}//end of parentheses else
		//input = input.substr(first);
		if(input.empty()) {
			return currentRoot;
		}
		if(input.at(0) == ')') {
			int k = *count;
			k=k+1;
			*count = k;
			input = input.substr(1);
			//cout<<"returning paren 1"<<input<<endl;
			return currentRoot;
		} else if (input.at(0) == ' ') {
			input = input.substr(1);
			//cout<<"returning paren 2"<<endl;
			//return currentRoot;
		}
			
			//input = input.substr(first);
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
				//cout<<"after and: "<<input<<endl;
				c->setLeft(currentRoot);//creating tree
				currentRoot=c;
				order.push(c);
			} else if(input.at(0) == '|') {
				c = new Or();
				if(input.at(2) == ' ') {
					//cout<<"first"<<endl;
					input = input.substr(3);
				}
				else { 
					//cout<<"second: "<<input<<endl;
					input = input.substr(2);
				}
				//cout<<"after or: "<<input<<endl;
				c->setLeft(currentRoot);//creating tree
				currentRoot=c;
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
				//cout<<"after semi: "<<input<<endl;
				c->setLeft(currentRoot);//creating tree
				currentRoot=c;
				order.push(c);
			}
			if(input.at(0) == ')') {
				int k = *count;
				k=k+1;
				*count = k;
				input = input.substr(1);
				return currentRoot;
			}
		} else {
			size_t first = input.find_first_of(")");
			if(input.substr(0,4).compare("exit") == 0) {
                                b = new Exit();
				if(currentRoot == nullptr) {
					currentRoot=b;
				} else {
					currentRoot->setRight(b);
				}
				order.push(b);
                        } else {
				string test_tester = "";
                                test_tester = input;
                                if(test_tester.substr(0,4).compare("test") == 0) {
                                        test_tester = test_tester.substr(5);
                                        b = new test(test_tester);
                                        //cout<<test_tester<<endl;
                                } else if (test_tester.at(0) == '[') {
                                        test_tester = test_tester.substr(1);
                                	if(test_tester.at(0) == ' ') {
                                        	test_tester=test_tester.substr(1);
                                        }
                                        test_tester = test_tester.substr(0,test_tester.size()-1);
					//cout<<test_tester<<endl;
					if(test_tester.at(test_tester.size()-1) == ' ')
						test_tester = test_tester.substr(0, test_tester.size()-1);
                                        //cout<<test_tester<<endl;
                                        b = new test(test_tester);
                                } else {
					if(test_tester.find("\"") != string::npos) {
						test_tester.erase(test_tester.find("\""), 1);
						test_tester.erase(test_tester.find("\""), 1);
					}
                                        b = new command(test_tester);
                                }
				if(currentRoot == nullptr) {
					currentRoot=b;
				} else {
					currentRoot->setRight(b);
				}
				order.push(b);
			}
			input.clear();
		} 
	}
	return currentRoot;
}
