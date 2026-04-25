#include <iostream>
#include "../src/rect.hpp"
#include <cassert>
int main(){
    Rect r_default;
    assert(r_default.get_left() == 0);
    assert(r_default.get_right() == 0);
    assert(r_default.get_bottom() == 0);
    assert(r_default.get_top() == 0);
    std::cout << "[+] Default constructor test passed!" << std::endl;

    Rect r_params(10, 20, 50, 100);
    assert(r_params.get_left() == 10);
    assert(r_params.get_bottom() == 20);
    assert(r_params.get_right() == 50);
    assert(r_params.get_top() == 100);
    std::cout << "[+] Parameterized constructor test passed!" << std::endl;

    Rect r_copy(r_params);
    assert(r_copy.get_left() == 10);
    assert(r_copy.get_right() == 50);
    assert(r_copy.get_top() == 100);
    assert(r_copy.get_bottom() == 20);
    std::cout << "[+] Copy constructor test passed!" << std::endl;

    Rect r_set;
    r_set.set_all(5, 15, 30, 10);
    assert(r_set.get_left() == 5);
    assert(r_set.get_right() == 15);
    assert(r_set.get_top() == 30);
    assert(r_set.get_bottom() == 10);
    std::cout << "[+] set_all test passed!" << std::endl;

    return 0;
}