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
    // Error, must have same return value and params and funciton name
    // virtual void test(void) { cout << "Human's test" << endl; }
    virtual Human *test(void)
    {
        cout << "Human's test" << endl;
        return this;
    }
};

class Englishman : public Human
{
public:
    virtual ~Englishman() { cout << "~Englishman" << endl; }
    void eating(void) { cout << "use knife to eat" << endl; }
    virtual Englishman *test(void)
    {
        cout << "Englishman's test" << endl;
        return this;
    }
};

class Chinese : public Human
{
public:
    virtual ~Chinese() { cout << "~Chinese" << endl; }
    void eating(void) { cout << "use chopsticks to eat" << endl; }
    virtual Chinese *test(void)
    {
        cout << "Chinese's test" << endl;
        return this;
    }
};

class Guangximan : public Chinese
{
public:
    virtual ~Guangximan() { cout << "~Guangximan" << endl; }
    void eating(void) { cout << "use chopsticks to eat, I come from guangxi" << endl; }
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
#if 1
    //Error on Englishman
    //Englishman& pe = dynamic_cast<Englishman&>(h);
    Chinese&    pc = dynamic_cast<Chinese&>(h);
    Guangximan& pg = dynamic_cast<Guangximan&>(h);
#else
    //Englishman should be wrong, throw error but no error was thrown
    //Hence Dynamic cast is safer to use than Reinterpret cast
    Englishman& pe = reinterpret_cast<Englishman&>(h);
    Chinese &pc = reinterpret_cast<Chinese &>(h);
    Guangximan &pg = reinterpret_cast<Guangximan &>(h);
#endif
    h.eating();
}

int main(int argc, char **argv)
{
    // Human h;
    // Englishman e;
    // Chinese c;
    Guangximan g;

    // test_eating(h);
    // test_eating(e);
    // test_eating(c);
    test_eating(g);

    return 0;
}