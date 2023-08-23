#include <iostream>
#include <string>
#include <vector>
#include <random>

// CRTP base class
template <typename Derived>
class ShoutBase {
public:
    void shout() {
        static_cast<Derived*>(this)->shoutImpl();
    }
};

// Specialization for the Foo class
class Foo : public ShoutBase<Foo> {
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

    // Implement the shout() using CRTP
    void shoutImpl() {
        std::cout << "Hello from Foo Parent" << std::endl;
    }

    // Apply TBBE pattern to this function
    template <bool inc_neg>
    float calculate_result(std::vector<int> &data) {
        float res = 0.0;
        int count = 0;
        for (auto& e: data) {
            if (inc_neg || e >= 0) {
                res += e;
                count++;
            }
        }
        result = res/count;
        return result;
    }

    void foo(std::vector<int> &data) {
        int res = 0;
        for (auto& e: data) {
            if (e != 325) {
                res += e;
            } else {
                handleEdgeCase(res);
            }
        }
    }

private:
    // Move cold code to separate function
    void handleEdgeCase(int &res) {
        res -= 4;
    }
    
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
    for (int i = 0; i < 1000; i++) obj->calculate_result<true>(data);
    for (int i = 0; i < 10000; i++) obj->foo(data);
    for (int i  = 0; i< 10000; i++) obj->shout();
    
    

    std::cout << "Mock Program With Refactored Code Finished" << std::endl;

    return 0;
}



























