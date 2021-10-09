import helloworld;
import math;

/// main.cpp
#include <iostream>
#include <vector>

int main() {
    auto v = std::vector<int>{1,2,3,4,5,6};
    for (auto elem: v) { 
        std::cout << elem << std::endl;
    }

    std::cout << add(12, 89) << std::endl;
    helloworld::Hello h{45};
    helloworld::global_data = 123;
    helloworld::say_hello();
}


