#include<string>
#include"Person.h"

using std::string;

string Person::get_name() const
{
    return name;
}

string Person::get_address() const
{
    return address;
}
