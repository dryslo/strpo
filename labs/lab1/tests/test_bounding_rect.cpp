#include <iostream>
#include "../src/rect.hpp"
#include <cassert>
int main(){
    Rect r1(0,0,1,1);
    Rect r2(100,0,101,3);

    Rect r3 = bounding_rect(r1,r2);
    Rect r4 = bounding_rect(r2,r1);

    assert(r3.get_left()==0);
    assert(r3.get_right()==101);
    assert(r3.get_bottom()==0);
    assert(r3.get_top()==3);

    assert(r4.get_left()==0);
    assert(r4.get_right()==101);
    assert(r4.get_bottom()==0);
    assert(r4.get_top()==3);


    Rect r5(101,3,0,0);

    Rect r6 = bounding_rect(r1,r5);
    Rect r7 = bounding_rect(r5,r1);

    assert(r6.get_left()==0);
    assert(r6.get_right()==101);
    assert(r6.get_bottom()==0);
    assert(r6.get_top()==3);

    assert(r7.get_left()==0);
    assert(r7.get_right()==101);
    assert(r7.get_bottom()==0);
    assert(r7.get_top()==3);

    std::cout << "[+] bounding_rect test passed" << std::endl;
    return 0;
}