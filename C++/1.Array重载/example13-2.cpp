#include <stdio.h>
#include "Array.h"

int main()
{
    Array a1(10);
    Array a2(0);
    Array a3(0);
    
    if( a1 != a2 )
    {
        printf("a1 != a2\n");
    }
    
    for(int i=0; i<a1.length(); i++)
    {
        a1[i] = i + 1;
    }
    
    for(int i=0; i<a1.length(); i++)
    {
        printf("Element %d: %d\n", i, a1[i]);
    }
    
    a3 = a2 = a1;
    
    if( a1 == a2 )
    {
        printf("a1 == a2\n");
    }
    
    for(int i=0; i<a2.length(); i++)
    {
        printf("Element %d: %d\n", i, a2[i]);
    }
    
    printf("Press any key to continue...");
    getchar();
    return 0;
}
