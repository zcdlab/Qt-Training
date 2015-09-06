#include <cstdlib>
#include <iostream>
#include <list>

using namespace std;

int main(int argc, char *argv[])
{
    list<double> l;
    
    cout<<"l size: "<<l.size()<<endl;
    
    for(int i=0; i<5; i++)
    {
        l.push_back((i + 1) / 1000.0);
    }
    
    cout<<"l size: "<<l.size()<<endl;
    
    list<double>::iterator current = l.begin(); 
    
    cout<<"Elements in l:"<<endl;
    
    while( current != l.end() )
    {
        cout<<*current<<endl;
        
        current++;
    }
    
    current = l.begin();
    
    current++;
    current++;
    
    l.insert(current, 0.1);
    
    cout<<"Elements in l:"<<endl;
    
    for(list<double>::iterator p = l.begin(); p != l.end(); p++)
    {
        cout<<*p<<endl;
    }
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
