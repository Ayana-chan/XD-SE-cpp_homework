#include "error.h"
#include "parser.h"

using namespace Error;
using namespace Parser_BasicReader;

int Error::no_of_errors=0;
double Error::error(const string& s) {
    no_of_errors++;
    int flag=0;
    if(curr_tok==PRINT)
        flag=1;//When flag==1,line_indicator has 1 extra.
    cerr<<"ERROR in line["<< line_indicator-flag <<"]: "<< s <<'\n';
    return 1;//6-+4=9 with confusing error.But in most cases,it looks like just delete the wrong char.
}
