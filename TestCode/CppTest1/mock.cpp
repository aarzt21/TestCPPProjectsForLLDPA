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
    auto data = generate_random_data(10000, -4, 1000, 234);

    Foo* obj = new Foo("Alex");
    obj->set_status(23);
    for (int i = 0; i < 100; i++) obj->set_status(i);
    for (int i = 0; i < 10000; i++) obj->get_name();
    for (int i = 0; i < 1000; i++) obj->calculate_result(data, 12);
    for (int i = 0; i < 10000; i++) obj->foo(data);
    for (int i  = 0; i< 10000; i++) obj->shout();
    
    

    std::cout << "Mock Program Finished" << std::endl;

    return 0;
}
