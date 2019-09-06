#include <iostream>
#include "linked_List.h"

int main(){
	std::cout << "linked list test" << std::endl;
	linked_list<int> l1;
	l1.pushback(12);
	l1.pushback(69);
	l1.pushback(32);
	l1.pushback(45);
	l1.pushfront(23);
	l1.pushfront(1);
	std::cout << l1 << std::endl;
	l1.reverse();
	
	std::cout << l1 << std::endl;
	return 0;
}
