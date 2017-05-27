#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED
#include<iostream>
#include<set>
#include<string>
#include<algorithm>

class Folder;

class Message
{
private:
    std::string content;
    std::set<Folder*> folders;
    void put_message_into_folders(const std::set<Folder*> &);
    void remove_message_from_folders();
    void addFloder(Folder* f) {folders.insert(f);}
    void remFolder(Folder* f) {folders.erase(f);}
public:
    Message(std::string s=""):content(s) {}
    Message(const Message & m);
    Message& operator=(const Message & m);
    ~Message();
    void save(Folder*);
    void remove(Folder*);
};

class Folder
{
private:
    std::set<Message*> Messages;
public:
    Folder() {}
    void addMessage(Message*);
    void remMessage(Message*);
};



#endif // MESSAGE_H_INCLUDED
