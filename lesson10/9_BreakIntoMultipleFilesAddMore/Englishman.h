#ifndef _ENGLISHMAN_H
#define _ENGLISHMAN_H

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

#include "Human.h"

using namespace std;

class Englishman : public Human
{
public:
    char address[100];
    int age;

public:
    void eating(void);
    void wearing(void);
    void driving(void);
    Englishman();
    Englishman(char *name, int age, char *address);
    virtual ~Englishman();
};

#endif