#include <cstdlib>
#include <iostream>
#include <stdexcept>

using namespace std;

class divide_by_zero : public logic_error
{
public:
    divide_by_zero(const char* s) : logic_error(s)
    {
    }
};

double Div(double a, double b)
{
    if( (-0.00000001 < b) && ( b < 0.00000001) )
    {
        throw divide_by_zero("Divide by zero...");
    }
    
    return  a / b;
}

int main(int argc, char *argv[])
{
    try
    {
        cout<<Div(1, 0)<<endl;
    }
    catch(exception& e)
    {
        cout<<e.what()<<endl;
    }
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
