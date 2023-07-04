#include <iostream>

using namespace std;

class OS
{
public:
    virtual void installOS_impl() = 0;
};

class LinuxOS : public OS
{
public:
    void installOS_impl() { cout << "Install Linux OS" << endl; }
};

class WindowsOS : public OS
{
public:
    void installOS_impl() { cout << "Install Window OS" << endl; }
};

class UnixOS : public OS
{
public:
    void installOS_impl() { cout << "Install Unix OS" << endl; }
};

class Computer
{
public:
    virtual void printInfo() = 0;
    virtual void installOS() = 0;
};

class MAC : public Computer
{
public:
    void printInfo() { cout << "This is MAC, " << endl; }
    MAC(OS *impl)
    {
        this->impl = impl;
    }
    void installOS() 
    {
        printInfo(); impl->installOS_impl();
    }
private:
    OS *impl;
};

class Lenovo : public Computer
{
public:
    void printInfo() { cout << "This is Lenovo, " << endl; }
    Lenovo(OS *impl)
    {
        this->impl = impl;
    }
    void installOS() 
    {
        printInfo(); impl->installOS_impl();
    }
private:
    OS *impl;
};

int main(int argc, char **argv)
{
    OS *os1 = new LinuxOS();
    OS *os2 = new WindowsOS();
    OS *os3 = new UnixOS();

    Computer *c1 = new MAC(os1);
    Computer *c2 = new Lenovo(os2);
    Computer *c3 = new Lenovo(os3);

    c1->installOS();
    c2->installOS();
    c3->installOS();

    return 0;
}
