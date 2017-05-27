#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include<string>
class Person
{
private:
    std::string name;
    std::string address;
public:
    Person(const std::string& n,const std::string& a):name(n),address(a) {}
    std::string get_name() const;
    std::string get_address() const;
};


#endif // PERSON_H_INCLUDED
