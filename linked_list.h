#include <iostream>
#include "list.h"

template<class T>
class linked_list;

template<class T>
class Node{
	friend class linked_list<T>;
private:
	T value;
	Node<T> * next;
	Node<T> * prev;
};

template<class T>
class linked_list : public list<T,Node<T> *>{
	public:
		linked_list();	//COSTRUTTORE
		linked_list(const linked_list<T>&);	//COSTRUTTORE DI COPIA
		~linked_list();	//DISTRUTTORE
		
		linked_list<T>& operator=(const linked_list<T> &list);//OVERLOAD1
		linked_list<T>& operator==(const linked_list<T> &list);//OVERLOAD2
		
		
		void clear();	//CANCELLA LISTA
		bool empty() const;	//LISTA VUOTA
		size_t size() const;//GRANDEZZA LISTA
		void pushback(T v);//INSERISCI NELLA CODA
		void pushfront(T v);//INSERISCI NELLA TESTA
		Node<T> *begin() const;//RESTITUISCE TESTA
		Node<T> *asdbegin() const;//RESTITUISCE CODA
		bool end(Node<T> *p) const;//Check
		Node<T> *next(Node<T> *p) const; //POSIZIONE SUCC
		Node<T> * previous(Node<T> *p) const; //POSIZIONE PREC
		T read(Node<T> *p) const; //LEGGI LISTA
		void rewrite(Node<T> *p, T v);//RISCRIVE
		void insert(Node<T> *p, T v);//INSERISCE
		void remove(Node<T> *p);//RIMUOVE
		Node<T> *find(T v) const;//RICERCA
	
	private:
		Node<T> * head;
		Node<T> * tail;
		int length=0;
};

//COSTRUTTORE
template <class T>
linked_list<T>::linked_list(){
	head=tail=nullptr;
}

//COSTRUTTORE COPIA
template<typename T>
linked_list<T>::linked_list(const linked_list<T> &l){
	head=tail=nullptr;
	Node<T> *tmp = l.begin();

	while(!l.end(tmp)){
		pushback(tmp->value);
		tmp=tmp->next;
	}
		length=l.size();

}


//DISTRUTTORE
template<typename T>
linked_list<T>::~linked_list(){
	clear();
}

//PUSHBACK
template<typename T>
void linked_list<T>::pushback(T v){
    Node<T> *node = new Node<T>;
    node->value = v;
    node->next = nullptr; 
    if(empty()){
        node->prev = nullptr;
        head = node;
    }else{
        tail->next = node;
        node->prev = tail;
    }
    tail = node;
    length++;
}

//PUSHFRONT
template <typename T>
void linked_list<T>::pushfront(T v){
	Node<T> *node = new Node<T>;
	node->value = v;
	node->prev = nullptr;
	if (empty()){
		node->next = nullptr;
		head=node;
	}else{
		head->prev= node;
		node->next= head;
	}
	head=node;
	length++;
}

//EMPTY
template <class T>
bool linked_list<T> ::empty() const {
	return head == nullptr;
}

//CLEAR
template<typename T>
void linked_list<T>::clear(){
	Node<T> *tmp;
	while(head != nullptr)
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

//SIZE
template<typename T>
size_t linked_list<T>::size() const {
	return length;
}

//BEGIN
template<typename T>
Node<T> *linked_list<T>::begin() const{
	return head;
}
//ASDBEGIN
template<typename T>
Node<T> *linked_list<T>::asdbegin() const{
	return tail;
}

//END
template<typename T>
bool linked_list<T>::end(Node<T> *p) const{
 	return p->next == nullptr;
}

//SUCC
template<typename T>
Node<T> *linked_list<T>::next(Node<T> *p) const{
	return p->next;
}

//PREC
template<typename T>
Node<T> *linked_list<T>::previous(Node<T> *p) const{
	return p->prev;
}

//LEGGI
template<typename T>
T linked_list<T>::read(Node<T> *p) const{
	return p->value;
}

//RISCRIVO
template<typename T>
void linked_list<T>::rewrite(Node<T> *p, T v){
	p->value=v;
}

//INSERISCO
template<typename T>
void linked_list<T>::insert(Node<T> *p, T v){
	Node<T> *node=new Node<T>;
	node->value=v;
	node->next=p->next;
	node->prev=p;

	if(p->next == nullptr){
		tail = node;
	}
	else{
		p->next->prev=node;
	}
	p->next=node;
	length++;
}

//RIMUOVE
template<typename T>
void linked_list<T>::remove(Node<T> *p){
	if(p->prev == nullptr){
		p->next->prev= nullptr;
	}
	else if(p->next == nullptr){
		p->prev->next = nullptr;
	}
	else{
		p->prev->next=p->next;
		p->next->prev=p->prev;
	}
	delete(p);
	length--;
}

//RICERCA
template<typename T>
Node<T> *linked_list<T>::find(T v)const{
	Node<T> *tmp=new Node<T>;
	bool found=false;
	tmp = begin();
	while(!end(tmp) and !found){
		if(tmp->value==v){
			found=true;
		}
		else{
			tmp=next(tmp);	
		}
	}
	return tmp;	
}

//OVERLOAD 
template<class T>
linked_list<T>& linked_list<T>::operator=(const linked_list<T> &list){
	if(this!=&list){
		clear();
		size=list.size();
		Node<T> *temp=list.begin();
		while(!list.end(temp)){
			pushback(temp->back);
			temp=temp->next;
		}
	}
	length=list.size();
	return *this;
}

//OVERLOAD 2.0 
template<class T>
linked_list<T>& linked_list<T>::operator==(const linked_list<T> &list){
	if(this.size()!=list.size()){
		return false;
	}
	Node<T> *temp1=list.begin();
	Node<T> *temp2=begin();
	while(!end(temp1)){
		if(temp1->value!=temp2->value){
			return false;
		}
		temp1=next(temp1);
		temp2=next(temp2);
	}
	return true;
}
