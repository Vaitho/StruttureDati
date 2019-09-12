#include <iostream>
#include "linked_List.h"
#include "stack.h"
#include "queue.h"
#include "set.h"
#include "dictionary.h"
#include "binarytree.h"
int main(){
	binarytree<int> tree;
	btNode<int> *n=new btNode<int>;
	tree.insertRoot(12);
	tree.insertRight(tree.getRoot(),32);
	tree.insertLeft(tree.getRight(tree.getRoot()),153);
	tree.insertRight(tree.getRight(tree.getRoot()),43);
	tree.remove(tree.getRight(tree.getRoot()));
	std::cout<<tree<<std::endl;
	return 0;
}
