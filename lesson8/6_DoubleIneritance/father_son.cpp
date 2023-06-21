#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Father
{
private:
    int money;

protected:
    int room_key;

public:
    int address;
    void it_skill(void)
    {
        cout << "father's skill" << endl;
    }
    int getMoney(void)
    {
        return money;
    }
    void setMoney(int money)
    {
        this->money = money;
    }
};

class Son_pub : public Father
{
private:
    int toy;

public:
    using Father::room_key;
    void play_game(void)
    {
        int m;

        cout << "son play game" << endl;

        /* money -= 1;
         * cannot access father's money directly
         */

        /*
         *but can ask father to give money
         */
        m = getMoney();
        m--;
        setMoney(m);

        /*
         * Only son can access father's protected room key
         */
        room_key = 1;
    }
};

class Son_pro : protected Father
{
private:
    int toy;

public:
    using Father::room_key;
    void play_game(void)
    {
        int m;

        cout << "son play game" << endl;

        /* money -= 1;
         * cannot access father's money directly
         */

        /*
         *but can ask father to give money
         */
        m = getMoney();
        m--;
        setMoney(m);

        /*
         * Only son can access father's protected room key
         */
        room_key = 1;
    }
};

class Son_pri : private Father
{
private:
    int toy;

public:
    using Father::room_key;
    void play_game(void)
    {
        int m;

        cout << "son play game" << endl;

        /* money -= 1;
         * cannot access father's money directly
         */

        /*
         *but can ask father to give money
         */
        m = getMoney();
        m--;
        setMoney(m);

        /*
         * Only son can access father's protected room key
         */
        room_key = 1;
    }
};

class Grandson_pub : public Son_pub
{
public:
    void test(void)
    {
        room_key = 1; //room_key is protected
        address = 2; //address is public
    }
};

class Grandson_pro : protected Son_pro
{
public:
    void test(void)
    {
        room_key = 1; //room_key is protected
        address = 2; //address is protected
    }
};

class Grandson_pri : private Son_pri
{
public:
    void test(void)
    {
        //room_key = 1; //error
        //address = 2; //error
    }
};

int
main(int argc, char **argv)
{
    Son_pub s_pub;
    Son_pro s_pro;
    Son_pri s_pri;

    s_pub.play_game();
    s_pro.play_game();
    s_pri.play_game();

    s_pub.it_skill();
    // s_pro.it_skill(); //error
    // s_pri.it_skill(); //error

    Grandson_pub gs_pub;
    Grandson_pro gs_pro;

    gs_pub.address = 2;
    //gs_pro.address = 2; //error

    return 0;
}