// main.cpp
#include "Keeper.h"
#include "Fish.h"
#include "Cat.h"

int main() {
    Keeper keeper;

    Fish fish1("Som", "Grey", "Predator");
    Fish fish2("Pike", "Green", "Cannibal");

    Cat cat1("Britain", "Orange", "Lermontov Mihail Yuryevich","Vasya");
    Cat cat2("Scottish", "Grey", "Tolstoy Lev Nikolaevich", "Barsik");

    keeper.AddAnimal(&fish1);
    keeper.AddAnimal(&fish2);

    keeper.AddAnimal(&cat1);
    keeper.AddAnimal(&cat2);
    
    //keeper.ShowAllAnimals();
    keeper.SaveToFile("animals.txt");

    keeper.LoadFromFile("animals.txt");
    keeper.ShowAllAnimals();

    //keeper.RemoveAnimal(2);
    //keeper.ShowAllAnimals();

    return 0;
}
