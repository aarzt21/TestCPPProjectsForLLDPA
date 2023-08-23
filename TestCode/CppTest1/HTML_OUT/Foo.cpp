#include <string>
#include <iostream>
#include <vector>

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
