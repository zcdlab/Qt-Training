#include <cstdlib>
#include <iostream>

using namespace std;

class Shape
{
public:
    virtual double area() = 0;
};

class Rectangle : public Shape
{
    double m_a;
    double m_b;
public:
    Rectangle(double a, double b)
    {
        m_a = a;
        m_b = b;
    }
    
    double area()
    {
        return m_a * m_b;
    }
};

class Circle : public Shape
{
    double m_r;
public:
    Circle(double r)
    {
        m_r = r;
    }
    
    double area()
    {
        return 3.14 * m_r * m_r;
    }
};

void area(Shape* s)
{
    cout<<s->area()<<endl;
}

int main(int argc, char *argv[])
{
    Rectangle rect(2, 3);
    Circle circle(4);
    
    area(&rect);
    area(&circle);
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
