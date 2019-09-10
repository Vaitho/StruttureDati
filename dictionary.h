template<class T,class V>
class dictionary;

template<class K, class T>
class dNode{
public:
	K key;
	T value;
	dNode<K,T> *next;
	dNode<K,T> *prev;
	
	friend class dictionary<T,K>;
	
	template<class U, class V>
	friend std::ostream &operator<<(std::ostream &os,const dictionary<U,V> &d);
};

template<class K>
class hash{
	public:
		size_t operator()(K k) const{
			size_t t=0;
			for(int i=0;i<t;i++){
				t+=k[i];
			}
		}
};

template<class K, class T>
class dictionary{
	public:
		dictionary(size_t d);
		dictionary(const dictionary &ht);
		~dictionary();

		bool isempty()const;
		bool isKey(K k)const;

		void insert(K k, T v);
		void remove(K k);
	 	K getValue(K k)const;

	private:
		dNode<K, T> **table;
		hash<K> hash;
		size_t size;
		size_t divisor;
		
		template<class U, class V>
		friend std::ostream &operator<<(std::ostream &os, const dictionary<U, V> &ht);


		dNode<K, T> *search(K k, size_t h) const;	
};

template<typename K, typename T>
dictionary<K,T>::dictionary(size_t d){
	if(d == 0){
		throw"Error";
	}
	divisor=d;
	size=0;

	table = new dNode<K, T> *[divisor];
	
	for(size_t i=0; i<divisor; i++){
		table[i]=nullptr;
	}
}

template<typename K, typename T>
bool dictionary<K, T>::isempty() const{
	return size==0;
}

template<typename K,typename T>
void dictionary<K,T>::insert(K k,T v){
	size_t pos=hash(k)%divisor;
	dNode<K,T> *node=search(k,pos);
	if(node==nullptr){
		dNode<K,T> *temp=new dNode<K,T>;
		temp->key=k;
		temp->value=v;
		temp->prev=nullptr;
		temp->next=hash[pos];
		
		if(table[pos]!=nullptr){
			hash[pos]->prev=temp;
		}
		hash[pos]=temp;	
	}else{
		node->value=v;
	}
}

template<typename K,typename T>
void dictionary<K,T>::remove(K k){
	size_t pos=hash(k)%divisor;
	dNode<K,T> *node=search(k,pos);

	if(node==nullptr){
		throw"Chiave non trovata";
	}
	else{
		if(node->prev==nullptr){
			hash[pos]=node->next;
		}else{
			node->prev->next=node->next;
		}
		if(node->next!=nullptr){
			node->next->prev=node->prev;
		}
	}
	delete node;
	size --;
}
template<typename K,typename T>
bool dictionary<K,T>::isKey(K k)const{
	size_t pos=hash(k)%divisor;
	dNode<K,T> *node=search(k,pos);
	if(node==nullptr){
		return false;
	}else{
		return true;
	}
}

template<typename K,typename T>
K dictionary<K,T>::getValue(K k)const{
	size_t pos=hash(k)%divisor;
	dNode<K,T> *node=search(k,pos);
	if(node==nullptr){
		throw"Chiave non trovata";
	}
	else{
		return node->value;
	}
}

template<typename K,typename T>
dNode<K, T> *dictionary<K,T>::search(K k, size_t h) const{
	dNode<K, T> *dsearch =table[h];
	while(dsearch != nullptr){
		if(dsearch->key == k){
			return dsearch;
		}
		dsearch=dsearch->next;
	}
	return nullptr;
}

template<class K, class T>
std::ostream &operator<<(std::ostream &os, const dictionary<K, T> &d){
	for(size_t i = 0; i <d.divisor(); i++){
		os << i << ") [ ";
		dNode<K, T> *tmp = d.table[i];
		while(tmp != nullptr){
			os << "(" << tmp->key << " " << tmp->value << ") ";
			tmp = tmp->next;
		}
		os << "]" << std::endl;
	}
	return os;
}
