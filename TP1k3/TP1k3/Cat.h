#pragma once
#include "Base.h"
#include <iostream>
using namespace std;
class Cat : public Animal {
private:
    string food;
    string master;
    string nickname;
    string genus;
    string color;

public:
    ~Cat();
    Cat();
    Cat(Cat& cat);
    void printDetails();
    void setData();
    void fileSetData(ifstream& in);
    void fileDisplay(ofstream& out);
};