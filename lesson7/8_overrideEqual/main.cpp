#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

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
        this->name = NULL;
        this->work = NULL;
    }

    Person(char *name)
    {
        // cout << "Person(char)" << endl;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->work = NULL;
    }

    Person(char *name, int age, char *work = "none")
    {
        cout << "Person(char*, int), name = " << name << " age = " << age << endl;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
        this->work = new char[strlen(work) + 1];
        strcpy(this->work, work);
    }

    Person(const Person &per)
    {
        cout << "Person(Person *)" << endl;
        this->age = per.age;

        this->name = new char[strlen(per.name) + 1];
        strcpy(this->name, per.name);

        this->work = new char[strlen(per.work) + 1];
        strcpy(this->work, per.work);
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

    void printInfo(void) const
    {
        cout << "name = " << name << " age = " << age << " work = " << work << endl;
    }

    Person& operator=(const Person &p)
    {
        cout<<"operator=(const Person &p)"<<endl;

        if (this == &p)
            return *this;
        this->age = p.age;
        if (this->name)
        {
            delete this->name;
        }

        if (this->work)
        {
            delete this->work;
        }

        this->name = new char[strlen(p.name) + 1];
        strcpy(this->name, p.name);

        this->work = new char[strlen(p.work) + 1];
        strcpy(this->work, p.work);

        return *this;
    }
};

int main(int argc, char **argv)
{
    const Person p1("zhangsan", 10);

    cout<<"Person p2 = p1"<<endl;
    Person p2 = p1;
    
    Person p3;

    cout<<"p3 = p1"<<endl;
    p3 = p1;
    cout<<"end"<<endl;
    p1.printInfo();
    p2.printInfo();
    p2.printInfo();
    return 0;
}
