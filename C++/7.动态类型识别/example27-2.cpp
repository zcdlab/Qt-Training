#include <cstdlib>
#include <iostream>

using namespace std;

class Parent
{
public:
    virtual ~Parent()
    {
    }
};

class Child : public Parent
{
public:
    int add(int a, int b)
    {
        return a + b;
    }
};

class NewChild : public Parent 
{
};

void test(Parent* p)
{
    Child* c = dynamic_cast<Child*>(p);
    
    if( c != NULL )
    {
        cout<<"Dynamic Type: "<<"Child"<<endl;
        cout<<"add: "<<c->add(2, 3)<<endl;
    }
    else
    {
        if( dynamic_cast<NewChild*>(p) != NULL )
        {
            cout<<"Dynamic Type: "<<"NewChild"<<endl;
        }
        else
        {
            cout<<"Dynamic Type: "<<"Parent"<<endl;
        }
    }
}

int main(int argc, char *argv[])
{
    Parent parent;
    Child child;
    NewChild nc;
    
    test(&parent);
    test(&child);
    test(&nc);
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
