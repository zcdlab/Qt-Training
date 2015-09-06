#include <cstdlib>
#include <iostream>
#include <stdexcept>

using namespace std;

int func1(int i)
{
    try
    {
        if( i > 0 )
        {
            return i;
        }
        else
        {
            throw "error";
        }
    }
    catch(...)
    {
        return -1;
    }
}

int func2(int i) try
{
    if( i > 0 )
    {
        return i;
    }
    else
    {
        throw "error";
    }
}
catch(...)
{
    return -1;
}

int main(int argc, char *argv[])
{
    for(int i=0; i<5; i++)
    {
        cout<<func2(i)<<endl;
    }
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
