#pragma once
#include <string>
#include <fstream>
using namespace std;

class Base {
public:
    Base(const string& genus = "", const string& color = "");
    virtual ~Base();

    virtual void ShowInfo() const;

    virtual void SaveToFile(ofstream& file) const;
    virtual void LoadFromFile(ifstream& file);

    string GetGenus() const;
    void SetGenus(const string& genus);

    string GetColor() const;
    void SetColor(const string& color);

private:
    string genus;
    string color;
};