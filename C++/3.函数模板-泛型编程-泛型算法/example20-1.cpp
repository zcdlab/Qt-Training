#include <cstdlib>
#include <iostream>

using namespace std;

template<typename T>
void Swap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

int main(int argc, char *argv[])
{
    int a = 1;
    int b = 2;
    
    Swap(a, b);
    
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    
    float fa = 3;
    float fb = 4;
    
    Swap<float>(fa, fb);
    
    cout<<"fa = "<<fa<<endl;
    cout<<"fb = "<<fb<<endl;
    
    char ca = 'a';
    char cb = 'b';
    
    Swap(ca, cb);
    
    cout<<"ca = "<<ca<<endl;
    cout<<"cb = "<<cb<<endl;
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
