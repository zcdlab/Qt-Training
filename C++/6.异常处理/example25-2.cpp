#include <cstdlib>
#include <iostream>

using namespace std;

int MemSet(void* dest, unsigned int length, unsigned char v)
{
    if( dest == NULL )
    {
        return -1;
    }
    
    if( length < 4 )
    {
        return -2;
    }
    
    if( (v < 0) || (v > 9) )
    {
        return -3;
    }
    
    unsigned char* p = (unsigned char*)dest;
    
    for(int i=0; i<length; i++)
    {
        p[i] = v;
    }
    
    return 0;
}

int main(int argc, char *argv[])
{
    int ai[5];
    double ad[4];
    char ac[3];
    int ret;
    
    ret = MemSet(ai, sizeof(ai), 0);
    
    if( ret == 0 )
    {
    }
    else if( ret == -1 )
    {
    }
    else if( ret == -2 )
    {
    }
    else if( ret == -3 )
    {
    }
    
    ret = MemSet(ad, sizeof(ad), 1);
    
    if( ret == 0 )
    {
    }
    else if( ret == -1 )
    {
    }
    else if( ret == -2 )
    {
    }
    else if( ret == -3 )
    {
    }
    
    ret = MemSet(ac, sizeof(ac), 2);
    
    if( ret == 0 )
    {
    }
    else if( ret == -1 )
    {
    }
    else if( ret == -2 )
    {
    }
    else if( ret == -3 )
    {
    }
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}