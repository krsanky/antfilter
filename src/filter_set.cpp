#include "filter_set.h"

filter_set::filter_set(string ff_name)
{
    this->ff_name = ff_name ;
}

void filter_set::read_filter_file()
{
    ifstream ffile(ff_name.c_str());

    string line;

    if( ffile.is_open() ){
        while (! ffile.eof() )
        {
            getline( ffile, line );
            filter_file.push_back(line);
        }
        ffile.close();
    } else {
        cerr << "Can't open input file: " << ff_name << endl;
    }
}

void filter_set::trim_ws(string & str)
{
    // trim leading whitespace
    string::size_type  notwhite = str.find_first_not_of(" \t\n");
    str.erase(0,notwhite);

    // trim trailing whitespace
    notwhite = str.find_last_not_of(" \t\n"); 
    str.erase(notwhite+1); 
}

void filter_set::parse_filter_file()
{
    //map<string,string> filters;
    list<string>::iterator iter;
    size_t idx;
    string key, val;

    for( iter = filter_file.begin(); iter != filter_file.end(); ++iter ){
        trim_ws( * iter);
        if( (! iter->empty()) && (iter->at(0) != '#') ){
            //cout << "[" << * iter << "]\n";
            //find the first "=" and split there
            idx = iter->find('=');
            if(idx != string::npos){
                key = iter->substr(0,idx);
                val = iter->substr(idx+1,iter->size()-1);
                trim_ws(key);
                trim_ws(val);
                //cout << "key[" << key << "] val[" << val << "]\n";
                filters.insert( pair<string,string>(key,val) );
            }
        }
    }
}

void filter_set::print_filters()
{
    map<string,string>::iterator iter;
    for( iter = filters.begin() ; iter != filters.end(); iter++ )
        cout << iter->first << " => " << iter->second << endl;
}

void filter_set::print_filter_file()
{
    list<string>::iterator iter;
    for( iter = filter_file.begin(); iter != filter_file.end(); ++iter ){
        cout << *iter << "\n";
    }
}

map<string,string> filter_set::get_map()
{
    return filters;
}
