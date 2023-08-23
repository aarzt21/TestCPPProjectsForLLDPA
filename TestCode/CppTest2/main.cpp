#include <iostream>
#include <random>
#include "Calculator.h"

std::vector<int> generate_random_data(int n, int low, int high, int seed) {
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distrib(low, high);

    std::vector<int> data(n);
    for(int i=0; i<n; ++i) data[i] = distrib(gen);

    return data;
}

int main() {
    // test parent class ----------------------
    auto calc = Calculator();
    calc.set_name("Alex");
    std::vector<int> data;
    for (int i = 0; i < 1000; i++){
        data = generate_random_data(10000, -10, 1000, i);
        calc.calculate_result(data);
        calc.get_result();
        calc.aggregate(11);
        calc.makeNoise();

    }
    std::cout << "Calc res: " << calc.get_result() << std::endl;


    // test child class ----------------------
    auto child = Child();
    child.set_name("Alex2");
    std::vector<int> data2;
    data2 = generate_random_data(10000, -10, 1000, 99);
    child.calculate_result(data2);

    for (int i = 0; i < 1000; i++){
        child.get_result();
        child.aggregate(12);
        child.makeNoise();
    }
    std::cout << "Child res: " << child.get_result() << std::endl;



    std::cout << "Finished Program" << std::endl;
    return 0;
}
