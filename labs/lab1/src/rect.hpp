#ifndef RECT_HPP
#define RECT_HPP
/* class Rect{
    int x1,y1,x2,y2;
    friend Rect bounding_rect(Rect r1, Rect r2);
public:
    Rect(int x1,int y1,int x2,int y2);
    Rect();
    Rect(Rect& other);
    ~Rect();
    int get_left();
    int get_right();
    int get_top();
    int get_bottom();
    void set_all(int left, int right, int top, int bottom);
    void inflate(int amount);
    void inflate(int dw, int dh);
    void inflate(int d_left, int d_right, int d_top, int d_bottom);
    void move(int x,int y=0);
    int get_width();
    int get_height();
    int get_square();
    void set_width(int value);
    void set_height(int value);
}; */

class Rect{
    int x1,y1,width,height;
public:
    Rect(int x1,int y1,int x2,int y2);
    Rect();
    Rect(Rect& other);
    ~Rect();
    int get_left();
    int get_right();
    int get_top();
    int get_bottom();
    void set_all(int left, int right, int top, int bottom);
    void inflate(int amount);
    void inflate(int dw, int dh);
    void inflate(int d_left, int d_right, int d_top, int d_bottom);
    void move(int x,int y=0);
    int get_width();
    int get_height();
    int get_square();
    void set_width(int value);
    void set_height(int value);
};

Rect bounding_rect(Rect r1, Rect r2);
void print_rect(Rect &r);
#endif