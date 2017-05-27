#include"Queue.h"
template <class Type> void Queue<Type>::destroy()
{
    while(!empty())
        pop();
}

template <class Type> void Queue<Type>::pop()
{
    QueueItem<Type> *p=head;
    head=head->next;
    delete p;
}

template <class Type> void Queue<Type>::push(const Type& val)
{
    QueueItem<Type> *pt=new QueueItem<Type>(val);
    if(empty())
        head=tail=pt;
    else
    {
        tail->next=pt;
        tail=pt;
    }
}

template <class Type> void Queue<Type>::copy_elems(const Queue &orig)
{
    for(QueueItem<Type> *pt=orig.head;pt;pt=pt->next)
        push(pt->item);
}

template <class Type> Queue<Type>& Queue<Type>::operator=(const Queue& orig)
{
    destroy();
    head=tail=0;
    copy_elems(orig);
    return *this;
}

template <class T> template <class Iter> void Queue<T>::assign(Iter beg,Iter end)
{
    destroy();
    copy_elems(beg,end);
}

template <class Type> template <class It> void Queue<Type>::copy_elems(It beg,It end)
{
    while(beg!=end)
    {
        push(*beg);
        ++beg;
    }
}
