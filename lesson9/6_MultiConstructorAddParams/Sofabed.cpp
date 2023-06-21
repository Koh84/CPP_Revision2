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
    Sofabed(char *abc)
    {
        cout << "Sofabed(char *abc)" << endl;
    }
};

class LeftRightCom
{
public:
    LeftRightCom()
    {
        cout << "LeftRightCom()" << endl;
    }
    LeftRightCom(char *abc)
    {
        cout << "LeftRightCom(char *abc)" << endl;
    }
};

class Date
{
public:
    Date()
    {
        cout << "Date()" << endl;
    }
    Date(char *abc)
    {
        cout << "Date(char *abc)" << endl;
    }
};

class Type
{
public:
    Type()
    {
        cout << "Type()" << endl;
    }
    Type(char *abc)
    {
        cout << "Type(char *abc)" << endl;
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
    LeftRightSofabed(char *str1, char *str2, char *str3) : Sofabed(str1), LeftRightCom(str2), date(str3)
    {
        cout << "LeftRightSofabed()" << endl;
    }
};

int main(int argc, char **argv)
{
    LeftRightSofabed s("abc","2343","yyy");
    return 0;
}