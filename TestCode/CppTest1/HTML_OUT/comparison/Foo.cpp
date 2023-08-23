#include <string>
#include <iostream>
#include <vector>
#include <random>

class Foo {
public:
	Foo(std::string name) : name(name), status(1) {}
	
	void set_status(int newStatus) {
	    status = newStatus;
	}
	
	int get_status() {
	    return status;
	}
	
	std::string get_name() {
	    return name;
	}
	
	 virtual void shout() {
	// Refactor this class using the CRTP to get rid of virtual method.
	    std::cout << "Hello from Foo Parent" << std::endl;
	}
	
	float calculate_result(std::vector<int> &data, bool inc_neg) {
	// Refactor this method by applying the TBBE Pattern.
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
	
	void foo(std::vector<int> &data) {
	    int res = 0;
	
	    for (auto& e: data){
	        if (e != 325) {
	          res += e;
	        }
	        else {
	// Refactor this ELSE block by moving it into seperate method (0.1%).
	            res--;
	            res--;
	            res--;
	            res--;
	        }
	    }
	}
	
private:
	std::string name;
	float result;
	int status;

};



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
    for (int i = 0; i < 1000; i++) obj->calculate_result(data, true);
    for (int i = 0; i < 10000; i++) obj->foo(data);
    for (int i  = 0; i< 10000; i++) obj->shout();
    
    

    std::cout << "Mock Program With Original Code Finished" << std::endl;

    return 0;
}























