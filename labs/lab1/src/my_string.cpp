#include "my_string.hpp"
#include <iostream>
int get_str_len(const char* str){
    int res = 0;
    while(true){
        if (str[res]=='\0'){
            break;
        }
        res++;
    }
    return res;
}

MyString::MyString(): n(0),capacity(10){
    data = new char[capacity];
    data[0] = '\0';
}

MyString::MyString(const char* str){
    n = get_str_len(str);
    capacity = n+1;
    data = new char[capacity];
    for(int i = 0; i < n; i++){
        data[i] = str[i];
    }
    data[n] = '\0';

}
MyString::MyString(const MyString& other){
    n = other.n;
    capacity = other.capacity;
    data = new char[capacity];
    for (int i = 0; i <= n; i++){
        data[i] = other.data[i];
    }
}

char MyString::get(int i){
    if(i>=n || i<0){
        throw "str index out of range";
    }
    return data[i];
}

void MyString::set(int i, char c){
    if(i>=n || i<0){
        throw "str index out of range";
    }
    data[i] = c;
}

void MyString::clear(){
    if(data!=nullptr){
        delete[] data;
    }
    n = 0;
    capacity = 0;
    data = nullptr;
}

void MyString::set_new_string(const char* str){
    int l = get_str_len(str);
    if(l>=capacity){
        clear();
        n = l;
        capacity = n+1;
        data = new char[capacity];
        for(int i = 0; i < n; i++){
            data[i] = str[i];
        }
        data[n] = '\0';
    }
    else{
        n = l;
        for(int i = 0; i < n; i++){
        data[i] = str[i];
    }
    data[n] = '\0';
    }
}

void MyString::print(){
    std::cout<<data<<std::endl;
}


void MyString::read_line(){
    n = 0;
    int c;
    while ((c = getchar()) != EOF && c != '\n') {
        if (n >= capacity - 1) {
            int new_cap = capacity * 2;
            char *buf = new char[new_cap];
            for (int i = 0; i < n; i++) {
                buf[i] = data[i];
            }
            delete[] data;
            data = buf;
            capacity = new_cap;
        }
        data[n++] = (char)c;
    }
    data[n] = '\0';
}

MyString::~MyString(){
    clear();
}

MyString& MyString::operator=(const MyString& other){
    if(this == &other){
        return *this;
    }
    if(capacity < other.capacity){
        clear();
        capacity = other.capacity;
        data = new char[capacity];
    }
    n = other.n;
    for (int i = 0; i <= n; i++){
        data[i] = other.data[i];
    }
    return *this;
}