#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include<iostream>
template <class Type> class Queue;
template <class Type> std::ostream& operator<<(std::ostream& os,const Queue<Type> &q);
template <class Type> std::istream& operator>>(std::istream& is,Queue<Type> &q);

template <class Type> class QueueItem
{
    friend class Queue<Type>;
    friend std::ostream& operator<< <Type>(std::ostream&,const Queue<Type>&);
    //friend std::istream& operator>> <Type>(std::istream& is,Queue<Type> &q);
    QueueItem(const Type &t):item(t),next(0) {}
    Type item;
    QueueItem *next;
};

template <class Type> class Queue
{
public:
    friend std::ostream& operator<< <Type>(std::ostream&,const Queue<Type>&);
    friend std::istream& operator>> <Type>(std::istream& is,Queue<Type> &q);
    Queue():head(0),tail(0) {}
    Queue(const Queue& Q):head(0),tail(0) {copy_elecms(Q);}
    Queue& operator=(const Queue&);
    ~Queue() { destroy(); }
    Type& front() {return head->item;}
    const Type& front() const {return head->item;}
    void push(const Type&);
    void pop();
    bool empty() const {return head==0;}
    template <class It> Queue(It beg,It end):head(0),tail(0) {copy_elems(beg,end);}
    template <class Iter> void assign(Iter,Iter);
private:
    QueueItem<Type> *head;
    QueueItem<Type> *tail;
    void destroy();
    void copy_elems(const Queue&);
    template <class Iter> void copy_elems(Iter,Iter);
};

template <class Type> std::ostream& operator<<(std::ostream& os,const Queue<Type> &q)
{
    os<<"< ";
    QueueItem<Type> *p;
    for(p=q.head;p;p=p->next)
        os<<p->item<<" ";
    os<<">";
    return os;
}

template <class Type> std::istream& operator>>(std::istream& is,Queue<Type> &q)
{
    Type tp;
    is>>tp;
    q.push(tp);
    return is;
}
//#include"Queue.cpp"

#endif // QUEUE_H_INCLUDED
