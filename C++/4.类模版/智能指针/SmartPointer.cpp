#include <cstdlib>
#include <iostream>
#include "SmartPointer.hpp"

using namespace std;

class Test
{
public:
    int i;
    void print()
    {
        cout<<i<<endl;
    }
};

int main(int argc, char *argv[])
{
    SmartPointer<int> pi = new int(5);
    SmartPointer<Test> pt = new Test();
    
    cout<<*pi<<endl;
    
    *pi = 10;
    
    cout<<*pi<<endl;
    
    pt->i = 20;
    pt->print();
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
