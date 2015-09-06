#include <cstdlib>
#include <iostream>

using namespace std;

template<typename T>
class Test
{
public:
    T test(T v)
    {
        cout<<"T test(T v)"<<endl;
        cout<<"sizeof(T) = "<<sizeof(T)<<endl;
        
        return v;
    }
};

template<>
class Test<int>
{
public:
    int test(int v)
    {
        cout<<"int test(int v)"<<endl;
        cout<<"sizeof(int) = "<<sizeof(int)<<endl;
        
        return v;
    }
};

class MyTest : public Test<int>
{
};

int main(int argc, char *argv[])
{
    Test<int> t1;
    
    cout<<t1.test(1)<<endl;
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
