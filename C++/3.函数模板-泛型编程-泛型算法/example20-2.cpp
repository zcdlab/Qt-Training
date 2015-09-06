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

template<typename T>
void SelectSort(T array[], int length)
{
    for(int i=0; i<length; i++)
    {
        T min = array[i];
        int index = i;
        
        for(int j=i+1; j<length; j++)
        {
            if( array[j] < min )
            {
                min = array[j];
                index = j;
            }
        }
        
        Swap(array[i], array[index]);
    }
}

int main(int argc, char *argv[])
{
    int array[] = {3, 2, 5, 3 , 4};
    
    SelectSort<int>(array, 5);
    
    for(int i=0; i<5; i++)
    {
        cout<<array[i]<<endl;
    }
    
    char ca[] = {'b', 'c', 'a', 'e', 'd', 'f'};
    
    SelectSort(ca, 6);
    
    for(int i=0; i<6; i++)
    {
        cout<<ca[i]<<endl;
    }
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
