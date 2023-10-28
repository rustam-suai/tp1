#include "Base.h"
#include <iostream>
using namespace std;
Base::Base(const string& genus, const string& color)
    : genus(genus), color(color) {
    cout << "Base constructor called" << endl;
}

Base::~Base() {
    cout << "Base destructor called" << endl;
}

void Base::ShowInfo() const {
    cout << "Genus: " << genus << endl;
    cout << "Color: " << color << endl;
}

void Base::SaveToFile(ofstream& file) const {
    file << GetGenus() << " " << GetColor() << " ";
}

void Base::LoadFromFile(ifstream& file) {
    file >> genus >> color;
}

string Base::GetGenus() const {
    return genus;
}

void Base::SetGenus(const string& genus) {
    this->genus = genus;
}

string Base::GetColor() const {
    return color;
}

void Base::SetColor(const string& color) {
    this->color = color;
}