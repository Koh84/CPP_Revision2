#include<stdio.h>

int main(int argc, char **argv) {
    double d = 100.1;
    int i = d;
    char *str = "Kelvin Koh";
    //reinterpret_cast is the same as basic c type casting
    int *p = reinterpret_cast<int *>(str);

    //error due to x64 is 64bit while usigned int is 4 bytes
    //use 32 bits compiler should be good.
    //printf("i = %d, str = 0x%x, p = 0x%x\n", i, reinterpret_cast<unsigned int>(str), reinterpret_cast<unsigned int>(p));

    return 0;
}