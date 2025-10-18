#include<iostream>
#include<string>

class MyInterger {
public:
    int x, y; 
public:
    MyInterger operator++(int) {
        MyInterger temp = *this;
        x++, y++;
        return temp;
    }  

    MyInterger operator++() {
        x++, y++;
        return *this;
    }
};

int main(int argc, const char** argv) {
    MyInterger myInt {1, 2};
    std::cout << myInt.x << myInt.y << std::endl;
    MyInterger a = myInt++;
    std::cout << a.x << a.y << std::endl;
    MyInterger b = ++myInt;
    std::cout << b.x << b.y << std::endl;

    return 0;
}