#include <string>
#include <vector>
#include <iostream>
#include <random>

class Calculator {
protected:
	int result;
	std::string name;
public:
	int get_result() {
	    return result;
	}
	
	void set_name(std::string name) {
	    this->name = name;
	}
	
	 virtual void calculate_result(std::vector<int> &data) {
	// Refactor this class using the CRTP to get rid of virtual method.
	    int sum = 0;
	
	    for (auto& e : data){
	        if (e % 543 != 0){
	            sum += e;
	        }
	        else {
	// Refactor this ELSE block by moving it into seperate method (0.2%).
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
	
	 virtual void makeNoise() {
	// Refactor this class using the CRTP to get rid of virtual method.
	    std::cout << "Hello from Parent" << std::endl;
	}
	
	int aggregate(int flag) {
	// Refactor this method by applying the TBBE Pattern.
	    int res = 0;
	
	    for (int i = -1000; i < 10000; i ++){
	        if (flag != 12){
	            res += i;
	        }
	        else {
	            if (i < 0) continue;
	// Refactor this THEN block by moving it into seperate method (0.0%).
	            res += i;
	        }
	    }
	
	    return res;
	}
	

};

class Child : public Calculator {
public:
	 virtual void makeNoise() {
	// Refactor this class using the CRTP to get rid of virtual method.
	    std::cout << "Hello from Child" << std::endl;
	}
	
	 virtual void calculate_result(std::vector<int> &data) {
	// Refactor this class using the CRTP to get rid of virtual method.
	    int sum = 0;
	
	    for (auto& e : data){
	        if (e % 229 != 0){
	            sum += e;
	        }
	        else {
	// Refactor this ELSE block by moving it into seperate method (0.6%).
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
	

};



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





















