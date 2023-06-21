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
    // when a function start with virtual and end with =0
    // it becomes pure virtual function.
    // when a class contain pure virtual funciton, it becomes
    // abstract class - abstact class cannot create object out
    // of it. only its inheritance class can.
    virtual void eating(void) = 0;
    virtual void wearing(void) = 0;
    virtual void driving(void) = 0;
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
    void wearing(void) { cout << "wear english style" << endl; }
    void driving(void) { cout << "drive english car" << endl; }
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
    void wearing(void) { cout << "wear chinese style" << endl; }
    // void driving(void) { cout << "drive chinese car" << endl; }
    virtual Chinese *test(void)
    {
        cout << "Chinese's test" << endl;
        return this;
    }
};

class Guangximan : public Chinese
{
public:
    void driving(void) { cout << "drive Guangximan car" << endl; }
};

int
main(int argc, char **argv)
{
    Englishman e;
    Guangximan g;

    return 0;
}