#include <map>
#include <iostream>
#include <string>
using namespace std;

#include "getopt_pp.h"
using namespace GetOpt;

#include "filter_set.h"
#include "filter_target.h"


void show_usage();
void run_filter(string ff_name, string sf_name);


//MAIN
int main(int argc, char ** argv )
{

    int ret = -1;
    string ff_name, sf_name, test;
    bool flag;
    GetOpt_pp ops(argc, argv);
    ops.exceptions(std::ios::failbit | std::ios::eofbit);

    try
    {
        if( ops >> OptionPresent('h', "help") ){
            show_usage();
            return(1);
        }
        ops >> Option('s', "source_file", sf_name); 
        ops >> Option('f', "filter_file", ff_name); 
        ops >> Option('t', "test", test, "DEF-ARG"); 
        ops >> OptionPresent('l', "flag", flag);
        if(flag){
            cout << "FLAG!\n";
        }
        ops.end_of_options();    

        run_filter(ff_name, sf_name);

        ret = 0;
    }
    catch(TooManyOptionsEx)
    {
        cerr << "extraneous commandline option(s)\n\n";
        show_usage();
    }
    catch(GetOptEx)
    {
        cerr << "invalid commandline option(s)\n\n";
        show_usage();
    }

    return(ret);
}

void show_usage()
{
    cout << "-h, --help:        this message\n" 
         << "-s, --source_file: file to run filter on\n"
         << "-f, --filter_file: filter file\n"
         << "-t, --test:        this is a test option that doesn't need to be present\n"
         << "-l, --flag:        this is a test a flag option (no argument to the option)\n";
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

