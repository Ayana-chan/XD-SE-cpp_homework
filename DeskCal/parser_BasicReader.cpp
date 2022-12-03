#include "parser.h"
#include "error.h"

using namespace Parser_BasicReader;
using namespace Error;

Token_value Parser_BasicReader::curr_tok;//Refer the char that get_token() get last time,which is going to be handled next.
unsigned int Parser_BasicReader::line_indicator=1;//show which line is reading.
map<string, double> Parser_BasicReader::table;//the NAME would be indexed in table.
double Parser_BasicReader::number_value;//save NUMBER's value
string Parser_BasicReader::string_value;//save NAME's value

Token_value Parser_BasicReader::get_token() {
    char ch;
    //skip whitespace except ’\n’
    do {
        if(!cin.get(ch))
            return curr_tok=END;
    } while (ch != '\n' && isspace(ch));
    //judge type
    switch (ch) {
        //let ';' equals to '\n' and PRINT.
        case ';':
        case '\n':
            line_indicator++;
            return curr_tok = PRINT;
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
        case '=':
            return curr_tok = Token_value(ch);
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '.':
            cin.putback(ch);
            cin>>number_value;
            return curr_tok = NUMBER;
        default: { //NAME, NAME=, or error
            if (isalpha(ch)) {
                string_value = ch;
                while (cin.get(ch) && isalnum(ch)) {
                    string_value.push_back(ch);//Read the string type one by one.
                }
                cin.putback(ch);//read one more word to do isalnum(ch),so put it back.
                return curr_tok = NAME;
            } else {
                error("bad token");//When would it happens? I don't know.
                return curr_tok = PRINT;
            }
        }
    }
}




