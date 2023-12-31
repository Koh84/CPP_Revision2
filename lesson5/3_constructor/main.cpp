#include <stdio.h>
#include <iostream>
#include <string.h>

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
        cout << "Person()" << endl;
    }

    Person(char *name)
    {
        cout << "Person(char)" << endl;
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
    }

    Person(char *name, int age, char *work = "none")
    {
        cout << "Person(char*, int)" << endl;
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->age = age;
        this->work = new char[strlen(work)+1];
        strcpy(this->work, work);
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
        cout << "name = " << name << " age = " << age << " work = " << work << endl;
    }
};

int main(int argc, char **argv)
{

    Person per("zhangsan", 200);
    Person per2; // call no params constructor
    // Person per2(); //this is wrong

    Person *per4 = new Person;
    Person *per5 = new Person; // same as above

    Person *per6 = new Person[2];

    Person *per7 = new Person("lisi", 18, "student");
    Person *per8 = new Person("wangwu", 18);

    per.printInfo();
    per7->printInfo();
    per8->printInfo();

    delete per4;
    delete per5;
    delete []per6;
    delete per7;
    delete per8;

    return 0;
}