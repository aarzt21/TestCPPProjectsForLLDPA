template <typename Derived>
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
	
	void calculate_result(std::vector<int> &data) {
	    int sum = 0;
	
	    for (auto& e : data){
	        if (static_cast<Derived*>(this)->isSpecialCase(e)){
	            sum += static_cast<Derived*>(this)->handleSpecialCase(e);
	        }
	        else {
	            sum += e;
	        }
	    }
	
	    this->result = sum;
	}
	
	void makeNoise() {
	    std::cout << static_cast<Derived*>(this)->noiseMessage() << std::endl;
	}
	
	template <bool flag>
	int aggregate() {
	    int res = 0;
	
	    if constexpr (flag) {
			for (int i = -1000; i < 10000; i ++) {
				res += i;
			}
		} else {
			for (int i = 0; i < 10000; i ++) {
				res += static_cast<Derived*>(this)->thenBlock(i);
			}
		}
	
	    return res;
	}
};

class Child : public Calculator<Child> {
public:
	bool isSpecialCase(int e) {
	    return e % 229 == 0;
	}
	
	int handleSpecialCase(int e) {
	    int k = 5;
	    k++;
	    k++;
	    k++;
	    k++;
	    return k;
	}
	
	static std::string noiseMessage() {
	    return "Hello from Child";
	}
	
	static int thenBlock(int i) {
	    return i;
	}
};

class Parent : public Calculator<Parent> {
public:
	bool isSpecialCase(int e) {
	    return e % 543 == 0;
	}
	
	int handleSpecialCase(int e) {
	    int k = 0;
	    k++;
	    k++;
	    k++;
	    k++;
	    return k;
	}
	
	static std::string noiseMessage() {
	    return "Hello from Parent";
	}
	
	static int thenBlock(int i) {
	    return i;
	}
};