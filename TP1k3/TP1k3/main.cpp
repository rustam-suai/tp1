#include <iostream>
#include <clocale>
#include "Keeper.h"
#include "Bird.h"
#include "Cat.h"
#include "Fish.h"

int main() {
    setlocale(LC_ALL, "Russian");
    Keeper keeper;

    while (true) {
        cout << "Выберите действие:\n";
        cout << "1. Добавить животное\n";
        cout << "2. Удалить животное\n";
        cout << "3. Изменить животное\n";
        cout << "4. Вывести информацию о животных\n";
        cout << "5. Сохранить в файл\n";
        cout << "6. Восстановить из файла\n";
        cout << "7. Выйти\n";
        cout << "Введите номер выбранного действия: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            system("cls");
            cout << "Выберите вид животного:\n";
            cout << "1. Кошка\n";
            cout << "2. Рыба\n";
            cout << "3. Птица\n";
            cout << "Введите номер выбранного вида: ";

            int animalType;
            cin >> animalType;
            if (animalType == 1 or animalType == 2 or animalType == 3) {
                if (animalType == 1) {
                    system("cls");
                    Cat* cat = new Cat;
                    cat->setData();
                    keeper.addAnimal(cat);
                }
                else if (animalType == 2) {
                    system("cls");
                    Fish* fish = new Fish;
                    fish->setData();
                    keeper.addAnimal(fish);
                }
                else if (animalType == 3) {
                    system("cls");
                    Bird* bird = new Bird;
                    bird->setData();
                    keeper.addAnimal(bird);
                }
            }
            else {
                system("cls");
                cout << "Неверный вид животного." << endl;
            }

        }
        else if (choice == 2) {
            system("cls");
            if (keeper.getCount() > 0) {
                keeper.printAllDetails();
                cout << "Введите индекс животного для удаления: ";
                int index;
                cin >> index;
                system("cls");
                keeper.removeAnimal(index);
            }
            else {
                cout << "EMPTY\n";
            }
        }
        else if (choice == 3) {
            system("cls");
            if (keeper.getCount() > 0) {
                keeper.printAllDetails();
                cout << "Введите индекс животного для изменения: ";
                int index;
                cin >> index;
                system("cls");
                keeper.editMember(index);
            }
            else {
                cout << "EMPTY\n";
            }
        }
        else if (choice == 4) {
            system("cls");
            keeper.printAllDetails();
        }
        else if (choice == 5) {
            system("cls");
            keeper.fileDisplayKeep();
        }
        else if (choice == 6) {
            system("cls");
            keeper.fileSetDataKeep();
        }
        else if (choice == 7) {
            break;
        }
        else {
            system("cls");
            cout << "Неверный выбор." << endl;
        }

        cout << endl;
    }

    return 0;
}