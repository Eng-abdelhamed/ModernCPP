#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <ostream>

class complex{
    private:
        int real;
        int img;
    public:
    // delegating Constructor
        complex() : complex(0,0){}
    // Initialization List 
        complex(int R , int I) :real{R},img{I}{}

    // Copy constructor
        complex(complex &r): real{r.real} , img{r.img} {}
     // c = c1 + c2

     friend complex operator+(complex c1 , complex c2);
     friend complex operator-(complex c1, complex c2);
     friend complex operator*(complex c1, complex c2);
     friend std::ostream &operator<<(std::ostream &o ,complex c1);

         void add(complex c)
     {
        this->img += c.img;
        this->real += c.real;
     }

     void display()
     {
        std::cout << "The Real      : " << this->real << std::endl;
        std::cout << "The Imaginary : " << this->img  << std::endl;
     }
};

complex operator+(complex c1, complex c2)
{
    complex t;
    t.real = c1.real + c2.real;
    t.img = c1.img + c2.img;
    return t;
}

complex operator-(complex c1, complex c2)
{
    complex t;
    t.real = c1.real - c2.real;
    t.img = c1.img - c2.img;
    return t;
}

complex operator*(complex c1, complex c2)
{
    complex t;
    t.real = c1.real * c2.real;
    t.img = c1.img * c2.img;
    return t;
}
std::ostream &operator<<(std::ostream &o, complex c1)
{
    o << c1.real << "+" << c1.img << "I" << std::endl ;
    return o;
}
int main()
{
    complex c1(1000,100) , c2(100,10);
    // c1.addition(c2);
   
    complex c = c1 + c2;
    complex b = c1 - c2;
    complex t = c1 * c2;

    std::cout<<c1;
    return 0;
}