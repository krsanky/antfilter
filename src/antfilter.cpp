#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#include "filter_set.h"
#include "filter_target.h"

//MAIN
int main(int argc, char ** argv )
{
    if( argc != 3){
        cout << argv[0] << " <filter-file> <file-to-filter>\n";
        exit(1);
    }
    string ff_name = argv[1];
    string sf_name = argv[2];

    filter_set * filt = new filter_set(ff_name);
    filt->read_filter_file();
    //filt->print_filter_file();
    filt->parse_filter_file();
    //filt->print_filters();

    filter_target * filt_targ = new filter_target(sf_name);

    map<string,string>::iterator iter;
    map<string,string> filters = filt->get_map();
    for( iter = filters.begin(); iter != filters.end(); iter++ ){
        filt_targ->replace( iter->first, iter->second );
    }

    //filt_targ->print_src_file();

    filt_targ->overwrite();

    delete filt;
    delete filt_targ;
    exit(1);
}


