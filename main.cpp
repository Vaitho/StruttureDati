#include <iostream>
#include "linked_List.h"
#include "stack.h"

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
	
	stack<int> l2;
	l2.push(1);
	l2.push(2);
	l2.push(3);
	l2.push(4);
	l2.pop();
	std::cout<<l2;
	
	return 0;
}
