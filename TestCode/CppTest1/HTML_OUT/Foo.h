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
    Foo(std::string name);;

    void set_status(int newStatus);

    int get_status();

    std::string get_name();

    virtual void shout();

    float calculate_result(std::vector<int>& data, bool inc_neg);

    void foo(std::vector<int>& data);


private:
    std::string name;
    float result;
    int status;

};


#endif //TEST3_FOO_H
