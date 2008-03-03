#ifndef __FILTER_TARGET_H__
#define __FILTER_TARGET_H__

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/*
  Class: filter_target
  A class that represents a source file is the the target of a filter.
  This source file gets modified according to the filter rules of some
  filter instance.
*/
class filter_target
{
private:
    string fcontents;
    string fname;

public:
    filter_target(string fname);
    void read_src_file(string fname);
    void print_src_file();
    int replace( string tok, string val );
    void overwrite();
};

#endif
