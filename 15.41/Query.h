#ifndef QUERY_H_INCLUDED
#define QUERY_H_INCLUDED
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<fstream>
#include<stdexcept>

class  TextQuery
{
public:
    typedef std::vector<std::string>::size_type line_no;
private:
    std::vector<std::string> lines_of_text;
    std::map<std::string,std::set<line_no> > word_map;
    void store_file(std::ifstream&);
    void build_map();
public:
    void read_file(std::ifstream &is)
    {
        store_file(is);build_map();
    }
    std::set<line_no> run_query(const std::string&) const;
    std::string text_line(line_no) const;
    line_no size() const
    {
        return lines_of_text.size();
    }
};


#endif // QUERY_H_INCLUDED
