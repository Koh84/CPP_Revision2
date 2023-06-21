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

public:
    int address;
    Person()
    {
        // cout << "Person()" << endl;
        this->name = NULL;
    }

    Person(char *name)
    {
        // cout << "Person(char)" << endl;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    Person(char *name, int age)
    {
        cout << "Person(char*, int), name = " << name << " age = " << age << endl;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
    }

    Person(Person &per)
    {
        cout << "Person(Person *)" << endl;
        this->age = per.age;

        this->name = new char[strlen(per.name) + 1];
        strcpy(this->name, per.name);
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

class Student : public Person
{
private:
    int grade;
    void setGrade(int grade)
    {
        this->grade = grade;
    }
    int getGrade(void)
    {
        return grade;
    }

public:
    void printInfo(void)
    {
        cout << "Student ";
        Person::printInfo();
    }
};

void test_func(Person &p)
{
    p.printInfo();
}

int main(int argc, char **argv)
{
    Person p("lisi", 16);

    Student s;
    s.setName("zhangsan");
    s.setAge(16);

    test_func(p);
    test_func(s); // Person &p = s; - only person's attribute can be accessed

    s.printInfo();
    return 0;
}
