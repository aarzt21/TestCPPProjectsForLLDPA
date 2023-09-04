#include <string>
#include <iostream>
#include <vector>
#include <random>

#ifdef OPTIM
template <typename Derived>
class CRTPTemplate {
public:
    void incResult(){static_cast<Derived*>(this)->incImpl();}
};


class Foo: public CRTPTemplate<Foo>{
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
    
    void incImpl() {
        result++;
    }

    template <bool include_negatives>
    float calculate_result(std::vector<int> &data) {
        float res = 0.0;
        int count = 0;
        for (auto e: data){
            if (include_negatives){
                res += e;
            }
            else{
                if (e >= 0){
                    res += e;
                    count++;
                }
            }
        }
        if (include_negatives){
            result = res/data.size();
        }
        else {
            result = res/count;
        }
        return result;
    }

    void foo(std::vector<int> &data) {
        int res = 0;

        for (auto& e: data){
            if (e != 325) {
              res += e;
            }
            else {
                handleSpecialCase(res);
            }
        }
    }

private:
    std::string name;
    int status;
protected:
    float result;

    void handleSpecialCase(int res){
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
        p++;
        res--;
    }

};

#else

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
	    result++;
	}
	
	float calculate_result(std::vector<int> &data, bool inc_neg) {
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
	    return result;
	}
	
	void foo(std::vector<int> &data) {
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
	
private:
	std::string name;
	int status;
protected:
	float result;

};
#endif


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
    //ignore getter and setter invocations
    
    #ifndef OPTIM
    for (int i = 0; i < 100; i++){
        auto data = generate_random_data(10000, -100, 1000, i+1);
        obj->calculate_result(data, true);
        obj->calculate_result(data, false);
    } 

    #else
    for (int i = 0; i < 100; i++){
        auto data = generate_random_data(10000, -100, 1000, i+1);
        obj->calculate_result<true>(data);
        obj->calculate_result<false>(data);
    } 
    #endif
    auto data = generate_random_data(10000, -100, 1000, 234);
    for (int i = 0; i < 10000; i++) obj->foo(data);
    for (int i = 0; i < 10000; i++) obj->incResult();

    #ifdef OPTIM
    std::cout << "Mock Program with refactored code finished. Result: " << obj->get_result() << std::endl;
    #else
    std::cout << "Mock Program with original code finished. Result: " << obj->get_result() << std::endl;
    #endif
    return 0;
}