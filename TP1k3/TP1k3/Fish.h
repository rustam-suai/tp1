#pragma once
#include "Base.h"
#include <fstream>
#include <iostream>
class Fish : public Animal {
private:
    string genus;
    string color;
    string food;

public:
    ~Fish();
    Fish();
    Fish(Fish& fish);
    void printDetails();
    void setData();
    void fileSetData(ifstream& in);
    void fileDisplay(ofstream& out);
};