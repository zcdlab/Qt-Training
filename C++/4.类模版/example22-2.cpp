#include <cstdlib>
#include <iostream>

using namespace std;

template<typename T1, typename T2>
class Test
{
public:
    void add(T1 a, T2 b)
    {
        cout<<(a + b)<<endl;
    }
};

/*
template<typename T>
class Test<T, T>
{
public:
    void add(T a, T b)
    {
        cout<<"add(T a, T b)"<<endl;
        cout<<static_cast<T>(a + b)<<endl;
    }
};
*/

template<typename T>
class Test<T, int>
{
public:
    void add(T a, int b)
    {
        cout<<"add(T a, int b)"<<endl;
        cout<<a + b<<endl;
    }
};

template<typename T1, typename T2>
class Test<T1*, T2*>
{
public:
    void add(T1* a, T2* b)
    {
        cout<<"add(T1* a, T2* b)"<<endl;
    }
};

int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;
    
    Test<double, int> t; // <T, int>
    Test<long, long> ti; // <T1, T2>
    Test<float, int> tt; // <T, int>
    Test<int*, int*> tp; // <T*, T*>
    
    t.add(10.0001, 8);
    ti.add(2, 3);
    tt.add(4, 5);
    tp.add(&i, &j);
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
