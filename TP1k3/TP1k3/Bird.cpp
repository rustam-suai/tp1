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
    cout << "������: "; cin >> genus; cout << "\n";
    system("cls");
    cout << "����: "; cin >> color; cout << "\n";
    system("cls");
    cout << "����� ��������: "; cin >> place; cout << "\n";
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