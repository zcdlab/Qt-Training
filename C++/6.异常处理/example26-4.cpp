#include <cstdlib>
#include <iostream>

using namespace std;

class Test
{
    int* p;
public:
    Test()
    {
        cout<<"Test()"<<endl;
        
        p = new int[5];
        
        throw 10;
    }
    
    ~Test()
    {
        cout<<"~Test()"<<endl;
        delete[] p;
    }
};

int main(int argc, char *argv[])
{
    try
    {
        Test t;
    }
    catch(int e)
    {
        cout<<"Catch: "<<e<<endl;
    }
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
