#include <unistd.h>

#include <map>
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

#include "filter_set.h"
#include "filter_target.h"


void show_usage();
void run_filter(string ff_name, string sf_name);


//MAIN
int main(int argc, char ** argv)
{
    cout << "start...\n";

    // -- begin getop section

    // int getopt(int argc, char * const argv[],
    //            const char *optstring);

    //int o1 = getopt(argc, argv, "+a:");
    //cout << "o1:" << (char)o1 << endl;
    //cout << "o1 arg:" << argv[0] << endl;    

    int opt;
    while((opt = getopt(argc, argv, "+hDf:")) != -1) {
        cout << "opt:";    
        switch(opt) {
        case 'h':
            show_usage();
            exit(0);
        case 'D':
            cout << "DDDDDD\n";
            break;
        case 'f':
            cout << "t optarg:" << optarg;
            break;
        default: /* '?' */
            show_usage();
            exit(EXIT_FAILURE);
        }
        cout << endl;
    }

    cout << "optind:" << optind << endl;

    if(optind < argc){
        for(int i = optind; i < argc; i++){
            cout << "arg[" << i << "]:" << argv[i] << endl;
        }
    }

    // -- end getop section

    int ret = 1;
    string ff_name, sf_name, test, src_dir;
    bool debug = false;

    vector<int> v_int;
    vector<string> src_files, filter_files;
    
    // ops >> Option('s', "src_file", src_files); 
    // ops >> Option('f', "filter_file", filter_files); 
    // ops >> OptionPresent('D', "debug", debug);

    if(debug){
        cout << "debug:\n";
        
        cout << "SOURCES";
        for(vector<string>::const_iterator it = src_files.begin(); it != src_files.end(); ++it)
            cout << ":" << *it;
        cout << "\n\n";
        
        cout << "FILTERS";
        for(vector<string>::const_iterator it = filter_files.begin(); it != filter_files.end(); ++it)
            cout << ":" << *it;
        cout << "\n\n";
    }
    
    //foreach filter-file ... run_filter() on each src file. 
    for(vector<string>::const_iterator s_it = src_files.begin(); s_it != src_files.end(); ++s_it){
        for(vector<string>::const_iterator f_it = filter_files.begin(); f_it != filter_files.end(); ++f_it){
            run_filter(*f_it, *s_it);
        }
    }

    ret = 0;

    return(ret);
}

void show_usage()
{
    cout << "\nusage:\n";
    cout << "antfilter [-h][-f <filter-file>][-D] <files-to-filter>\n";
    cout << "-h   this message\n" ;
    cout << "-f   filter file (allow multiple)\n";
    cout << "-D   echo some debugging stuff\n";
    cout << "\n";
}

void run_filter(string ff_name, string sf_name)
{
   filter_set * filt = new filter_set(ff_name);
   filt->read_filter_file();
   filt->parse_filter_file();
   
   filter_target * filt_targ = new filter_target(sf_name);
   
   map<string,string>::iterator iter;
   map<string,string> filters = filt->get_map();
   for( iter = filters.begin(); iter != filters.end(); iter++ ){
       filt_targ->replace( iter->first, iter->second );
   }
   
   
   filt_targ->overwrite();
   
   delete filt;
   delete filt_targ;
}

