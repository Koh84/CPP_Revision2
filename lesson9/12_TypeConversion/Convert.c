#include<stdio.h>

int main(int argc, char **argv) {
    double d = 100.1;
    int i = d;
    char *str = "Kelvin Koh";
    int *p = str;

    printf("i = %d, str = 0x%x, p = 0x%x\n", i, str, p);

    return 0;
}