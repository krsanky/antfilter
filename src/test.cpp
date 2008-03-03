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
