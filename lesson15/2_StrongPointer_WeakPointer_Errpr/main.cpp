#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include "utils/RefBase.h"

using namespace std;
using namespace android;

class Person : public LightRefBase<Person>
{
private:
    sp<Person> father;
    sp<Person> son;

public:
    Person()
    {
        cout << "Person()" << endl;
    }

    ~Person()
    {
        cout << "~Person()" << endl;
    }

    void setFather(sp<Person> &father)
    {
        this->father = father;
    }

    void setSon(sp<Person> &son)
    {
        this->son = son;
    }

    void printInfo(void)
    {
        cout << "just a test function" << endl;
    }
};

void test_func()
{
    sp<Person> father = new Person();
    sp<Person> son = new Person();

    father->setSon(son);
    son->setFather(father);
}

int main(int argc, char **argv)
{
    test_func();
    return 0;
}
