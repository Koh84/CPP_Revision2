#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Sofa
{
private:
    int weight;

public:
    void watchTV(void) { cout << "watch TV" << endl; }
    void setWeight(int weight) { this->weight = weight; }
    int getWeight(void) { return weight; }
};

class Bed
{
private:
    int weight;

public:
    void sleep(void) { cout << "sleep" << endl; }
    void setWeight(int weight) { this->weight = weight; }
    int getWeight(void) { return weight; }
};

class Sofabed : public Sofa, public Bed
{
};

int main(int argc, char **argv)
{
    Sofabed s;
    s.watchTV();
    s.sleep();

    //s.setWeight(100); /* error ambiguous function*/
    //s.Sofa::setWeight(100); /* fixed the above but too much to write */

    return 0;
}