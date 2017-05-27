#include"Query.h"

void TextQuery::store_file(std::ifstream &is)
{
    std::string line;
    while(getline(is,line))
        lines_of_text.push_back(line);
}

void TextQuery::build_map()
{
    for(line_no i=0;i!=lines_of_text.size();++i)
    {
        std::istringstream ss(lines_of_text[i]);
        std::string word;
        while(ss>>word)
            word_map[word].insert(i);
    }
}

std::set<TextQuery::line_no> TextQuery::run_query(const std::string &query_word) const
{
    std::map<std::string,std::set<line_no> >::const_iterator loc=word_map.find(query_word);
    if(loc==word_map.end())
        return std::set<line_no>();
    else
        return loc->second;
}

std::string TextQuery::text_line(line_no n) const
{
    if(n>=lines_of_text.size())
        throw std::out_of_range("out of range");
    else
        return lines_of_text[n-1];
}
