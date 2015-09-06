#include <cstdlib>
#include <iostream>

using namespace std;

#define DIV_ZERO_ERROR -1

double Div(double a, double b)
{
    if( (-0.000000001 < b) && (b < 0.000000001) )
    {
        throw DIV_ZERO_ERROR;
    }
    
    return a / b;
}

int main(int argc, char *argv[])
{
    try
    {
        cout<<Div(3, 1.1)<<endl;
        cout<<Div(1, 0)<<endl;
        cout<<Div(1, 2)<<endl;
    }
    catch(int error)
    {
        cout<<"Exception: "<<endl;
        cout<<error<<endl;
    }

    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
