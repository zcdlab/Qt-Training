#include <cstdlib>
#include <iostream>
#include "Array.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    Array<int> ai(5);
    
    for(int i=0; i<ai.length(); i++)
    {
        ai[i] = i + 1;
    }
    
    for(int i=0; i<ai.length(); i++)
    {
        cout<<ai[i]<<endl;
    }
    
    Array<double> ad(10);
    
    for(int i=0; i<ad.length(); i++)
    {
        ad[i] = (i + 1) / 100.0;
    }
    
    for(int i=0; i<ad.length(); i++)
    {
        cout<<ad[i]<<endl;
    }
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
