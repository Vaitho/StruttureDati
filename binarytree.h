template<class T>
class btNode{
    btNode *son;
    btNode *left;
    btNode *right;
    T value;
};

template<class T>
class binarytree{
    public:
        binarytree();
        binarytree(const binarytree&ht);
        ~binarytree();

        void insert(T v);
        void remove(T v);

    private:
        btNode<T> *root;
        t_size size;0
};