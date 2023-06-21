#include<stdio.h>

int main(int argc, char **argv) {
    double d = 100.1;
    int i = d;

    //we need to add const cause " " is supposed to be const
    const char *str = "Kelvin Koh";

    //we user const_cast to remove const from above string, 
    //else it will have warning
    char *str2 = const_cast<char*>(str);
    //reinterpret_cast is the same as basic c type casting
    int *p = reinterpret_cast<int *>(str2);

    //error due to x64 is 64bit while usigned int is 4 bytes
    //use 32 bits compiler should be good.
    //printf("i = %d, str = 0x%x, p = 0x%x\n", i, reinterpret_cast<unsigned int>(str), reinterpret_cast<unsigned int>(p));

    return 0;
}