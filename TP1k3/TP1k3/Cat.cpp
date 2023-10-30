// Cat.cpp
#include "Cat.h"

Cat::Cat() {
    cout << "Cat constructor called" << endl;
}

Cat::Cat(const string& genus, const string& color, const string& masterName, const string& name)
    : Base(genus, color), masterName(masterName), name(name) {
    cout << "Cat parameterized constructor called" << endl;
}

Cat::~Cat() {
    cout << "Cat destructor called" << endl;
}

void Cat::ShowInfo() const {
    cout << "\nCat Info:" << endl;
    Base::ShowInfo();
    cout << "Master Name: " << masterName << endl;
    cout << "Name: " << name << "\n" << endl;
}

string Cat::GetMasterName() const {
    return masterName;
}

void Cat::SetMasterName(const string& masterName) {
    this->masterName = masterName;
}

string Cat::GetName() const {
    return name;
}

void Cat::SetName(const string& name) {
    this->name = name;
}

void Cat::SaveToFile(ofstream& file) const {
    file << "Cat ";
    Base::SaveToFile(file); // —начала сохран€ем атрибуты из базового класса
    file << GetMasterName() << " " << GetName() << endl;
}

void Cat::LoadFromFile(ifstream& file) {
    if (file.is_open()) {
        string name, masterName, genus, color;

        file >> genus >> color >> masterName >> name;

        SetGenus(genus);
        SetColor(color);
        SetMasterName(masterName);
        SetName(name);
    }
}
