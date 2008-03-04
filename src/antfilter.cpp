#include <map>
#include <iostream>
#include <string>
#include <list>
#include <vector>
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
    string ff_name, sf_name, test, src_dir;
    bool debug;

    vector<int> v_int;
    vector<string> src_files, filter_files;

    GetOpt_pp ops(argc, argv);
    //eofbit cheks for options not present 
    //failbit check for malforned options (string instead of int)
    //ops.exceptions(std::ios::failbit | std::ios::eofbit);
    ops.exceptions(std::ios::failbit);

    try
    {
        if( ops >> OptionPresent('h', "help") ){
            show_usage();
            return(1);
        }
        ops >> Option('s', "src_file", src_files); 
        ops >> Option('f', "filter_file", filter_files); 
        ops >> OptionPresent('D', "debug", debug);

        //this checks for options given but not asked for (only if eofbit is set?)
        //ops.end_of_options(); 
        //what if we don't want eofbit set ?
        if( ops.options_remain() ) throw TooManyOptionsEx();

        if( debug ){
            cout << "debug:\n";

            for(vector<string>::const_iterator it = src_files.begin(); it != src_files.end(); ++it)
                cout << *it << ":";
            cout << "\n";

            for(vector<string>::const_iterator it = filter_files.begin(); it != filter_files.end(); ++it)
                cout << *it << ":";
            cout << "\n";
        }


        //foreach filter-file ... run_filter() on each src file. 
        //run_filter(ff_name, sf_name);

        ret = 0;
    }
    catch(TooManyOptionsEx &ex)
    {
        cout << "extraneous commandline option(s):" 
             << ex.what() << endl << endl;
        show_usage();
    }
    catch(GetOptEx &ex) //GetOptEx is the baseclass for getopt_pp defined Exceptions
    {
        cout << "getopt_pp exception:" 
             << ex.what() << endl << endl;
        show_usage();
    }

    return(ret);
}

void show_usage()
{
    cout << "-h, --help:        this message\n" 
         << "-s, --src_file:    file(s) to run filter on\n"
         << "-f, --filter_file: filter file(s)\n"
         << "-D, --debug:       echo some debugging stuff\n";
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

