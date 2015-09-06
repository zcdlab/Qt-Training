#include <cstdlib>
#include <iostream>
#include <typeinfo>

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
    if( typeid(*p) == typeid(Child) )
    {
        Child* c = dynamic_cast<Child*>(p);
    
        cout<<"Dynamic Type: "<<"Child"<<endl;
        cout<<"add: "<<c->add(2, 3)<<endl;
    }
    else if( typeid(*p) == typeid(NewChild) )
    {
        cout<<"Dynamic Type: "<<"NewChild"<<endl;
    }
    else if( typeid(*p) == typeid(Parent) )
    {
        cout<<"Dynamic Type: "<<"Parent"<<endl;
    }

}

int main(int argc, char *argv[])
{
    Parent parent;
    Child child;
    NewChild nc;
    int index;
    char ch;
    
    const type_info& tp = typeid(parent);
    const type_info& tc = typeid(child);
    const type_info& tn = typeid(nc);
    const type_info& ti = typeid(index);
    const type_info& tch = typeid(ch);
    
    cout<<tp.name()<<endl;
    cout<<tc.name()<<endl;
    cout<<tn.name()<<endl;
    cout<<ti.name()<<endl;
    cout<<tch.name()<<endl;
    
    test(&parent);
    test(&child);
    test(&nc);
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
