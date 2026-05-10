#ifndef MY_STRING_HPP
#define MY_STRING_HPP
class MyString{
    friend class TextWrapper;
    int n;
    int capacity;
    char* data;
    void clear();
public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);
    // MyString substr(int i, int len);
    char get(int i);
    void set(int i, char c);
    void set_new_string(const char *str);
    void print();
    void read_line();
    ~MyString();
};

#endif