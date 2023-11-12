#include "Fish.h"
#include <iostream>
#include <fstream>
using namespace std;

Fish::~Fish() { cout << "Destructor FISH\n"; };
Fish::Fish() { genus = ""; color = ""; food = ""; cout << "Constructor FISH\n"; };
Fish::Fish(Fish& fish) {
    genus = fish.genus; color = fish.color; food = fish.food; cout << "COPY Constructor FISH\n";
};
void Fish::printDetails() {
    cout << "Fish - " << genus << ", color: " << color << ", food: " << food << endl;
}
void Fish::setData() {
    cout << "Порода: "; cin >> genus; cout << "\n";
    system("cls");
    cout << "Цвет: "; cin >> color; cout << "\n";
    system("cls");
    cout << "Пища: "; cin >> food; cout << "\n";
    system("cls");
}
void Fish::fileSetData(ifstream& in) {
    in >> genus;
    in >> color;
    in >> food;
}
void Fish::fileDisplay(ofstream& out) {
    out << "Fish - " << genus << ", color: " << color << ", food: " << food << endl;
}