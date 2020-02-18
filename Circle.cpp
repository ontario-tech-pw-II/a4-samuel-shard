#include <iostream>
#include <cmath>
const double pi = 3.141592653589793;
using namespace std;

class Circle {
  private:  
    int x,y;      // center of circle
    double r;    // radius of circle

  public:
    //constructor with optional default values 
    Circle(int =0,int=0, double =1.0);
    //destructor
    ~Circle(){cout << "Circle deleted.\n";}
    void print() const;
    double area() const;

    double operator+(const Circle &) const;

    Circle & operator++();
    Circle operator++(int);

  friend ostream & operator<<(ostream &out, const Circle &);
  friend istream & operator>>(istream &in, Circle &);
};

Circle::Circle(int x,int y, double z)
{
  cout << "Circle created.\n";
  // Initialize the object here
  this->x = x; //set x of circle to given x
  this->y = y;
  this->r = z;
}

double Circle::area() const {
  // Return the area of a circle
  return pi*pow(r,2);  
}

double Circle::operator+(const Circle & c) const
{
   // + Return the area of two circles
   return pi*pow(r,2) + pi*pow(c.r,2);  

}

Circle & Circle::operator++()
{
  // Prefix (++a): increment the radius by 1 and return new radius
  r++;
  return *this; //*this->r or just this*? Why is pointer needed?
}

Circle Circle::operator++(int)
{
  // Postfix (a++): increment the radius by 1 and return original radius
  Circle temp = *this;
  r++;
  return temp;
}

ostream & operator<<(ostream &out, const Circle &c)
{
  // print a circle in the out stream (the format is the same as print())
  out << "Circle =(x: "<< c.x << ", y: " << c.y << ", r: " << c.r << ")" << endl;
  return out;
}

istream & operator>>(istream &in, Circle &c)
{
  // Read a circle information from the in stream and create new circle object
  int tmp_x,tmp_y;      // center of circle
  double tmp_r;    // radius of circle
  cout << "Enter radius: ";
  in >> tmp_r;
  cout << "Enter x position: ";
  in >> tmp_x;
  cout << "Enter y position: ";
  in >> tmp_y;
  c = Circle(tmp_x,tmp_y,tmp_r);
  return in; //Allows for cascading
}


void Circle::print() const
{
  cout << "Circle =(x: "<< x << ", y: " << y << ", r: " << r << ")" << endl;
}



int main()
{
  Circle a;
  Circle b(2,3,3.0);

  a.print();
  b.print();
  int x;
  
  cout << "The area a + b is: " << a+b << endl;
  ++a;
  a.print();

  cout << "Return value of a++: " << a++;
  a.print();

  cout << a;

  cin >> a >> b;
  cout <<a << b;

  return 0;
}