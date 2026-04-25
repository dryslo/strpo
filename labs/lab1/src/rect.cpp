#include "rect.hpp"
#include <iostream>
int min(int a, int b){ return (a>b)?b:a;}
int max(int a, int b){ return (a<b)?b:a;}

Rect bounding_rect(Rect r1, Rect r2){
    return Rect(
    min(r1.get_left(),r2.get_left()),
    min(r1.get_bottom(),r2.get_bottom()),
    max(r1.get_right(),r2.get_right()),
    max(r1.get_top(),r2.get_top())
);
}
void print_rect(Rect &r){
    std::cout<<"Left: "<< r.get_left() << '\n';
    std::cout<<"Right: "<< r.get_right() << '\n';
    std::cout<<"Bottom: "<< r.get_bottom() << '\n';
    std::cout<<"Top: "<< r.get_top() << '\n'<<'\n';
/*     for(int i = r.get_bottom();i<r.get_top();i++){
        for(int j=r.get_left();j<r.get_right();j++){
            if(j==r.get_left() || (j+1)==r.get_right() || i == r.get_bottom() || (i+1)==r.get_top()){
                std::cout<<'*';
            }
            else{
                std::cout<<' ';
            }
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl; */
}


/* Rect::Rect():x1(0), y1(0), x2(0), y2(0){
    std::cout<<"Default: "<<this<<'\n';
}
Rect::Rect(int x1,int y1,int x2, int y2):x1(x1), y1(y1), x2(x2), y2(y2){ 
    std::cout<<"Params: "<<this<<'\n';
}
Rect::Rect(Rect& other):x1(other.x1),y1(other.y1),x2(other.x2),y2(other.y2){
    std::cout<<"Copy: "<<this<<'\n';
 }
Rect::~Rect(){
    std::cout<<"destructor "<<this<<'\n';
}
int Rect::get_left(){
    return min(x1,x2);
}
int Rect::get_right(){
    return max(x1,x2);
}
int Rect::get_top(){
    return max(y1,y2);
}
int Rect::get_bottom(){
    return min(y1,y2);
}

void Rect::set_all(int left, int right, int top, int bottom){
    x1 = left;
    x2 = right;
    y1 = bottom;
    y2 = top;
}

void Rect::inflate(int amount){
    x1 = get_left() - amount;
    x2 = get_right() + amount;
    y1 = get_bottom() - amount;
    y2= get_top() + amount;
}

void Rect::inflate(int dw, int dh){
    x1 = get_left() - dw;
    x2 = get_right() + dw;
    y1 = get_bottom() - dh;
    y2= get_top() + dh;
}

void Rect::inflate(int d_left, int d_right, int d_top, int d_bottom){
    x1 = get_left() - d_left;
    x2 = get_right() + d_right;
    y1 = get_bottom() - d_bottom;
    y2= get_top() + d_top;
}

void Rect::move(int x,int y){
    x1+=x;
    x2+=x;
    y1+=y;
    y2+=y;
}



int Rect::get_width(){
    return get_right() - get_left();
}
int Rect::get_height(){
    return get_top() - get_bottom();
}

int Rect::get_square(){
    return get_width()*get_height();
}

void Rect::set_width(int value){
    if(x2>x1){
        x2 = x1+value;
    }
    else{
        x1 = x2 + value;
    }
}

void Rect::set_height(int value){
    if(y2>y1){
        y2 = y1+value;
    }
    else{
        y1 = y2 + value;
    }
} */




Rect::Rect():x1(0), y1(0), width(0), height(0){
    std::cout<<"Default: "<<this<<'\n';
}
Rect::Rect(int x1,int y1,int x2, int y2):x1(min(x1,x2)), y1(min(y1,y2)), width(max(x1,x2)-min(x1,x2)), height(max(y1,y2)-min(y1,y2)){
    std::cout<<"Params: "<<this<<'\n';
}
Rect::Rect(Rect& other):x1(other.x1),y1(other.y1),width(other.width),height(other.height){
    std::cout<<"Copy: "<<this<<'\n';
 }
Rect::~Rect(){
    std::cout<<"destructor "<<this<<'\n';
}
int Rect::get_left(){
    return x1;
}
int Rect::get_right(){
    return x1+width;
}
int Rect::get_top(){
    return y1+height;
}
int Rect::get_bottom(){
    return y1;
}

void Rect::set_all(int left, int right, int top, int bottom){
    x1 = left;
    width = right-left;
    y1 = bottom;
    height = top-bottom;
}

void Rect::inflate(int amount){
    x1 = get_left() - amount;
    width += amount*2;
    y1 = get_bottom() - amount;
    height+= 2*amount;
}

void Rect::inflate(int dw, int dh){
    x1 = get_left() - dw;
    width+=dw*2;
    y1 = get_bottom() - dh;
    height+=dh*2;
}

void Rect::inflate(int d_left, int d_right, int d_top, int d_bottom){
    x1 = get_left() - d_left;
    width+= d_left;
    width+= d_right;
    y1 = get_bottom() - d_bottom;
    height+= d_bottom;
    height+= d_top;
}

void Rect::move(int x,int y){
    x1+=x;
    y1+=y;
}



int Rect::get_width(){
    return get_right() - get_left();
}
int Rect::get_height(){
    return get_top() - get_bottom();
}

int Rect::get_square(){
    return get_width()*get_height();
}

void Rect::set_width(int value){
    width = value;
}

void Rect::set_height(int value){
    height = value;
}