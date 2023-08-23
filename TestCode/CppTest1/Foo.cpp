//
// Created by alex on 07.08.23.
//

#include "Foo.h"

Foo::Foo(std::string name) : name(name), status(1) {}

int Foo::get_status() {
    return status;
}

float Foo::calculate_result(std::vector<int> &data, bool inc_neg) {
    float res = 0.0;
    if (inc_neg){
        for (auto& e: data){
            res += e;
        }
        result = res/data.size();
        return result;
    }
    else {
        int count = 0;
        for (auto& e: data){
            if (e >= 0){
            	res += e; 
            	count++;
            }
        }
        result = res/count;
        return result;
    }
}

void Foo::foo(std::vector<int> &data) {
    int res = 0;

    for (auto& e: data){
        if (e != 325) {
          res += e;
        }
        else {
            res--;
            res--;
            res--;
            res--;
        }
    }
}

std::string Foo::get_name() {
    return name;
}

void Foo::shout() {
    std::cout << "Hello from Foo Parent" << std::endl;
}

void Foo::set_status(int newStatus) {
    status = newStatus;
}
