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
	
	float get_result(){
	    return result; 
	}
	
	std::string get_name() {
	    return name;
	}
	
	 virtual void incResult() {
	// Refactor this class using the CRTP to get rid of virtual method.
	    result++;
	}
	
	float calculate_result(std::vector<int> &data, bool inc_neg) {
	// Refactor this method by applying the TBBE Pattern.
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
	
	void foo(std::vector<int> &data) {
	    int res = 0;
	
	    for (auto& e: data){
	        if (e != 325) {
	          res += e;
	        }
	        else {
	// Refactor this ELSE block by moving it into seperate method (0.1%).
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
	
private:
	std::string name;
	int status;
protected:
	float result;

};
