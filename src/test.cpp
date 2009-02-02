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

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char ** argv )
{
    if( argc != 2){
        cout << argv[0] << " <file>\n";
        exit(1);
    }
    string fname = argv[1];

    ifstream filter_file(fname.c_str());

    string str = "";
    char c;
    if( filter_file.is_open() ){
        while( filter_file.get(c) ){
            str = str + c;
        }
        filter_file.close();
    } else {
        cerr << "Can't open input file: " << fname << endl;
    }

    cout << str;

    exit(1);
}
