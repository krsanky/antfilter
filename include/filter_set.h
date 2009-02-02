/*
 * Copyright (c) 2008, 2009 Paul Wisehart <paul@1ud2.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

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
