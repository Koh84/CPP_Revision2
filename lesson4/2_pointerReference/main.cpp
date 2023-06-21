#include <iostream>

using namespace std;

//pass by value
int add_one(int a){
    a = a+1;
    return a;
}

//pass by pointer
int add_one(int *a){
    *a = *a+1;
    return *a;
}

//pass by reference, reference is added to c++
//to allow user to avoid using pointer
int add_one_ref(int &b){
    b=b+1;
    return b;
}

int main(int argc, char **argv) {
    int a = 99;
    //int &c; <-- this will cause compilation error, must be init upfront
    //int &c = 1; <-- can't reference to a value, error
    int &c = a;

    cout<<add_one(a)<<endl; //100
    cout<<"a = "<<a<<endl; //99

    cout<<add_one(&a)<<endl; //100
    cout<<"a = "<<a<<endl; //100

    cout<<add_one_ref(a)<<endl; //101
    cout<<"a = "<<a<<endl; //101

    c++;
    cout<<"a = "<<a<<endl; //102
    cout<<"c = "<<c<<endl; //102
    return 0;
}