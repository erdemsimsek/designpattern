//
// Created by erdem on 4/24/2021.
//

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class IDisplayBehaviour{
public:
    virtual int display() = 0;
};

class WildDisplay : public IDisplayBehaviour{
public:
    int display() override {
        cout << "WildDisplay" << endl;
    }
};

class FriendlyDisplay : public IDisplayBehaviour{
public:
    int display() override {
        cout << "FriendlyDisplay" << endl;
    }
};

class IFlyBehaviour{
public:
    virtual int fly() = 0;
};

class SimpleFly : public IFlyBehaviour{
public:
    int fly() override {
        cout << "SimpleFly" << endl;
    }
};

class NoFly : public IFlyBehaviour{
public:
    int fly() override {
        cout << "NoFly" << endl;
    }
};

class IQuackBehaviour{
public:
    virtual int quack() = 0;
};

class SimpleQuack : public IQuackBehaviour{
public:
    int quack() override {
        cout << "SimpleQuack" << endl;
    }
};

class NoQuack : public IQuackBehaviour{
public:
    int quack() override {
        cout << "NoQuack" << endl;
    }
};

class Duck{
private:
    IFlyBehaviour * flyB;
    IQuackBehaviour * quackB;
    IDisplayBehaviour * displayB;
public:
    Duck(IFlyBehaviour *flyB, IQuackBehaviour *quackB, IDisplayBehaviour *displayB) : flyB(flyB), quackB(quackB),
                                                                                      displayB(displayB) {
        cout << "Duck Class Contructed" << endl;
    }

    /* For runtime algorithm changes */
    void setFlyB(IFlyBehaviour *flyB) {
        Duck::flyB = flyB;
    }

    void setQuackB(IQuackBehaviour *quackB) {
        Duck::quackB = quackB;
    }

    void setDisplayB(IDisplayBehaviour *displayB) {
        Duck::displayB = displayB;
    }

    void quack(){
        this->quackB->quack();
    }

    void display(){
        this->displayB->display();
    }

    void fly(){
        this->flyB->fly();
    }
};

int main()
{
    Duck rubberDuck(new NoFly,new SimpleQuack,new FriendlyDisplay);

    rubberDuck.fly();
    rubberDuck.display();
    rubberDuck.quack();


    return 0;
}

