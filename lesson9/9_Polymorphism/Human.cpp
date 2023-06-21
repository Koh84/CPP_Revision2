#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

//static function and inline function cannot be a virtual function.

// virtual function allow the compiler to automatically
// call the right eating function
class Human
{
private:
    int a;

public:
    virtual void eating(void) { cout << "use hand to eat" << endl; }
};

class Englishman : public Human
{
public:
    void eating(void) { cout << "use knife to eat" << endl; }
};

class Chinese : public Human
{
public:
    void eating(void) { cout << "use chopsticks to eat" << endl; }
};

//Polymorphism only works with pointer
//hence if you pass as value, the object's 
//pointer to the virtual function will be removed.
//call Human's eating for all object
// void test_eating(Human h)
// {
//     h.eating();
// }

void test_eating(Human& h)
{
    h.eating();
}

int main(int argc, char **argv)
{
    Human h;
    Englishman e;
    Chinese c;

    test_eating(h);
    test_eating(e);
    test_eating(c);

    // without virtual function in Human class
    // these are all 1
    cout << "sizeof(Human) =" << sizeof(h) << endl;
    cout << "sizeof(Englishman) =" << sizeof(e) << endl;
    cout << "sizeof(Chinese) =" << sizeof(c) << endl;

    return 0;
}