#pragma once
#include "Base.h"
#include <iostream>
using namespace std;
class Fish : public Base {
public:
    Fish();
    Fish(const string& genus, const string& color, const string& food);
    ~Fish() override;

    void ShowInfo() const override;

    string GetFood() const;
    void SetFood(const string& food);

    void SaveToFile(ofstream& file) const override;
    void LoadFromFile(ifstream& file) override;

private:
    string food;
};