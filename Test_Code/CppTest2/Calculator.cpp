//
// Created by alex on 03.08.23.
//

#include "Calculator.h"

int Calculator::get_result() {
    return result;
}

void Calculator::calculate_result(std::vector<int> &data) {
    int sum = 0;

    for (auto& e : data){
        if (e % 543 != 0){
            sum += e;
        }
        else {
            int k = 0;
            k++;
            k++;
            k++;
            k++;
            sum += k;
        }
    }

    this->result = sum;
}

void Calculator::makeNoise() {
    std::cout << "Hello from Parent" << std::endl;
}

int Calculator::aggregate(int flag) {
    int res = 0;

    for (int i = -1000; i < 10000; i ++){
        if (flag != 12){
            res += i;
        }
        else {
            if (i < 0) continue;
            res += i;
        }
    }

    return res;
}

void Calculator::set_name(std::string name) {
    this->name = name;
}

void Child::makeNoise() {
    std::cout << "Hello from Child" << std::endl;
}

void Child::calculate_result(std::vector<int> &data) {
    int sum = 0;

    for (auto& e : data){
        if (e % 229 != 0){
            sum += e;
        }
        else {
            int k = 5;
            k++;
            k++;
            k++;
            k++;
            sum += k;
        }
    }

    this->result = sum;
}
