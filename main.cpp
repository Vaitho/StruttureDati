#include <iostream>
#include "linked_List.h"
#include "stack.h"
#include "queue.h"
#include "set.h"
int main(){
/*	linked_list<int> l1;
	
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
	l3.push(3);
	l3.push(2);
	l3.push(1);
	std::cout << l3 << std::endl;
	//l2=l3;
	queue<int> q1;
	q1.push(1);
	q1.push(2);
	
	std::cout <<q1;
	*/
	set<int> s1;
	s1.insert(1);
	s1.insert(12);
	s1.insert(32);
//	s1.remove(s1.find(23));
	set<int> s2;
	s2.insert(1);
	s2.insert(32);
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	s1.difference(s2);
//	set<int> s2(s1);
	if(s1==s2){
		std::cout<<"NO";
	}
	else
	{
		std::cout<<"SI";
			std::cout << s1 << std::endl;
	}
	return 0;
}
