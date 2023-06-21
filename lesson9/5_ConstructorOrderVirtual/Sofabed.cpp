#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

/* The basic difference between a virtual and abstratc class
is that methods in virtual class CAN be overridden
in derived classes, while abstract class methods
MUST be overridden.*/

class Furniture
{
private:
    int weight;

public:
    Furniture()
    {
        cout << "Furniture()" << endl;
    }
    void setWeight(int weight) { this->weight = weight; }
    int getWeight(void) { return weight; }
};

class Certification3C{
    public:
    Certification3C()
    {
        cout << "Certification3C()" << endl;
    }
};

class Sofa : virtual public Furniture, virtual public Certification3C
{
private:
    int a;

public:
    Sofa()
    {
        cout << "Sofa()" << endl;
    }
    void watchTV(void) { cout << "watch TV" << endl; }
};

class Bed : virtual public Furniture, virtual public Certification3C
{
private:
    int b;

public:
    Bed()
    {
        cout << "Bed()" << endl;
    }
    void sleep(void) { cout << "sleep" << endl; }
};

class Sofabed : public Sofa, public Bed
{
private:
    int c;

public:
    Sofabed()
    {
        cout << "Sofabed()" << endl;
    }
};

class LeftRightCom
{
public:
    LeftRightCom()
    {
        cout << "LeftRightCom()" << endl;
    }
};

class Date
{
public:
    Date()
    {
        cout << "Date()" << endl;
    }
};

class Type
{
public:
    Type()
    {
        cout << "Type()" << endl;
    }
};

class LeftRightSofabed : public Sofabed, virtual public LeftRightCom
{
private:
    Date date;
    Type type;

public:
    LeftRightSofabed()
    {
        cout << "LeftRightSofabed()" << endl;
    }
};

int main(int argc, char **argv)
{
    LeftRightSofabed s;
    return 0;
}