#pragma once
#include "Base.h"
#include <iostream>
#include <fstream>
#include "Cat.h"
#include "Fish.h"
#include "Bird.h"
using namespace std;
class Keeper {
private:
    class Member {
    public:
        Animal* value;
        Member* prev;
        Member(Animal* data, Member* prev = nullptr) {
            this->value = data;
            this->prev = prev;
        }
        ~Member() {
            delete this->value;
        }

    };
    int count;
    Member* head;
    Member* end;

public:
    Keeper() {
        cout << "Constructor KEEPER\n";
        count = 0;
        head = nullptr;
        end = nullptr;
    }
    ~Keeper() {
        while (head != nullptr && count != 0) {
            end = head;
            head = head->prev;
            delete end;
            count--;
        }
        delete head;
        cout << "Destructor KEEPER\n";
    }
    int getCount() { return count; }

    Animal& operator[] (const int index) {
        int cnt = getCount();
        Member* cu;
        cu = this->head;

        while (cu != nullptr) {
            if (cnt == index) {
                return  *(cu->value);
            }
            cu = cu->prev;
            cnt--;
        }
    }

    void addAnimal(Animal* animal) {

        if (head == nullptr) {
            head = new Member(animal);
            head->value = animal;
        }
        else {
            end = new Member(animal);
            end->prev = head;
            head = end;
            head->value = animal;
        }
        count++;
    }

    void removeAnimal(int index) {
        try {
            if (getCount() == 0 or index > getCount() or index <= 0) throw exception("NOT FOUND\n");
            if (getCount() == 1) {
                delete this->head;
                head = nullptr;
                count--;
            }
            else if (index == getCount()) {
                Member* cu = this->head;
                head = head->prev;
                delete cu;
                count--;
            }
            else {
                Member* cu = this->head;
                Member* cu1 = this->head;
                int c = getCount();
                bool flag = 0;
                while (flag != 1) {
                    if (c == index) {
                        int r = getCount();
                        while (r != (c + 1)) {
                            cu1 = cu1->prev;
                            r--;
                        }
                        Member* temp = cu;
                        cu = cu->prev;
                        cu1->prev = cu;
                        delete temp;
                        flag = 1;
                        count--;
                    }
                    else {
                        cu = cu->prev;
                        c--;
                    }
                }
            }
        }
        catch (const exception& ex) {
            cout << ex.what();
        }

    }

    void printAllDetails() {
        try {
            if (getCount() == 0) throw exception("EMPTY\n");
            end = head;
            int i = getCount();
            while (end != nullptr && i != 0) {

                cout << "#" << i << " ";
                (end->value)->printDetails();
                end = end->prev;
                i--;
            }
        }
        catch (const exception& ex) {
            cout << ex.what();
        }
    }
    void editMember(int index) {
        try {
            if (getCount() == 0 or index > getCount() or index <= 0) throw exception("NOT FOUND\n");
            (*this)[index].setData();
        }
        catch (const exception& ex) {
            cout << ex.what();
        }
    }
    void fileSetDataKeep() {
        int countMemberFile = 0;
        Cat* cat;
        Fish* fish;
        Bird* bird;
        string str;
        ifstream in;
        in.open("in.txt");
        try {
            if (!in.is_open()) throw exception("IS CLOSED\n");
            if (in.eof()) throw exception("EMPTY FILE\n");
            in >> countMemberFile;
            for (int i = 0; i < countMemberFile; i++) {
                in >> str;
                if (str == "Cat") {
                    cat = new Cat;
                    cat->fileSetData(in);
                    this->addAnimal(cat);
                }
                else if (str == "Fish") {
                    fish = new Fish;
                    fish->fileSetData(in);
                    this->addAnimal(fish);
                }
                else {
                    bird = new Bird;
                    bird->fileSetData(in);
                    this->addAnimal(bird);
                }
            }
        }
        catch (const exception& ex) {
            cout << ex.what();
        }
        in.close();
    }
    void fileDisplayKeep() {
        ofstream out;
        out.open("out.txt", ios::out);

        try {
            if (!out.is_open()) throw exception("IS CLOSED\n");
            if (getCount() == 0) out << "EMPTY FILE\n";
            for (int i = 1; i < getCount() + 1; ++i) {

                if (sizeof((*this)[i]) == sizeof(Cat)) {
                    out << "type::Cat ";
                }
                else if (sizeof((*this)[i]) == sizeof(Fish)) {
                    out << "type::Fish ";
                }
                else if (sizeof((*this)[i]) == sizeof(Bird)) {
                    out << "type::Bird ";
                }

                (*this)[i].fileDisplay(out);
            }
        }
        catch (const exception& ex) {
            cout << ex.what();
        }
        out.close();
    }

};