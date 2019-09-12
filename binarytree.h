template<class T>
class binarytree;

template<class T>
class btNode{
	friend class binarytree<T>;

	private:
	    btNode *parent;
	    btNode *left;
	    btNode *right;
	    T value;
};

template<class T>
class binarytree{
    public:
        binarytree();
       // binarytree(const binarytree&ht);
       // ~binarytree();

        btNode<T>* getRoot() const;//
        btNode<T>* getRight(btNode<T> *n)const;//
        btNode<T>* getLeft(btNode<T> *n)const;//
        btNode<T> getValue(btNode<T> *n)const;//
        btNode<T>* getParent(btNode<T>* n)const;//

		bool isEmpty()const;
        bool dxEmpty(btNode<T> *n)const;//
        bool sxEmpty(btNode<T> *n)const;//

        void insertRoot(T v);//
        void insertRight(btNode<T> *n,T v);//
        void insertLeft(btNode<T> *n,T v);//
        
        void remove(btNode<T> *n);
        
        void write(btNode<T> *n,T v);
		void clear();
        static void print(std::ostream &os, btNode<T> *n);

        template<class U>
        friend std::ostream &operator<<(std::ostream &os, const binarytree<T> &t);
    private:
        btNode<T> *root;
        int size;
};
template<class T>
binarytree<T>::binarytree(){
    root=nullptr,
    size=0;
}

template<class T>
btNode<T>* binarytree<T>::getRoot() const{
    return root;
}

template<class T>
btNode<T> *binarytree<T>::getRight(btNode<T> *n) const{
    return n->right;
}

template<class T>
btNode<T> *binarytree<T>::getLeft(btNode<T> *n) const{
    return n->left;
}

template<class T>
btNode<T> *binarytree<T>::getParent(btNode<T> *n) const{
    return n->parent;
}

template<class T>
btNode<T> binarytree<T>::getValue(btNode<T> *n) const{
    return n->value;
}

template<class T>
bool binarytree<T>::isEmpty()const{
    return root==nullptr;
}

template<class T>
bool binarytree<T>::dxEmpty(btNode<T> *n)const{
    return n->right==nullptr;
}

template<class T>
bool binarytree<T>::sxEmpty(btNode<T> *n)const{
    return n->left==nullptr;
}

template<class T>
void binarytree<T>::insertRoot(T v){
    btNode<T> *node=new btNode<T>;
    node->parent=nullptr;
    node->right=nullptr;
    node->left=nullptr;
    node->value=v;
    root=node;
    size++;
}

template<class T>
void binarytree<T>::insertRight(btNode<T> *n,T v){
    btNode<T> *node=new btNode<T>;
    node->parent=n;
    node->value=v;
    n->right=node;
    node->right=nullptr;
    node->left=nullptr;
    size++;
}

template<class T>
void binarytree<T>::insertLeft(btNode<T> *n,T v){
    btNode<T> *node=new btNode<T>;
    node->parent=n;
    node->right=nullptr;
    node->left=nullptr;
    n->left=node;
    node->value=v;
    size++;
}

template<class T>
void binarytree<T>::remove(btNode<T> *n){
	if(n->left!=nullptr){
        remove(n->left);
        n->left=nullptr;     
    }if(n->right!=nullptr){
        remove(n->right);
        n->right=nullptr;
    }
    if(n->left==nullptr and n->right==nullptr){
		if(n == root){
			root = nullptr;
		}
		if(n->parent->right=n){
			n->parent->right=nullptr;
		}
		if(n->parent->left=n){
			n->parent->left=nullptr;			
		}
	    delete(n);
		n=nullptr;
		size--;
	}
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const binarytree<T> &t){
	if(t.isEmpty()){
		os<<"[]";
	}
	else{
		binarytree<T>::print(os, t.getRoot());
	}
	return os;
}

template<typename T>
void binarytree<T>::print(std::ostream &os, btNode<T> *n)
{
	std::cout << "[ " << n->value << " ";

	if(n->left)
		print(os, n->left);
	else
		os << "NULL ";

	if(n->right)
		print(os, n->right);
	else
		os << "NULL ";

	std::cout << "] ";
}

template<class T>
void binarytree<T>::write(btNode<T> *n,T v){
	btNode<T> *node=new btNode<T>;
	node=n;
	node->value=v;
}

template<class T>
void binarytree<T>::clear(){
	remove(getRoot());
}
