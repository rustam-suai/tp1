// Fish.cpp
#include "Fish.h"

Fish::Fish() {
    cout << "Fish constructor called" << endl;
}

Fish::Fish(const string& genus, const string& color, const string& food)
    : Base(genus, color), food(food) {
    cout << "Fish parameterized constructor called" << endl;
}

Fish::~Fish() {
    cout << "Fish destructor called" << endl;
}

void Fish::ShowInfo() const {
    cout << "\nFish Info:" << endl;
    Base::ShowInfo();
    cout << "Food: " << food << "\n" << endl;
}

string Fish::GetFood() const {
    return food;
}

void Fish::SetFood(const string& food) {
    this->food = food;
}

void Fish::SaveToFile(ofstream& file) const {
    file << "Fish ";
    Base::SaveToFile(file); // —начала сохран€ем атрибуты из базового класса
    file << GetFood() << endl;
}

void Fish::LoadFromFile(ifstream& file) {
    if (file.is_open()) {
        string genus, color, food;

        file >> genus >> color >> food;

        SetGenus(genus);
        SetColor(color);
        SetFood(food);
    }
}

