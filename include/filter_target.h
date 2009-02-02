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
