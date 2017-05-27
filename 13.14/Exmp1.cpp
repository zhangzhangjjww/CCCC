#include<iostream>
#include"Example.h"
#include<vector>

void fun1(Exmp1 &e) {}
void fun2(Exmp1 e) {}
Exmp1 fun3() {Exmp1 o;return o;}
int main()
{
    Exmp1 ex1;
    Exmp1 ex2(ex1);
    Exmp1 ex3=ex1;
    ex3=ex2;
    //fun1(ex1);
    std::cout<<std::endl;
    fun2(ex1);
    std::cout<<std::endl;
    ex2=fun3();
    std::cout<<std::endl;
    //std::vector<Exmp1> v(3);
    std::cout<<std::endl;
    Exmp1 *p=new Exmp1;
    std::cout<<std::endl;
    delete p;
    std::cout<<std::endl;
    return 0;
}
