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

    Person(Person &per)
    {
        cout << "Person(Person *)" << endl;
        this->age = per.age;

        this->name = new char[strlen(per.name)+1];
        strcpy(this->name, per.name);
        
        this->work = new char[strlen(per.work)+1];
        strcpy(this->work, per.work);
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
        cout << "name = " << name << " age = " << age << " work = " << work << endl;
    }
};

int main(int argc, char **argv){
    Person per("zhangsan", 20); 
    Person per2(per); //this will use default copy constructor
                        //the issue using this is that when "per" calling
                        //deconstructor, "per2" later will call again
                        //but value in "per2" has been cleared, so a bug happen.
                        //we need to provide our own copy constructor. 
                        //in our own copy construction, we allocate heap memory,
                        //so when destructor occure, it deallocate its own heap
                        //memory.   
    per2.printInfo();
    
    return 0;
}

