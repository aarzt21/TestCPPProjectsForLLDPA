
#include <iostream>
#include <vector>
#include <random>

std::vector<int> generate_random_data(int n, int low, int high, int seed) {
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> distrib(low, high);

    std::vector<int> data(n);
    for(int i=0; i<n; ++i) data[i] = distrib(gen);

    return data;
}



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




int main(){
    auto calc = Parent();
    calc.set_name("Alex");
    std::vector<int> data;
    data = generate_random_data(10000, -10, 1000, 99);
    calc.calculate_result(data);

    for (int i = 0; i < 1000; i++){
        calc.get_result();
        calc.aggregate<false>();
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
        child.aggregate<true>();
        child.makeNoise();
    }
    std::cout << "Child res: " << child.get_result() << std::endl;



    std::cout << "Finished Program" << std::endl;
    return 0;

}