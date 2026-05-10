#ifndef TEXT_WRAPPER_HPP
#define TEXT_WRAPPER_HPP
#include "my_string.hpp"
class TextWrapper{
    MyString* inp;
    int line_width;
    int MAX_STR;
    char** strs;
    int len = 0;
    int current_pos = 0;
    int line = 0;
    int inp_len;
    int mx;
public:
    TextWrapper(MyString& input,int line_width);
    void print_wrapped();
    ~TextWrapper();
};

#endif