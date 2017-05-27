#ifndef ITEM_BASE_H_INCLUDED
#define ITEM_BASE_H_INCLUDED
#include<string>
#include<iostream>
#include<cctype>
#include<utility>
#include<vector>
#include<stdexcept>
#include<set>
#include<algorithm>
class Item_base
{
public:
    Item_base(const std::string &book="",double sales_price=0.0,std::string st="on"):isbn(book),price(sales_price),state(st) {}
    Item_base(const Item_base &i):isbn(i.isbn),price(i.price),state(i.state) {}
    virtual Item_base* clone() const {return new Item_base(*this);}
    virtual void debug(std::string s="on")
    {
        if(s=="on")
        std::cout<<"Item_base:"<<'\t'<<"isbn:"<<isbn<<'\t'<<"price:"<<price<<std::endl;
    }
    virtual void debug()
    {
        if(state=="on")
            std::cout<<"Item_base:"<<'\t'<<"isbn:"<<isbn<<'\t'<<"price:"<<price<<std::endl;
    }
    std::string book() const {return isbn;}
    virtual double net_price(std::size_t n) const
    {
        return n*price;
    }
    virtual ~Item_base() {}
private:
    std::string isbn;
protected:
    double price;
    std::string state;
};

class Disc_item:public Item_base
{
public:
    Disc_item(const std::string &book="",double sale_price=0.0,double dc=0.0,std::size_t q=0,std::string s="on"):
        Item_base(book,sale_price,s),discount(dc),quantity(q) {}
    Disc_item(const Disc_item& d):Item_base(d),discount(d.discount),quantity(d.quantity) {}
    virtual std::pair<std::size_t,double> discount_policy() const=0;
    virtual ~Disc_item() {}
protected:
    double discount;
    std::size_t quantity;
};
class Bulk_item:public Disc_item
{
public:
    Bulk_item(const std::string &book="",double sales_prices=0.0,std::string s="on",double dc=0.0,std::size_t minq=0):
        Disc_item(book,sales_prices,dc,minq,s) {}
    Bulk_item(const Bulk_item &b):Disc_item(b) {}
    Bulk_item* clone() const {return new Bulk_item(*this);}
    void debug(std::string s="on")
    {
        if(s=="on")
            std::cout<<"Bilk_item:"<<'\t'<<"isbn:"<<book()<<'\t'<<"price:"<<price<<'\t'<<
            "min_quantity:"<<quantity<<'\t'<<"dicount:"<<discount<<std::endl;
    }
    void debug()
    {
        if(state=="on")
            std::cout<<"Bilk_item:"<<'\t'<<"isbn:"<<book()<<'\t'<<"price:"<<price<<'\t'<<
            "min_quantity:"<<quantity<<'\t'<<"dicount:"<<discount<<std::endl;
    }
    std::pair<std::size_t,double> discount_policy() const
    {
        return std::make_pair(quantity,discount);
    }
    double net_price(std::size_t n) const
    {
        if(n>=quantity)
            return n*price*(1-discount);
        else
            return n*price;
    }
    ~Bulk_item() {}
};

class Up_discount:public Disc_item
{
public:
    Up_discount(const std::string &book="",double sale_price=0.0,std::string s="on",double dc=0.0,std::size_t maxq=0):
        Disc_item(book,sale_price,dc,maxq,s) {}
    Up_discount(const Up_discount &u):Disc_item(u) {}
    Up_discount* clone() const {return new Up_discount(*this);}
    void debug(std::string s="on")
    {
        if(s=="on")
            std::cout<<"Bilk_item:"<<'\t'<<"isbn:"<<book()<<'\t'<<"price:"<<price<<'\t'<<
            "max_quantity:"<<quantity<<'\t'<<"dicount:"<<discount<<std::endl;
    }
    void debug()
    {
        if(state=="on")
            std::cout<<"Bilk_item:"<<'\t'<<"isbn:"<<book()<<'\t'<<"price:"<<price<<'\t'<<
            "max_quantity:"<<quantity<<'\t'<<"dicount:"<<discount<<std::endl;
    }
    std::pair<std::size_t,double> discount_policy() const
    {
        return std::make_pair(quantity,discount);
    }
    double net_price(std::size_t n) const
    {
        if(n<=quantity)
            return n*price*(1-discount);
        else
            return quantity*price*(1-discount)+price*(n-quantity);
    }
};

class Sales_item
{
public:
    Sales_item():p(0),use(new std::size_t(1)) {}
    Sales_item(const Sales_item &s):p(s.p),use(s.use) {++*use;};
    Sales_item(const Item_base& i):p(i.clone()),use(new std::size_t(1)) {};
    ~Sales_item() {decr_use();}
    Sales_item& operator=(const Sales_item&);
    const Item_base* operator->() const
    {if(p) return p;
    else throw std::logic_error("unbound Sales_item");}
    const Item_base& operator*() const
    {
        if(p)
            return *p;
        else
            throw std::logic_error("unbound Sales_item");
    }

private:
    Item_base *p;
    std::size_t *use;
    void decr_use()
    {
        if(--*use==0)
        {
            delete use;
            delete p;
        }
    }
};

Sales_item& Sales_item::operator=(const Sales_item &s)
{
    ++(*s.use);
    decr_use();
    use=s.use;
    p=s.p;
    return *this;
}
inline bool compare(const Sales_item &lhs,const Sales_item &rhs)
    {
        return lhs->book()<rhs->book();
    }
class Basket
{
    typedef bool (*Comp)(const Sales_item&,const Sales_item&);
public:

    typedef std::multiset<Sales_item,Comp> set_type;
    typedef set_type::size_type size_type;
    typedef set_type::const_iterator const_iter;
    Basket():items(compare) {}
    void add_item(const Sales_item &item)
    {
        items.insert(item);
    }
    size_type size(const Sales_item &i) const
    {
        return items.count(i);
    }
    double total() const;
private:
    std::multiset<Sales_item,Comp> items;
};

double Basket::total() const
{
    double sum=0.0;
    for(const_iter iter=items.begin();iter!=items.end();iter=items.upper_bound(*iter))
    {
        sum+=(*iter)->net_price(items.count(*iter));
    }
    return sum;
}
#endif // ITEM_BASE_H_INCLUDED
