
template <class T>  typename T::value_type middle(T t)
{
    for(int i=1;i!=t.size();++i)
    {
        int j=i-1;
        typename T::value_type key=t[i];
        while(j>-1&&t[j]>key)
        {
            t[j+1]=t[j];
            --j;
        }
        t[j+1]=key;
    }
    typename T::size_type middle=t.size()/2;
    return t[middle];
}

//F:\ÕÅ½¨Íþ\c++\16.27\middle.cpp|11|error: assignment of read-only location 't.std::vector<_Tp, _Alloc>::operator[]<int, std::allocator<int> >(((std::vector<int>::size_type)(((long unsigned int)j) + 1ul)))'|
