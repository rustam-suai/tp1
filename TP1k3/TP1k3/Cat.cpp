#include "Cat.h"
#include <iostream>
#include <fstream>
using namespace std;

Cat::Cat() { genus = ""; color = ""; food = ""; master = ""; nickname = ""; cout << "Constructor CAT\n"; };

Cat::Cat(Cat& cat) {
    genus = cat.genus; color = cat.color; food = cat.food; master = cat.master; nickname = cat.nickname; cout << "COPY Constructor CAT\n";
};

Cat::~Cat() { cout << "Destructor CAT\n"; };

void Cat::printDetails() {
    cout << "Cat - " << genus << ", color: " << color << ", food: "
        << food << ", master: " << master << ", nickname: " << nickname << endl;
}

void Cat::setData() {
    cout << "Порода: "; cin >> genus; cout << "\n";
    system("cls");
    cout << "Цвет: "; cin >> color; cout << "\n";
    system("cls");
    cout << "Пища: "; cin >> food; cout << "\n";
    system("cls");
    cout << "Хозяин: "; cin >> master; cout << "\n";
    system("cls");
    cout << "Кличка: "; cin >> nickname; cout << "\n";
    system("cls");
}

void Cat::fileSetData(ifstream& in) {
    in >> genus;
    in >> color;
    in >> food;
    in >> master;
    in >> nickname;
}
void Cat::fileDisplay(ofstream& out) {
    out << "Cat - " << genus << ", color: " << color << ", food: "
        << food << ", master: " << master << ", nickname: " << nickname << endl;
}