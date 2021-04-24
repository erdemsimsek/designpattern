//
// Created by erdem on 4/24/2021.
//

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bits/stdc++.h>
#include "timer.h"
#include <stdlib.h>

using namespace std;

class IObserver{
public:
    virtual void update() = 0;
};

class IDisplay{
public:
    virtual void display() = 0;
};

class IObservable{
public:
    virtual int addIObserver(IObserver *) = 0;
    virtual int removeIObserver(IObserver *) = 0;
    virtual int notifyIObserver() = 0;
};

class WeatherStation : public IObservable{
private:
    int temperature;
    list<IObserver *> list_IObserver;
    Timer time_interval = Timer();
public:
    WeatherStation() {
        srand(time(NULL));
        time_interval.setInterval([&]() {
            this->temperature = rand() % 100;
            cout << "Temperature: " << this->temperature << endl;
            this->notifyIObserver();
        }, 1000);
    }

    int addIObserver(IObserver *observer) override {
        list_IObserver.push_back(observer);
        return 0;
    }

    int removeIObserver(IObserver *observer) override {
        list_IObserver.remove(observer);
        return 0;
    }

    int notifyIObserver() override {
        for(auto item : list_IObserver)
            item->update();
        return 0;
    }

    int getTemperature()
    {
        return this->temperature;
    }
};

class PhoneDisplay : public IObserver, IDisplay
{
private:
    /* Adding IObservable here because, this class should be able to retrive data from Weather Station*/
    WeatherStation& wstation;
public:
    PhoneDisplay(WeatherStation &wstation) : wstation(wstation) {}

    void update() override {
        cout << "Update in PhoneDisplay is called" << endl;

        this->display();
    }

    void display() override {
        cout << "Phone Display Called Temperature is " << wstation.getTemperature() << endl;
    }
};

class WindowDisplay : public IObserver, IDisplay
{
private:
    /* Adding IObservable here because, this class should be able to retrive data from Weather Station*/
    WeatherStation& wstation;
public:
    WindowDisplay(WeatherStation &wstation) : wstation(wstation) {}

    void update() override {
        cout << "Update in WindowDisplay is called" << endl;

        this->display();
    }

    void display() override {
        cout << "Window Display Called Temperature is " << wstation.getTemperature() << endl;
    }
};

int main()
{
    WeatherStation station = WeatherStation();
    WindowDisplay window = WindowDisplay(station);
    PhoneDisplay phone = PhoneDisplay(station);


    station.addIObserver(&window);
    station.addIObserver(&phone);

    while(1);


    return 0;
}

