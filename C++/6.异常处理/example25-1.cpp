#include <cstdlib>
#include <iostream>

using namespace std;

double Div(double a, double b, bool* valid)
{
    *valid = true;
    
    if( (-0.000000001 < b) && (b < 0.000000001) )
    {
        *valid = false;
        
        return 0;
    }
    
    return a / b;
}

double Add(double a, double b)
{
    return a + b;
}

double Minus(double a, double b)
{
    return a - b;
}

double Multi(double a, double b)
{
    return a * b;
}

int main(int argc, char *argv[])
{
    bool v = false;
    
    cout<<Div(Add(3, 3), Minus(2, 2), &v)<<endl;
    cout<<v<<endl;
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
