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

#include "filter_target.h"

filter_target::filter_target(string fname)
{
    this->fname = fname;
    read_src_file(fname);
}

void filter_target::read_src_file(string fname)
{
    fcontents.clear();

    ifstream sfile(fname.c_str());
    stringstream ss;

    ss << sfile.rdbuf();

    fcontents = ss.str();
    //cout << "fcontents.size():" << fcontents.size() << endl;
    if( fcontents.size() == 0 )
        cerr << "read src file failed!\n";
}

void filter_target::print_src_file()
{
    cout << fcontents;
}

int filter_target::replace( string tok, string val )
{
    tok = '@' + tok + '@';
    int repl_count = 0;
    size_t found;
    do {
        found = fcontents.find( tok );
        if( found != string::npos ){
            repl_count++;
            //cout << "FOUND at:" << found << endl;
            fcontents.replace(found, tok.size(), val );
        }
    } while( found != string::npos );

    return repl_count;
}

void filter_target::overwrite()
{
    ofstream ofile(fname.c_str(),ios::trunc);
    ofile << fcontents;
    ofile.close();
}
