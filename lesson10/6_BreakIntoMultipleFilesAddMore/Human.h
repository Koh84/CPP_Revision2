#ifndef _HUMAN_H
#define _HUMAN_H

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Human
{
private:
    char *name;

public:
    void setName(char *name);
    char *getName(void);
    virtual void eating(void){ cout<<"use hand to eat"<<endl;};
    virtual void wearing(void){};
    virtual void driving(void){};
};

#endif