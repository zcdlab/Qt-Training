#include <cstdlib>
#include <iostream>

using namespace std;

int test(int i)
{
    if( i == 1 )
    {
        throw -1;
    }
    
    if( i == 2 )
    {
        throw "ERROR";
    }
    
    if( i == 3 )
    {
        throw 0.5;
    }
    
    if( i == 4 )
    {
        throw 'd';
    }
    
    return i;
}

int main(int argc, char *argv[])
{
    for(int i=0; i<5; i++)
    {
        try
        {
            cout<<test(i)<<endl;
        }
        catch(int e)
        {
            cout<<"Int: "<<e<<endl;
        }
        catch(const char* e)
        {
            cout<<"const char*: "<<e<<endl;
        }
        catch(double e)
        {
            cout<<"double: "<<e<<endl;
        }
    }
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
