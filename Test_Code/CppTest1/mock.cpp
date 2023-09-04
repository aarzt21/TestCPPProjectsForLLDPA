#include <iostream>
#include <random>
#include "Foo.h"

std::vector<int> generate_random_data(int n, int low, int high, int seed) {
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distrib(low, high);
    std::vector<int> data(n);
    for(int i=0; i<n; ++i) data[i] = distrib(gen);
    return data;
}

int main() {
    Foo* obj = new Foo("Alex");
    obj->set_status(23);
    for (int i = 0; i < 100; i++) obj->set_status(i);
    for (int i = 0; i < 10000; i++) obj->get_name();
    
    for (int i = 0; i < 100; i++){
        auto data = generate_random_data(10000, -10, 
                            1000, i+1);
        obj->calculate_result(data, false);
        obj->calculate_result(data, true);
    }
    
    auto data = generate_random_data(10000, -10, 
                            1000, 234);
    for (int i = 0; i < 10000; i++) obj->foo(data);
    for (int i = 0; i < 10000; i++) obj->incResult();
    std::cout << "Mock Program Finished. Result: " << 
        obj->get_result() << std::endl;
    return 0;
}
