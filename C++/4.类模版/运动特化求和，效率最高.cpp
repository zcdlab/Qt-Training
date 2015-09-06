#include <cstdlib>
#include <iostream>

using namespace std;

template<int N>
class Sum
{
public:
    static const int VALUE = Sum<N - 1>::VALUE + N;
};

template<>
class Sum<1>
{
public:
    static const int VALUE = 1;
};

int main(int argc, char *argv[])
{
    cout<<Sum<10>::VALUE<<endl;
    cout<<Sum<100>::VALUE<<endl;
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
