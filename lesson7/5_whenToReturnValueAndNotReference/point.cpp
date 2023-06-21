#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    Point()
    {
        cout << "Point()" << endl;
    }

    Point(int x, int y) : x(x), y(y)
    {
        cout << "Point(int x, int y)" << endl;
    }

    Point(const Point &p)
    {
        cout << " Point(const Point& p) " << endl;
        x = p.x;
        y = p.y;
    }

    ~Point()
    {
        cout << "~Point()" << endl;
    }

    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void setX(int x)
    {
        this->x = x;
    }
    void setY(int y)
    {
        this->y = y;
    }
    void printInfo()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
    friend Point add(Point &p1, Point &p2);
    friend Point operator+(Point &p1, Point &p2);
    friend Point& operator++(Point &p1);
    friend Point operator++(Point &p, int a);
};

Point add(Point &p1, Point &p2)
{
    Point n;
    n.x = p1.x + p2.x;
    n.y = p1.y + p2.y;
    return n;
}

Point operator+(Point &p1, Point &p2)
{
    cout << "Point operator+(Point &p1, Point &p2)" << endl;
    Point n;
    n.x = p1.x + p2.x;
    n.y = p1.y + p2.y;
    return n;
}

/* Point(1,2); ++p */
Point& operator++(Point &p)
{
    cout << "p++" << endl;
    p.x += 1;
    p.y += 1;
    return p;
}

/* Point(1,2); p++ */
Point operator++(Point &p, int a)
{
    cout << "++p" << endl;
    Point n;
    n = p;
    p.x += 1;
    p.y += 1;
    return n;
}

int main(int argc, char **argv)
{
    Point p1(1, 2);
    Point m,n;

    cout<<"begin"<<endl;
    m = ++p1;
    cout << "***********" << endl;
    n = p1++; // we cannot return reference here because
              // we don't know if we should return reference of
              // n or p, n is local variable so will be destroyed
              // when function complete running. 
              // p contain update value which we don't want, we 
              // want older value. So, we need to return value
              // wehn using p++
    cout<<"end"<<endl;

    return 0;
}