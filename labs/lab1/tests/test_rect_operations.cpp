#include <iostream>
#include "../src/rect.hpp"
#include <cassert>
int main(){
    Rect r1(0,0,20,10);
    r1.move(1,2);
    assert(r1.get_left()==1);
    assert(r1.get_right()==21);
    assert(r1.get_bottom()==2);
    assert(r1.get_top()==12);

    Rect r2(0,0,20,10);
    r2.move(1);
    assert(r2.get_left()==1);
    assert(r2.get_right()==21);
    assert(r2.get_bottom()==0);
    assert(r2.get_top()==10);

    std::cout << "[+] Rect move test passed" << std::endl;

    Rect r3(-1,-1,1,1);
    r3.inflate(1);
    assert(r3.get_left()==-2);
    assert(r3.get_right()==2);
    assert(r3.get_bottom()==-2);
    assert(r3.get_top()==2);

    Rect r4(-1,-1,1,1);
    r4.inflate(1,2);
    assert(r4.get_left()==-2);
    assert(r4.get_right()==2);
    assert(r4.get_bottom()==-3);
    assert(r4.get_top()==3);

    Rect r5(-1,-1,1,1);
    r5.inflate(1,2,3,4);
    assert(r5.get_left()==-2);
    assert(r5.get_right()==3);
    assert(r5.get_bottom()==-5);
    assert(r5.get_top()==4);

    std::cout << "[+] Rect inflate test passed" << std::endl;
    return 0;
}