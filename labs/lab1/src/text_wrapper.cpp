#include "text_wrapper.hpp"
#include <iostream>
#include <cstring>
TextWrapper::TextWrapper(MyString& input,int line_width){
    inp = &input;
    this->line_width = line_width;
    MAX_STR = ((inp->capacity)/(this->line_width/2) + 1);
    strs = new char* [MAX_STR];
    for(int i = 0; i < MAX_STR;i++){
        strs[i] = new char[line_width+1];
    }
    inp_len = inp->n;
    mx = line_width;
}

void TextWrapper::print_wrapped(){
    #define SPACE "                                                                                   "
    while(inp->get(current_pos)!='\0'){
        int end_pos = current_pos + line_width;
        int last_space = -1;
        if(end_pos>inp_len) end_pos = inp_len;
        for(int i = current_pos;i<end_pos;i++){
            if(inp->get(i)==' ' || inp->get(i) == '\n'){
                last_space = i;
            }
        }
        if(last_space==-1) last_space = end_pos;
        len = last_space - current_pos;
        strncpy(strs[line],inp->data+current_pos,len);
        strs[line][len] = '\0';
        current_pos = last_space+1;
        line++;
        if(current_pos>=inp_len) break;
    }


    std::cout<<' ';
    for(int i = 0;i<=mx+1;i++){
    std::cout<<"_";
    }
    std::cout<<'\n';
    
    for(int i = 0;i<line;i++){
    strncat(strs[i],SPACE,mx-strlen(strs[i]));
    if(i%2==0){
        std::cout<<"/ "<<strs[i]<<" \\\n";
    }else
    {
        std::cout<<"\\ "<<strs[i]<<" /\n";
    }

    }
    std::cout<<' ';
    for(int i = 0;i<=mx+1;i++){
    std::cout<<"-";
    }
std::cout<<'\n';
std::cout << "    \\\n";
std::cout << "     \\\n";
std::cout << "       /\\_/\\  (\n";
std::cout << "      ( ^.^ ) _)\n";
std::cout << "        \\\"/  (\n";
std::cout << "      ( | | )\n";
std::cout << "     (__d b__)\n";
}

TextWrapper::~TextWrapper(){
    if(strs){
        for(int i = 0; i < MAX_STR;i++){
            delete[] strs[i];
        }
        delete[] strs;
    }
}
