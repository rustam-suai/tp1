// Cat.h
#pragma once
#include "Base.h"
#include <iostream>


class Cat : public Base {
public:
    Cat();
    Cat(const string& genus, const string& color, const string& masterName, const string& name);
    ~Cat() override;

    void ShowInfo() const override;

    string GetMasterName() const;
    void SetMasterName(const string& masterName);

    string GetName() const;
    void SetName(const string& name);

    void SaveToFile(ofstream& file) const override;
    void LoadFromFile(ifstream& file) override;

private:
    string masterName;
    string name;
};