/// helloworld.cpp
#include <iostream>

export module helloworld;
export namespace helloworld {
    class Hello {
    public:
        Hello(int v) { std::cout << "Hello::Hello: " << v <<std::endl; }
    }; 
   
    int global_data;
    void say_hello() {
        std::cout << "Hello Module! Data is " << global_data << std::endl;
    }
}
