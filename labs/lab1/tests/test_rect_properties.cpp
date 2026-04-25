#include <iostream>
#include "../src/rect.hpp"
#include <cassert>
int main(){
    Rect rect(0,0,20,10);
    assert(rect.get_width() == 20);
    assert(rect.get_height() == 10);
    assert(rect.get_square() == 200);
    rect.set_width(100);
    assert(rect.get_width() == 100);
    rect.set_height(200);
    assert(rect.get_height() == 200);
    std::cout << "[+] Rect properties passed" << std::endl;
    return 0;
}