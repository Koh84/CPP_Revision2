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
        //cout << "Person()" << endl;
        this->name = NULL;
        this->work = NULL;
    }

    Person(char *name)
    {
        //cout << "Person(char)" << endl;
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->work = NULL;
    }

    Person(char *name, int age, char *work = "none")
    {
        //cout << "Person(char*, int)" << endl;
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->age = age;
        this->work = new char[strlen(work)+1];
        strcpy(this->work, work);
    }

    ~Person() 
    {
        cout<<"~Person()"<<endl;
        if(name){
            cout<<"name = "<<name<<endl;
            delete name;
        }
        
        if(work){
            cout<<"work = "<<work<<endl;
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
        //cout << "name = " << name << " age = " << age << " work = " << work << endl;
    }
};

void test_fun()
{
    Person per("zhangsan", 200); //only release after test_fun() finished running
    Person *per7 = new Person("lisi", 18, "student");
    delete per7; //we release it ourselves
}

int main(int argc, char **argv){
    test_fun();
    cout<<"run test_fun end"<<endl;
    return 0;
}

