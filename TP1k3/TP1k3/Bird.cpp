#include "Bird.h"
#include <iostream>
#include <fstream>
using namespace std;

Bird::~Bird() { cout << "Destructor BIRD\n"; };

Bird::Bird() { genus = ""; color = ""; place = ""; cout << "Constructor BIRD\n"; };

Bird::Bird(Bird& bird) {
    genus = bird.genus; color = bird.color; place = bird.place; cout << "COPY Constructor BIRD\n";
};

void Bird::printDetails() {
    cout << "Bird - " << genus << ", color: " << color << ", place: " << place << endl;
}

void Bird::setData() {
    cout << "Порода: "; cin >> genus; cout << "\n";
    system("cls");
    cout << "Цвет: "; cin >> color; cout << "\n";
    system("cls");
    cout << "Место обитания: "; cin >> place; cout << "\n";
    system("cls");
}

void Bird::fileSetData(ifstream& in) {
    in >> genus;
    in >> color;
    in >> place;
}

void Bird::fileDisplay(ofstream& out) {
    out << "Bird - " << genus << ", color: " << color << ", place: "
        << place << endl;
}