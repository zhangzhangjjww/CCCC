#include"Message.h"

Message::Message(const Message & m):content(m.content),folders(m.folders)
{
    put_message_into_folders(folders);
}

Message& Message::operator=(const Message& m)
{
    if(&m!=this) {
    remove_message_from_folders();
    content=m.content;
    folders=m.folders;
    put_message_into_folders(folders);}
    return *this;
}

Message::~Message()
{
    remove_message_from_folders();
}

void Message::put_message_into_folders(const std::set<Folder*> & f)
{
    for(std::set<Folder*>::iterator i=f.begin();i!=f.end();++i)
        (*i)->addMessage(this);
}

void Message::remove_message_from_folders()
{
    for(std::set<Folder*>::iterator i=folders.begin();i!=folders.end();++i)
        (*i)->remMessage(this);
}

void Message::save(Folder* f)
{
    folders.insert(f);
    f->addMessage(this);
}
void Message::remove(Folder *f)
{
    folders.erase(f);
    f->remMessage(this);
}
void Folder::addMessage( Message* m)
{
    Messages.insert(m);
}
void Folder::remMessage(Message* m)
{
    Messages.erase(m);
}
