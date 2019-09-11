#include <iostream>
#include "linked_List.h"
#include "stack.h"
#include "queue.h"
#include "set.h"
#include "dictionary.h"
int main(){
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
	l2=l3;//CORREGGI DEMENTE
	
	dictionary<std::string, int> ht(5);

	ht.insert("a", 1);
	ht.insert("b", 1);
	ht.insert("c", 1);
	ht.insert("d", 32);
	ht.insert("e", 12);
	ht.insert("ciao",12);
	ht.remove("ciao");
	dictionary<std::string,int> hp(5);
	hp=ht;
	std::cout << ht << std::endl;
	std::cout << hp << std::endl;
	return 0;
}
