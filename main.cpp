#include <iostream>
#include "linked_List.h"
#include "stack.h"
#include "queue.h"

int main(){
	linked_list<int> l1;
	
	l1.pushback(12);
	l1.pushfront(23);
	std::cout << l1 << std::endl;
	
	stack<int> l2;
	l2.push(1);
	l2.push(2);
	l2.push(3);
	l2.push(4);
	l2.pop();
	std::cout << l2 << std::endl;

	stack<int> l3;
	l3.push(4);
	
	//l2=l3;
	queue<int> q1;
	q1.push(12345679);
	q1.push(12);
	q1.pop();
	queue<int> q2;
	q2=q1;
	std::cout <<q2;
	return 0;
}
