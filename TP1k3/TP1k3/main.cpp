// main.cpp
#include "Keeper.h"
#include "Fish.h"

int main() {
    Keeper keeper;

    Fish fish1("Som", "Grey", "Predator");
    Fish fish2("Pike", "Green", "Cannibal");

    keeper.AddAnimal(&fish1);
    keeper.AddAnimal(&fish2);
    
    keeper.ShowAllAnimals();
    keeper.SaveToFile("animals.txt");

    keeper.LoadFromFile("animals.txt");
    keeper.ShowAllAnimals();

    keeper.RemoveAnimal(2);
    keeper.ShowAllAnimals();

    return 0;
}
