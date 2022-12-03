#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

//read & judge
namespace Parser_BasicReader {
    enum Token_value { //all tokens
        NAME, NUMBER, //Their value would be saved in number_value or string_value.
        END, ERR,   //ERR didn't be used!
        PLUS = '+', MINUS = '-', MUL = '*', DIV = '/',
        PRINT = ';', ASSIGN = '=', LP = '(', RP = ')',
    };

    extern Token_value get_token();//input
    extern unsigned int line_indicator;//show which line is reading.In addition,';' is also considered as the end of a line.
    extern Token_value curr_tok;//Refer the char that get_token() get last time,which is going to be handled next.

    extern map<string, double> table;//the NAME would be indexed in table.

    extern string string_value;//save NAME's value
    extern double number_value;//save NUMBER's value
}
//analyze & calculate
namespace Parser_Arithmometer {
    double expr(bool);//handle + -
    double term(bool get);//handle * /
    double prim(bool get);//handle primaries
}

#endif
