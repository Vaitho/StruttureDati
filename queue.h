#include <iostream>

template<class T>
class queue;

template<class T>
class qNode{
	friend class queue<T>;
	
	template <class K>
  	friend std :: ostream& operator<<(std::ostream&os, const queue<K>&);
	
	private:
		T value;
		qNode<T> *next;
};


template<class T>
class queue{
	public:
		queue();
		queue(const queue &q);
		~queue();
	
		void clear();
		bool empty() const;
		size_t get_size() const;
		void push(T v);
		void pop();
		T get_top() const;
		
		bool operator==(const queue<T> &);
		queue &operator=(const queue<T> &);
		
		template <class K>
  		friend std :: ostream& operator<<(std::ostream&os, const queue<K>&);
	
	private:
		qNode<T> *head;
		qNode<T> *tail;
		size_t length=0;
};

//COSTRUTTORE
template<typename T>
queue<T>::queue(){
	head=tail=nullptr;
	length= 0;
}
//COSTRUTTORE COPIA
template<typename T>
queue<T>::queue(const queue &q){
	head=tail=nullptr;
	length= 0;

	qNode<T> *tmp = q.head;

	while(tmp!=nullptr){
		push(tmp->value);
		tmp=tmp->next;
	}
}

//DISTRUTTORE
template<typename T>
queue<T>::~queue(){
	clear();
}
//PULISCI QUEUE
template<typename T>
void queue<T>::clear(){
	while(!empty())
		pop();
}
//EMPTY
template<typename T>
bool queue<T>::empty() const{
	return head==nullptr;
}
//POP
template<typename T>
void queue<T>::pop(){
	qNode<T> *node = head;
	head = head->next;
	delete node;

	length--;
}
//PUSH
template<typename T>
void queue<T>::push(T v){
	qNode<T> *node = new qNode<T>;
	node->value = v;
	node->next = nullptr;

	if(empty()){
		head=tail=node;
	}
	else{
		tail->next=node;
		tail=node;
	}
	length++;
}

//SIZE
template<typename T>
size_t queue<T>::get_size() const{
	return length;
}

//GET TOP
template<typename T>
T queue<T>::get_top() const{
	if(empty())
		throw "queue is empty";

	return head->value;
}

//STAMPA
template <class K>
std :: ostream& operator<<(std::ostream& os, const queue<K>&p){
  os<<"[";
  if(!p.empty()){
    qNode<K>* tmp=p.head;

    while(tmp!=nullptr) {
      os<<tmp->value<<"|";
      tmp=tmp->next;
    } 
  }
  os<<"]";
  return os;
}

//UGUALE
template<typename T>
queue<T> &queue<T>::operator=(const queue<T> &q){
	if(this == &q){
		return *this;
	}
	if(!empty()){
		clear();
	}
	head=tail=nullptr;
	length=0;

	qNode<T> *tmp = q.head;

	while(tmp != nullptr){
		push(tmp->value);
		tmp = tmp->next;
	}
	return *this;
}

//UGUALE UGUALE 
template<class T>
bool queue<T>::operator==(const queue<T> &q){
	if(get_size()!=q.get_size()){
		return false;
	}
	qNode<T> *temp1=q.head;
	qNode<T> *temp2=head;
	while(temp1!=nullptr){
		if(temp1->value!=temp2->value){
			return false;
		}
		temp1=temp1->next;
		temp2=temp2->next;
	}
	return true;
}
