#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> vi(10);
    
    cout<<"vi size: "<<vi.size()<<endl;
    
    for(int i=0; i<5; i++)
    {
        vi[i] = i + 1;
    }
    
    vi.resize(5);
    
    cout<<"Elements in vi:"<<endl;
    
    for(int i=0; i<vi.size(); i++)
    {
        cout<<vi[i]<<endl;
    }
    
    vector<int> vin;
    
    vin = vi;
    
    vi.resize(0);
    
    cout<<"Elements in vin:"<<endl;
    
    for(int i=0; i<vin.size(); i++)
    {
        cout<<vin[i]<<endl;
    }
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
