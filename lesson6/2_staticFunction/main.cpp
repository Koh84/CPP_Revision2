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
    char *work;

public:
    static int getCount(void);

    Person()
    {
        // cout << "Person()" << endl;
        this->name = NULL;
        this->work = NULL;
        cnt++;
    }

    Person(char *name)
    {
        // cout << "Person(char)" << endl;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->work = NULL;
        cnt++;
    }

    Person(char *name, int age, char *work = "none")
    {
        cout << "Person(char*, int), name = " << name << " age = " << age << endl;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
        this->work = new char[strlen(work) + 1];
        strcpy(this->work, work);
        cnt++;
    }

    Person(Person &per)
    {
        cout << "Person(Person *)" << endl;
        this->age = per.age;

        this->name = new char[strlen(per.name) + 1];
        strcpy(this->name, per.name);

        this->work = new char[strlen(per.work) + 1];
        strcpy(this->work, per.work);
        cnt++;
    }

    ~Person()
    {
        cout << "~Person()" << endl;
        if (name)
        {
            cout << "name = " << name << endl;
            delete name;
        }

        if (work)
        {
            cout << "work = " << work << endl;
            delete work;
        }
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

int Person::cnt = 0; /* init static variable */

int Person::getCount(void)
{
    return cnt;
}

int main(int argc, char **argv)
{
    Person p[100];
    cout << "person number = " << Person::getCount() << endl;
    cout << "person number = " << p[0].getCount() << endl;
    cout << "person number = " << p[1].getCount() << endl;
    return 0;
}
