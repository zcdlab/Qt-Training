#include <cstdlib>
#include <iostream>

using namespace std;

class Parent
{
public:
    virtual void func()
    {
        cout<<"void func()"<<endl;
    }
    
    virtual void func(int i)
    {
        cout<<"void func(int i)"<<endl;
    }
    
    virtual void func(int i, int j)
    {
        cout<<"void func(int i, int j)"<<endl;
    }
};

class Child : public Parent
{
public:
    void func(int i, int j)
    {
        cout<<"void func(int i, int j)"<<" "<<i + j<<endl;
    }
    
    void func(int i, int j, int k)
    {
        cout<<"void func(int i, int j, int k)"<<" "<<i + j + k<<endl;
    }
};

void run(Parent* p)
{
    p->func(1, 2);
}

int main(int argc, char *argv[])
{
    Parent p;
    
    p.func();
    p.func(1);
    p.func(1, 2);
    
    Child c;
    
    c.func(1, 2);
    
    run(&p);
    run(&c);
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
