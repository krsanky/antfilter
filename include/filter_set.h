#ifndef __FILTER_SET_H__
#define __FILTER_SET_H__

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <map>
using namespace std;

/*
  Class: filter
  A class that reads in a text file of filter substitution pairs.
*/
class filter_set
{
private:
    string ff_name;
    list<string> filter_file;
    map<string,string> filters;
    void trim_ws(string & str);
public:
    filter_set(string ff_name);
    void read_filter_file();
    void print_filter_file();
    void parse_filter_file();
    void print_filters();
    map<string,string> get_map();
};

#endif
