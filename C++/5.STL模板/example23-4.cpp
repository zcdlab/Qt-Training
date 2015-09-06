#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void current(int& v)
{
    cout<<v<<endl;
}

void print(vector<int>& vec)
{
    cout<<"Elements in vector:"<<endl;
    
    for_each(vec.begin(), vec.end(), current);
}

int compare(const int& a, const int& b)
{
    return a < b;
}

int main(int argc, char *argv[])
{
    vector<int> v(10);
    
    for(int i=9; i>=0; i--)
    {
        v[i] = 9 - i;
    }
        
    print(v);
    
    sort(v.begin(), v.end(), compare);
    
    print(v);
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
