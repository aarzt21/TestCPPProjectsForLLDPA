//
// Created by alex on 07.08.23.
//

#include "Foo.h"

Foo::Foo(std::string name) : name(name), status(1) {}

int Foo::get_status() {
    return status;
}

float Foo::get_result(){
    return result; 
}

float Foo::calculate_result(std::vector<int> &data, bool inc_neg) {
	float res = 0.0;
    int count = 0;
    for (auto e: data){
        if (inc_neg){
            res += e;
        } 
        else{
            if (e >= 0){
                res += e;
                count++;
            }
        }
    }
    if (inc_neg){
        result = res/data.size();
    } 
    else {
        result = res/count;
    }
    return res;
}

void Foo::foo(std::vector<int> &data) {
    int res = 0;

    for (auto& e: data){
        if (e != 325) {
          res += e;
        }
        else {
        	res--;
	        int p = 0;
	        res--;
	        p++;
	        res--;
	        p++;
	        res--;
	        p++;
	        res--;
	        p++;
	        res--;
	        p++;
	        res--;
	        p++;
	        res--;
        }
    }
}

std::string Foo::get_name() {
    return name;
}

void Foo::incResult() {
    result++;
}

void Foo::set_status(int newStatus) {
    status = newStatus;
}
