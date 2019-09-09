#include <iostream>

template<class T>
class stack;

template<class T>
class sNode{
	friend class stack<T>;
	
	template <class K>
  	friend std :: ostream& operator<<(std::ostream&os, const stack<K>&);
  	
	private:
		T value;
		sNode<T> *prev;
};


template<class T>
class stack{
	public:
		stack();//COSTRUTTORE
		stack(const stack &s);//COSTRUTTORE COPIA
		~stack();//DISTRUTTORE
		
		void clear();//RESET STACK
		bool empty() const;//CHECK
		size_t get_size() const;//RESTITUISCE LA LUNGHEZZA
		void push(T v);//INSERISCE
		void pop();//RIMUOVE
		T get_top() const;//RESTITUISCE LA TESTA
		
		template <class K>
 	   friend std :: ostream& operator<<(std::ostream& os, const stack<K>&);
 	   
 	   stack<T>& operator=(const stack<T> &);//OVERLOAD1
   		bool operator==(const stack<T> &);//OVERLOAD2

		
	private:
		sNode<T> *top;
		size_t length=0;
};

//COSTRUTTORE
template<typename T>
stack<T>::stack(){
	top=nullptr;
	length=0;
}

//COSTRUTTORE PER COPIA
template<typename T>
stack<T>::stack(const stack &s){
	top=nullptr;
	length=0;
	sNode<T> *tmp1 = s.top;
	top = new sNode<T>;
	top->value=tmp1->value;
	top->prev=nullptr;
	tmp1=tmp1->prev;
	sNode<T> *tmp2=top;
	
	while(tmp1!=nullptr){
		sNode<T> *node = new sNode<T>;
		node->value=tmp1->value;
		node->prev=nullptr;
		tmp2->prev=node;
		tmp1 = tmp1->prev;
		tmp2 = tmp2->prev;
	}
	length=s.get_size();
}

//DISTRUTTORE
template<typename T>
stack<T>::~stack(){
	clear();
}

//INSERISCE L'ELEMENTO IN TESTA
template<typename T>
void stack<T>::push(T v){
	sNode<T> *node = new sNode<T>;
	node->value=v;
	node->prev=top;
	top=node;
	length++;
}

//RIMUOVI ELEMENTO IN TESTA
template<typename T>
void stack<T>::pop(){
	if(empty()){
		throw"Lo stack è vuoto";
	}
	else{
	sNode<T> *node=top;
	top=top->prev;
	delete node;
	length--;
	}
}

//RESTITUISCE IL VALORE IN TESTA
template<typename T>
T stack<T>::get_top() const{
	return top->value;
}

//GET SIZE
template<typename T>
size_t stack<T>::get_size() const{
	return length;
}

//CHECK 
template<typename T>
bool stack<T>::empty() const{
	return top==nullptr;
}

//CLEAR
template<typename T>
void stack<T>::clear(){
	while(!empty()){
		pop();
	}
}

template <class K>
std :: ostream& operator<<(std::ostream& os, const stack<K>&p){
  os<<"[";
  if(!p.empty()){
    sNode<K>* tmp=p.top;

    while(tmp->prev!=nullptr) {
      os<<tmp->value<<"|";
      tmp=tmp->prev;
    }
    os<<tmp->value;
  }
  
  os<<"]";

  return os;
}

//OVERLOAD1
template<class T>
stack<T>& stack<T>::operator=(const stack<T> &s){
	if(this==& s){
		return *this;
	}
	else if(s.empty()){
		clear();
	}
	else{
		sNode<T> *tmp1 = s.top;
		top = new sNode<T>;
		top->value=tmp1->value;
		top->prev=nullptr;
		tmp1=tmp1->prev;
		sNode<T> *tmp2=top;
	
		while(tmp1!=nullptr){
			this->value=tmp1->value;
			this->prev=nullptr;
			this->prev=this;
			tmp1=tmp1->prev;
			tmp2=tmp2->prev;
		}
	}
}

//OVERLOAD2
template<class T>
bool stack<T>::operator==(const stack<T> &s){

	if(get_size()!=s.get_size()){
		return false;
	}
	sNode<T> *temp1=s.top;
	sNode<T> *temp2=top;
	while(temp1!=nullptr){
		if(temp1->value!=temp2->value){
			return false;
		}
		temp1=temp1->prev;
		temp2=temp2->prev;
	}
	return true;
}
