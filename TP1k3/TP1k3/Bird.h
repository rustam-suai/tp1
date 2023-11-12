#pragma once
#include "Base.h"
#include <iostream>
using namespace std;
class Bird : public Animal {
private:
    string genus;
    string color;
    string place;

public:
    ~Bird();
    Bird();
    Bird(Bird& bird);
    void printDetails();
    void setData();
    void fileSetData(ifstream& in);
    void fileDisplay(ofstream& out);
};