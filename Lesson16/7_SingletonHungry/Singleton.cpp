#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

class Singleton;

class Singleton
{
private:
    static Singleton *gInstance;

public:
    static Singleton *getInstance()
    {
        return gInstance;
    }

    void printInfo() { cout << "This is singleton" << endl; }

private:
    Singleton()
    {
        cout << "Singleton()" << endl;
    }
};

//饿汉模式 - hungry singleton instantiation
Singleton *Singleton::gInstance = new Singleton;

void *start_routine_thread1(void *arg)
{
    cout << "this is thread 2 ..." << endl;

    Singleton *s = Singleton::getInstance();
    s->printInfo();

    return NULL;
}

void *start_routine_thread2(void *arg)
{
    cout << "this is thread 1 ..." << endl;

    Singleton *s = Singleton::getInstance();
    s->printInfo();

    return NULL;
}

int main(int argc, char **argv)
{
    Singleton *s = Singleton::getInstance();
    s->printInfo();

    Singleton *s2 = Singleton::getInstance();
    s2->printInfo();

    Singleton *s3 = Singleton::getInstance();
    s3->printInfo();

    // Singleton *s4 = new Singleton();
    // Singleton s5;

    /* create multithreading */
    pthread_t thread1ID;
    pthread_t thread2ID;

    pthread_create(&thread1ID, NULL, start_routine_thread1, NULL);
    pthread_create(&thread2ID, NULL, start_routine_thread2, NULL);

    sleep(3);
    return 0;
}
