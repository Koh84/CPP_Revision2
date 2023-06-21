#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

// static function and inline function cannot be declared as virtual function.
// deconstructor must be declared as virtual function
// virtual function allow the compiler to automatically
// call the right eating function
class Human
{
private:
    int a;

public:
    virtual ~Human() { cout << "~Human" << endl; }
    virtual void eating(void) { cout << "use hand to eat" << endl; }
};

class Englishman : public Human
{
public:
    virtual ~Englishman() { cout << "~Englishman" << endl; }
    void eating(void) { cout << "use knife to eat" << endl; }
};

class Chinese : public Human
{
public:
    virtual ~Chinese() { cout << "~Chinese" << endl; }
    void eating(void) { cout << "use chopsticks to eat" << endl; }
};

// Polymorphism only works with pointer
// hence if you pass as value, the object's
// pointer to the virtual function will be removed.
// call Human's eating for all object
//  void test_eating(Human h)
//  {
//      h.eating();
//  }

void test_eating(Human &h)
{
    h.eating();
}

int main(int argc, char **argv)
{
    Human* h = new Human;
    Englishman* e = new Englishman;
    Chinese* c = new Chinese;

    Human *p[3] = { h, e, c};
    int i;
    for(i=0; i<3; i++){
        p[i]->eating();
        delete p[i];
    }

    return 0;
}