#include <stdio.h>
#include <iostream>
using namespace std;

class X
{
    int x;
public:
    int get() const {return x;};
    int set(int v) {x = v; return 0;}
    int permute() {return x = x * 100;}
    X():x(66){}
    X(int v):x(v){}
};

class Z
{
    int z;
public:
    int get() const {return z;};
    int set(int v) {z = v; return 0;}

    Z():z(88){}
    Z(int v):z(v){}
};

class Y : public X
{
    Z z;
    int x;
public:
    //int get() const {return x;}
    int set(int v) {x = v; X::set(v); return 0;}
    int change() {
        x = permute();
        return x;
    }
    int getz() const {return z.get();}
    Y():x(99), X(55), z(99){}
    //Y():x(99){X::x = 99; z.z =9; } // error, is private
};

class CBase
{
    static int s;
public:
    static int geta() {return s; };
    static int geta(int a){return a;}
    int getb() const {return s;}
};

int CBase::s=19999;

class CTest : public CBase
{
    int a;
public:
    static int geta() {return CBase::geta()+1;}
};

class CTest2 : private CBase
{
public:
    int getc(){return geta();}
};

int main()
{
    CTest ct;
    cout << ct.geta() << endl;

    Y y;
    //y.set (6);
    cout << y.get() << endl;
    cout << y.getz() << endl;
    cout << y.change() << endl;

    return 0;
}