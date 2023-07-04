#include <iostream>

using namespace std;

class OS
{
public:
    virtual void install() = 0;
};

class LinuxOS : public OS
{
public:
    void install() { cout << "Install Linux OS" << endl; }
};

class WindowsOS : public OS
{
public:
    void install() { cout << "Install Window OS" << endl; }
};

class Computer
{
public:
    virtual void printInfo() = 0;
};

class Mac : public Computer
{
public:
    void printInfo() { cout << "This is MAC, " << endl; }
};

class MacWithLinux : public Mac, public LinuxOS
{
public:
    void installOS()
    {
        printInfo();
        install();
    }
};

class MacWithWindows : public Mac, public WindowsOS
{
public:
    void installOS()
    {
        printInfo();
        install();
    }
};

class Lenovo : public Computer
{
public:
    void printInfo() { cout << "This is Lenovo, " << endl; }
};

class LenovoWithLinux : public Lenovo, public LinuxOS
{
public:
    void installOS()
    {
        printInfo();
        install();
    }
};

class LenovoWithWindows : public Lenovo, public WindowsOS
{
public:
    void installOS()
    {
        printInfo();
        install();
    }
};

int main(int argc, char **argv)
{
    MacWithLinux a;
    a.installOS();

    LenovoWithWindows b;
    b.installOS();
    
    return 0;
}
