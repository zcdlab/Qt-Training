#include <cstdlib>
#include <iostream>

using namespace std;

int test(int i)
{
    if( i == 1 )
    {
        throw "p";
    }
    
    if( i == 2 )
    {
        throw 0.5;
    }
    
    if( i == 3 )
    {
        throw 3;
    }
    
    if( i == 4 )
    {
        throw 'c';
    }
    
    return i;
}

int main(int argc, char *argv[])
{
    for(int i=0; i<10; i++)
    {
        try
        {
            cout<<test(i)<<endl;
        }
        catch(char e)
        {   
            cout<<"Exception: "<<e<<endl;
        }
        catch(...)
        {
            cout<<"Exception Occur"<<endl;
        }
    }
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
