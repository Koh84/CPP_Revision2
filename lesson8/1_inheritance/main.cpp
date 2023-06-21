#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Person
{
private:
    static int cnt;
    char *name;
    int age;

public:
    static int getCount(void);

    Person()
    {
        // cout << "Person()" << endl;
        this->name = NULL;
        cnt++;
    }

    Person(char *name)
    {
        // cout << "Person(char)" << endl;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        cnt++;
    }

    Person(char *name, int age)
    {
        cout << "Person(char*, int), name = " << name << " age = " << age << endl;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
        cnt++;
    }

    Person(Person &per)
    {
        cout << "Person(Person *)" << endl;
        this->age = per.age;

        this->name = new char[strlen(per.name) + 1];
        strcpy(this->name, per.name);

        cnt++;
    }

    ~Person()
    {
        cout << "~Person()" << endl;
        if (this->name)
        {
            cout << "name = " << name << endl;
            delete name;
        }
    }

    void setName(char *name)
    {
        if (this->name)
        {
            delete name;
        }

        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
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
        cout << "name = " << name << " age = " << age << endl;
    }
};

int Person::cnt = 0; /* init static variable */

int Person::getCount(void)
{
    return cnt;
}

class Student: public Person{

};

int main(int argc, char **argv)
{
    Student s;
    s.setName("zhangsan");
    s.setAge(16);
    s.printInfo();
    return 0;
}
