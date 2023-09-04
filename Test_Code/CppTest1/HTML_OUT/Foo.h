//
// Created by alex on 07.08.23.
//

#ifndef TEST3_FOO_H
#define TEST3_FOO_H


#include <string>
#include <iostream>
#include <vector>

class Foo {
public:

    Foo(std::string name);
    void set_status(int newStatus);
    int get_status();
    float get_result();
    std::string get_name();
    virtual void incResult();
    float calculate_result(std::vector<int>& data, bool inc_neg);
    void foo(std::vector<int>& data);

private:
    std::string name;
    int status;

protected:
    float result; 

};


#endif //TEST3_FOO_H
