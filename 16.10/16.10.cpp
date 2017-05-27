#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<algorithm>
#include<iterator>
using namespace std;
struct Review
{
    string title;
    int rating;
    double price;
};

bool operator<(const shared_ptr<Review> & r1,const shared_ptr<Review> & r2);
bool ra(const shared_ptr<Review> & r1,const shared_ptr<Review> & r2);
bool pr(const shared_ptr<Review> & r1,const shared_ptr<Review> & r2);
void showreview(const shared_ptr<Review> & rr);
bool fillreview(Review & rr);

int main()
{
    vector<shared_ptr<Review> > books;
    Review temp;
    while(fillreview(temp))
    {
        shared_ptr<Review> pd=new Review(temp);
        books.push_back(pd);
    }
    if(books.size()>0)
    {
        cout<<"Thank you,You enter the following "<<books.size()<<" books.\n";

    }
    else
    {cout<<"No entries.";return 0;}
    char ch;
    cout<<"Please enter the mode to output:\n";
    cout<<"o,t,r,p,q(to quit):";
    while(cin>>ch&&ch!='q')
    {
        cout<<"Rating\tPrice\tBook\n";
        switch(ch)
        {
            case'o':for_each(books.begin(),books.end(),showreview);
                    break;
            case't':sort(books.begin(),books.end());
                    cout<<"please choose upper or lower:<u/l>";
                    char ch1;cin>>ch1;
                    if(ch1=='u')
                    for_each(books.begin(),books.end(),showreview);
                    else
                        for_each(books.rbegin(),books.rend(),showreview);
                    break;
            case'r':sort(books.begin(),books.end(),ra);
                    cout<<"please choose upper or lower<u/l>";
                    char ch2;cin>>ch2;
                    if(ch2=='u')
                        for_each(books.begin(),books.end(),showreview);
                    else
                        for_each(books.rbegin(),books.rend(),showreview);
                    break;
            case'p':sort(books.begin(),books.end(),pr);
                    cout<<"please choose upper or lower<u/l>";
                    char ch3;cin>>ch3;
                    if(ch3=='u')
                        for_each(books.begin(),books.end(),showreview);
                    else
                        for_each(books.rbegin(),books.rend(),showreview);
                    break;

        }
        cout<<"Please enter a char(o,t,r,p,q(q to quit):";

        }
        cout<<"bye!\n";
        return 0;

    }

    bool operator<(const shared_ptr<Review> & r1,const shared_ptr<Review> & r2)
    {
        if(r1->title<r2->title)
            return true;
        else
            return false;
    }
    bool ra(const shared_ptr<Review> & r1,const shared_ptr<Review> & r2)
    {
        if(r1->rating<r2->rating)
            return true;
        else
            return false;
    }
    bool pr(const shared_ptr<Review> & r1,const shared_ptr<Review> & r2)
    {
        if(r1->price<r2->price)
            return true;
        else
            return false;

    }
    bool fillreview(Review & rr)
    {
        cout<<"Enter book title(quit to quit):";
        getline(cin,rr.title);
        if(rr.title=="quit")
            return false;
        cout<<"Enter the bok rating:";
        cin>>rr.rating;
        if(!cin)
            return false;
        cout<<"Enter the book price:";
        cin>>rr.price;
        if(!cin)
            return false;
        while(cin.get()!='\n')
            continue;
        return true;
    }
    void showreview(const shared_ptr<Review> & rr)
    {
        cout<<rr->rating<<'\t'<<rr->price<<'\t'<<rr->title<<endl;
    }
