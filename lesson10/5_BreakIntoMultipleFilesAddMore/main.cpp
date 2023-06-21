#include "Chinese.h"
#include "Englishman.h"

int
main(int argc, char **argv)
{
    Englishman e;
    Chinese c;

    e.setName("Bill");
    c.setName("zhangsan");

    e.eating();
    c.eating();

    return 0;
}