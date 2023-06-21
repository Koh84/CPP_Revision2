#include <stdio.h>
#include <iostream>
using namespace std;

class Person
{
private:
    char *name;
    int age;
    char *work;

public:
    Person()
    {
        cout<<"Person()"<<endl;
    }

    Person(char *name)
    {
         cout<<"Person(char)"<<endl;
        this->name = name;
    }

    Person(char *name, int age, char *work = "none")
    {
         cout<<"Person(char*, int)"<<endl;
        this->name = name;
        this->age = age;
        this->work = work;
    }

    void setName(char *name)
    {
        this->name = name;
    }

    int setAge(int age)
    {
        if (age < 0 || age > 150)
        {
            this->age = 0;
            return -1;
        }
        else
        {
            this->age = age;
            return 0;
        }
    }

    void printInfo(void)
    {
        cout<<"name = "<<name<<" age = "<<age<<" work = "<<work<<endl;
    }
};

int main(int argc, char **argv)
{

    Person per("zhangsan", 200);
    Person per2; //call no params constructor
    //Person per2(); //this is wrong
    per.printInfo();
  
    return 0;
}