#include <iostream>

template<class T, class P>
class list{
public:
	virtual T read(P p) const = 0;
	virtual P next(P p) const = 0;
	virtual P previous(P p) const = 0;
	virtual void clear() = 0;
	virtual bool empty() const = 0;
	virtual size_t size() const = 0;
	virtual P begin() const = 0;
	virtual P asdbegin() const = 0;
	virtual bool end(P p) const = 0;
	virtual void pushback(T v) = 0;
	virtual void pushfront(T v) = 0;
	virtual void rewrite(P p, T v)=0;
	virtual void insert(P p, T v)=0;
	virtual void remove(P p)=0;
	virtual P find(T v) const = 0;
	
	virtual void sort();	
	virtual void reverse();

};

template<class T, class P>
std::ostream &operator<<(std::ostream &os, const list<T, P> &l){
    P p = l.begin();
    os << "[ ";
    while(!l.end(p)){
        os << l.read(p) << " ";
        p = l.next(p);
    }
    os << "]";
    return os;
}

//ORDINAMENTO CRESCENTE
template<class T, class P>
void list<T,P>::sort(){
	if(!empty()){
		P cur = begin();
		while(!end(cur)){
			P q = cur;
			P pmin = cur;
			T min = read(cur);
			while(!end(q)){
				if(read(q) < min){
					min = read(q);
					pmin = q;
				}
				q = next(q);
			}
			T tmp = read(cur);
			rewrite(cur, min);
			rewrite(pmin, tmp);
			cur = next(cur);
		}
	}
}

//REVERSE
template<class T, class P>
void list<T, P>::reverse(){
	if(empty())
		return;
	T tmp;
	P cur1 = begin();
	P cur2 = begin();
	
	while(!end(next(cur2)))
		cur2 = next(cur2);

	while(cur1!=cur2 && previous(cur1)!=cur2)
	{
		tmp = read(cur1);
		rewrite(cur1, read(cur2));
		rewrite(cur2, tmp);
		cur1 = next(cur1);
		cur2 = previous(cur2);
	}
}
