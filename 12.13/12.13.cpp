#include<string>
#include<iostream>
#include"Screen.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;


main()
{
    string s("sdfgagfghhfhfgdhdfhtdfg");
    Screen tt(10,3,s);
    tt.move(4,0).set('#').display(cout);
    return 0;
}
