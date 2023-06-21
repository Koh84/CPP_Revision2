#include <stdio.h>
#include "person.h"

int main(int argc, char **argv)
{
    Person per;
    per.setName("zhangsan");
    per.setAge(200);
    per.printInfo();
    return 0;
}