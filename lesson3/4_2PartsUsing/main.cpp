#include <stdio.h>
#include "person.h"
#include "dog.h"

/* global namespace*/
using A::Person;
using C::Dog;

int main(int argc, char **argv)
{
    /* local namespace */
    Person per;
    per.setName("zhangsan");
    per.setAge(16);
    per.printInfo();

    Dog dog;
    dog.setName("wangcai");
    dog.setAge(1);
    dog.printInfo();

    A::printVersion();
    C::printVersion();
    return 0;
}