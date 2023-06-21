#include "Human.h"

void test_eating(Human *h){
    h->eating();
}

int
main(int argc, char **argv)
{
    Human& e = CreateEnglishman("Bill", 10, "swft");
    Human& c = CreateChinese("Zhangsan", 10, "swft");

    Human* h[2] = { &e, &c };
    int i;
    for(i = 0; i < 2; i++)
        test_eating(h[i]);

    delete &e;
    delete &c;

    return 0;
}