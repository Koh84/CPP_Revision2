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
    void eating(void);
    void wearing(void);
    void driving(void);
    ~Englishman();
};

#endif