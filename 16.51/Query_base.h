#ifndef QUERY_BASE_H_INCLUDED
#define QUERY_BASE_H_INCLUDED
#include"Query.h"
#include<cctype>
#include"Handle.h"
#include"Handle.cpp"
class Query_base
{
    friend class Query;
    friend class Handle<Query_base>;
protected:
    typedef TextQuery::line_no line_no;
    virtual ~Query_base() {}
private:
    virtual std::set<line_no> eval(const TextQuery&) const=0;
    virtual std::ostream& display(std::ostream& = std::cout) const=0;
};



class Query
{
    friend Query operator~(const Query&);
    friend Query operator|(const Query&,const Query&);
    friend Query operator&(const Query&,const Query&);
    friend std::ostream&operator<<(std::ostream os,const Query &q)
    {
        return q.display(os);
    }
public:
    Query(const std::string&);
    std::set<TextQuery::line_no> eval(const TextQuery &t) const {return h->eval(t);}
    std::ostream &display(std::ostream &os) const
    {
        return h->display(os);
    }
private:
    Query(Query_base *query):h() {}
    Handle<Query_base> h;
};



class WordQuery:public Query_base
{
    friend class Query;
    WordQuery(const std::string &s):query_word(s) {}
    std::set<line_no> eval(const TextQuery &t) const
    {
        return t.run_query(query_word);
    }
    std::ostream& display(std::ostream &os) const
    {
        return os<<query_word;
    }
    std::string query_word;
};

class NotQuery:public Query_base
{
    friend Query operator~(const Query &);
    NotQuery(Query q):query(q) {}
    std::set<line_no> eval(const TextQuery &) const;
    std::ostream& display(std::ostream &os) const
    {
        std::string s1("~("),s2(")");
        return os<<s1;
    }
    const Query query;
};

class BinaryQuery:public Query_base
{
protected:
    BinaryQuery(Query left,Query right,std::string op):lhs(left),rhs(right),oper(op) {}
    std::ostream& display(std::ostream &os) const
    {
        return os<<"("<<" "<<oper<<" "<<")";
    }
    const Query lhs,rhs;
    const std::string oper;
};

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query&,const Query&);
    AndQuery(Query left,Query right):BinaryQuery(left,right,"&") {}
    std::set<line_no> eval(const TextQuery&) const;
};

class OrQuery:public BinaryQuery
{
    friend Query operator|(const Query&,const Query&);
    OrQuery(Query left,Query right):BinaryQuery(left,right,"|") {}
    std::set<line_no> eval(const TextQuery&) const;
};
#endif // QUERY_BASE_H_INCLUDED
