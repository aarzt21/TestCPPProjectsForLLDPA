#include <string>
#include <iostream>
#include <vector>

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
        return res;
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
