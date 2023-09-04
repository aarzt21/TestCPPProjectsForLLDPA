//
// Created by alex on 03.08.23.
//

#ifndef TEST2_CALCULATOR_H
#define TEST2_CALCULATOR_H


#include <string>
#include <vector>
#include <iostream>

class Calculator {

protected:
    int result;
    std::string name;

public:
    int get_result();

    void set_name(std::string name);

    virtual void calculate_result(std::vector<int>& data);

    virtual void makeNoise();

    int aggregate(int flag); //use int flag instead of bool

};


class Child: public Calculator {
public:
    void makeNoise() override;
    void calculate_result(std::vector<int> &data) override;
};


#endif //TEST2_CALCULATOR_H
