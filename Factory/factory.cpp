#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


class Animal{
public:
    virtual void makeSound() = 0;
};

class Dog : public Animal{
public:
    void makeSound() override {
        cout << "Bark!" << endl;
    }
};

class Cat : public Animal{
public:
    void makeSound() override {
        cout << "Miaavv!" << endl;
    }
};

class Cow : public Animal{
public:
    void makeSound() override {
        cout << "Mooo!" << endl;
    }
};

class AnimalFactory{
public:
    virtual Animal * createAnimal() = 0;
};

class RandomFactory : public AnimalFactory{
public:
    RandomFactory() {
        srand (time(NULL));
    }

    Animal *createAnimal() override {
        int randomNumber =  rand() % 3;
        switch (randomNumber) {
            case 0:
                return new Dog();
                break;
            case 1:
                return new Cat();
                break;
            case 2:
                return new Cow();
                break;
        }
        return nullptr;
    }

};

int main()
{
    RandomFactory animals;

    vector <Animal *> animalList;

    for(int ind = 0; ind < 10; ++ind){
        animalList.push_back(animals.createAnimal());
    }

    for(int ind =0; ind < 10; ++ind){
        animalList[ind]->makeSound();
    }


    return 0;
}

