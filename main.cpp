#include <iostream>
#include "linked_List.h"
#include "stack.h"
#include "queue.h"
#include "set.h"
#include "dictionary.h"
#include "binarytree.h"
int main(){
binarytree<int>bt;
bt.insertRoot(1);
  bt.insertRight(bt.getRoot(),2);
  bt.insertRight(bt.getRight(bt.getRoot()), 3);
  bt.insertLeft(bt.getRight(bt.getRoot()), 4);
  bt.insertRight(bt.getRight(bt.getRight(bt.getRoot())),5);
  bt.remove(bt.getRight(bt.getRoot()));
  bt.write(bt.getRoot(),10000);
  bt.clear();
  std::cout<<bt<<std::endl;	
	return 0;
}
