#include <cstdlib>
#include <iostream>

using namespace std;

template<typename T, int N>
void func()
{
    T array[N] = {0};
    
    for(int i = 0; i < N; i++)
    {
        array[i] = i + 1;
        
        cout<<array[i]<<" ";
    }
    
    cout<<endl;
}

int main(int argc, char *argv[])
{
    func<int, 5>();
    func<float, 10>();
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
