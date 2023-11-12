#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Animal {
public:
    Animal() { cout << "Constructor ANIMAL\n"; };
    virtual ~Animal() { cout << "Destructor ANIMAL\n"; };
    virtual void printDetails() = 0;
    virtual void setData() = 0;
    virtual void fileDisplay(ofstream& out) = 0;
    virtual void fileSetData(ifstream& in) = 0;
};