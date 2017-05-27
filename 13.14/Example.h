#ifndef EXAMPLE_H_INCLUDED
#define EXAMPLE_H_INCLUDED
#include<iostream>


struct Exmp1
{
    Exmp1() {std::cout<<"Exmp1()"<<std::endl;}
    Exmp1(const Exmp1&) {std::cout<<"Exmp1(const Exmp1&)"<<std::endl;}
    Exmp1& operator=(const Exmp1&) {std::cout<<"operator=(const Exmp1&)"<<std::endl;return *this;}
    ~Exmp1() {std::cout<<"~Exmp1()"<<std::endl;}
};


#endif // EXAMPLE_H_INCLUDED
