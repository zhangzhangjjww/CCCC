#include"Query_base.h"
#include<iterator>
inline Query operator&(const Query &lhs,const Query &rhs)
{
    return new AndQuery(lhs,rhs);
}
inline Query operator|(const Query &lhs,const Query &rhs)
{
    return new OrQuery(lhs,rhs);
}
inline Query operator~(const Query &oper)
{
    return new NotQuery(oper);
}

std::set<TextQuery::line_no>
OrQuery::eval(const TextQuery& file) const
{
    std::set<line_no> right=rhs.eval(file),ret_lines=lhs.eval(file);
    ret_lines.insert(right.begin(),right.end());
    return ret_lines;
}

std::set<TextQuery::line_no>
AndQuery::eval(const TextQuery& file)const
{
    std::set<line_no> left=lhs.eval(file),right=rhs.eval(file);
    std::set<line_no> ret_lines;
    set_intersection(left.begin(),left.end(),right.begin(),right.end(),inserter(ret_lines,ret_lines.begin()));
    return ret_lines;
}

std::set<TextQuery::line_no>
NotQuery::eval(const TextQuery &file) const
{
    std::set<TextQuery::line_no> has_val=query.eval(file);
    std::set<line_no> ret_lines;
    for(TextQuery::line_no n=0;n!=file.size();++n)
        if(has_val.find(n)==has_val.end())
        ret_lines.insert(n);
    return ret_lines;
}
