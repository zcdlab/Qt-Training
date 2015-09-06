#include <cstdlib>
#include <iostream>

using namespace std;

int test(int i)
{
    if( (6 <= i) && (i <= 9) )
    {
        throw i;
    }
    
    return i;
}

int main(int argc, char *argv[])
{
    try
    {
        for(int i=0; i<10; i++)
        {
            try
            {
                cout<<test(i)<<endl;
            }
            catch(...)
            {   
                cout<<"Exception Occur"<<endl;
                
                throw;
            }
        }
    }
    catch(int e)
    {
        cout<<"Catch: "<<e<<endl;
    }
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
