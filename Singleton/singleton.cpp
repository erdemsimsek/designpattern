#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Singleton{
private:
    static Singleton* instance;
    static std::mutex mutex_;

    std::string name_;

    Singleton(const std::string name) : name_(name){
        cout << name_ << endl;
    }

public:
    static Singleton* getInstance(std::string& name){

        mutex_.lock();

        if(nullptr == instance)
        {
            instance = new Singleton(name);
        }

        mutex_.unlock();
        return instance;
    }

    /* Singletons should not be clonable */
    Singleton(Singleton &other) = delete;

    void operator=(const Singleton &) = delete;
};

Singleton * Singleton::instance = nullptr;
std::mutex Singleton::mutex_;


void ThreadFoo(){
    // Following code emulates slow initialization.
    std::string name1 = {"Foo"};
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::getInstance(name1);
}

void ThreadBar(){
    // Following code emulates slow initialization.
    std::string name2 = {"Bar"};
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::getInstance(name2);
}

int main()
{
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();

    return 0;
}

