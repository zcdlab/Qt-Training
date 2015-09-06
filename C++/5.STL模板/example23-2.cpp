#include <cstdlib>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void StackUsage()
{
    cout<<"Stack Usage"<<endl;
    
    stack<double> s;
    
    for(int i=0; i<5; i++)
    {
        s.push(i/100.0);
    }
    
    cout<<"Elements in s:"<<endl;
    
    while( !s.empty() )
    {
        double v = s.top();
        
        s.pop();
        
        cout<<v<<endl;
    }
}

void QueueUsage()
{
    cout<<"Queue Usage"<<endl;
    
    queue<int> q;
    
    for(int i=0; i<5; i++)
    {
        q.push(i + 1);
    }
    
    cout<<"Elements in q:"<<endl;
    
    while( !q.empty() )
    {
        int v = q.front();
        
        q.pop();
        
        cout<<v<<endl;
    }
    
}

int main(int argc, char *argv[])
{
    StackUsage();
    QueueUsage();
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
