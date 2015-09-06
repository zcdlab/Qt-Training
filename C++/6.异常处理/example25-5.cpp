#include <cstdlib>
#include <iostream>

using namespace std;

void MemSet(void* dest, unsigned int length, unsigned char v)
{
    if( dest == NULL )
    {
        throw -1;
    }
    
    if( length < 4 )
    {
        throw -2;
    }
    
    if( (v < 0) || (v > 9) )
    {
        throw -3;
    }
    
    unsigned char* p = (unsigned char*)dest;
    
    for(int i=0; i<length; i++)
    {
        p[i] = v;
    }
}

int main(int argc, char *argv[])
{
    int ai[5];
    double ad[4];
    char ac[3];
    
    try
    {
        MemSet(ai, sizeof(ai), 0);
        MemSet(ad, sizeof(ad), 1);
        MemSet(ac, sizeof(ac), 2);
    }
    catch(int e)
    {
        cout<<e<<endl;
    }
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
