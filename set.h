template<class T>
class set;

template<class T>
class setNode{
	friend class set<T>;
	
	template <class K>
  	friend std :: ostream& operator<<(std::ostream&os, const set<K>&);
private:
	T value;
	setNode<T> * next;
	setNode<T> * prev;
};

template<class T>
class set{
	public:
		set();//COSTRUTTORE
		set(const set<T>&);	//COSTRUTTORE DI COPIA
		~set();	//DISTRUTTORE
		
		set<T>& operator=(const set<T> &);
		bool operator==(const set<T> &);
		
		void clear();//CLEAR
		bool empty()const;//SET VUOTO
		bool isIn(T t)const;//CONTROLLO VALORI UGUALI
		void insert(T t);//INSERIMENTO
		void remove(setNode<T> *t);//RIMOZION
		setNode<T> *find(T t) const;//RICERCA
		size_t getsize() const;//size
		
		void merge(set<T> &v);//UNIONE
		void difference(set<T> &v);//DIFFERENZA
		void intersect(set<T> &v);//INTERSEZIONE
		
		
		template <class K>
	 	friend std :: ostream& operator<<(std::ostream& os, const set<K>&);
	
	private:
		setNode<T> * head;
		int length=0;
};

//COSTRUTTORE
template <typename T>
set<T>::set(){
	head=nullptr;
}
//COSTRUTTORE COPIA
template <typename T>
set<T>::set(const set<T>&s){
	head=nullptr;
	
	setNode<T> *node = new setNode<T>;
	node=s.head;
	while(node!=nullptr){
		insert(node->value);
		node=node->next;	
	}
}
//DISTRUTTORE
template <class T>
set<T>::~set(){
	clear();
}

//SIZE
template<typename T>
size_t set<T>::getsize() const {
	return length;
}

//CLEAR
template<typename T>
void set<T>::clear(){
	setNode<T> *temp;
	while(head!=nullptr){
		temp=head;
		head=head->next;
		delete temp;
	}
}
//EMPTY
template<typename T>
bool set<T>::empty()const{
	return head==nullptr;
}

//INSERIMENTO
template<class T>
void set<T>::insert(T t){
	if(!isIn(t)){
		setNode<T> *node=new setNode<T>;
		node->value=t;
		node->next=node->prev=nullptr;
		if(!empty()){
			node->next=head;
			head->prev=node;
		}
		head=node;
		length++;
	}
}

//ISIN
template<typename T>
bool set<T>::isIn(T t) const{
	setNode<T> *temp;
	temp=head;
	bool found=false;
	while(temp!=nullptr and !found){
		
		if(temp->value==t){
			found=true;
		}
		else{
			temp=temp->next;
		}
	}
	return found;	
}

//FIND 
template<typename T>
setNode<T> *set<T>::find(T t) const{
	setNode<T> *temp;
	temp=head;
	bool found=false;
	while(temp!=nullptr and !found){
		
		if(temp->value==t){
			found=true;
		}
		else{
			temp=temp->next;
		}
	}
	return temp;	
}

//RIMUOVI
template<typename T>
void set<T>::remove(setNode<T> *t){
	if(empty()){
		throw"Il set è vuoto";
	}
	if(t->prev==nullptr){
		head=t->next;
	}else if(t->next==nullptr){
		t->prev->next=nullptr;
	}
	else{
		t->next->prev=t->prev;
		t->prev->next=t->next;
	}
	delete t;
	length--;
}

//STAMPA
template <class K>
std :: ostream& operator<<(std::ostream& os, const set<K>&p){
  os<<"[";
  if(!p.empty()){
    setNode<K>* tmp=p.head;

    while(tmp!=nullptr) {
      os<<tmp->value<<"|";
      tmp=tmp->next;
    } 
  }
  os<<"]";
  return os;
}
//UNION
template<class T>
void set<T>::merge(set<T> &v){
	setNode<T> *node= new setNode<T>;
	node=v.head;
	while(node != nullptr){
		T value=node->value;
		if(!find(value)){
			insert(value);
		}
		node=node->next;
	}
}
//INTERSECT
template<class T>
void set<T>::intersect(set<T> &v){
	setNode<T> *node= new setNode<T>;
	node=head;
	while(node!=nullptr){
		T value=node->value;
		if(!v.find(value)){
			node=node->next;
			remove(find(value));
		}else{
			node=node->next;
		}
	}
}
//DIFFERENCE
template<class T>
void set<T>::difference(set<T> &v){
	setNode<T> *node= new setNode<T>;
	node=head;
	while(node!=nullptr){
		T value=node->value;
		if(v.find(value)){
			node=node->next;
			remove(find(value));
		}else{
			node=node->next;
		}
	}
}
//OPERATORE=
template<class T>
set<T>& set<T>::operator=(const set<T> &s){
	clear();
	setNode<T> *node= new setNode<T>;
	node=s.head;
	while(node!=nullptr){
		T value=node->value;
		insert(value);
		node=node->next;
	}
}
//OPERATORE==
template<class T>
bool set<T>::operator==(const set<T> &s){
	setNode<T> *node= new setNode<T>;
	node=head;
	while(node!=nullptr){
		T value=node->value;
		if(!s.find(value)){
			return false;
		}else{
			node=node->next;
		}
	}
	return true;
}
