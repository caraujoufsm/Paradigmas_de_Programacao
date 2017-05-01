#include <iostream>
#include <cmath>

const double PI = 3.14159;

class Point 
{
public:
	double x;
	double y;
	Point()
	{
		x = y = 0.0;
	}
	Point(double a, double b)
	{
		x = a;
		y = b;
	}
	void move(double dx, double dy)
	{
		x += dx;
		y += dy;
	}
};

class Circle {
private:
   Point centro;
   double r;
public:
   Circle() {
      centro.x = centro.y = r = 0.0;
      std::cout << "O circulo foi criado com sucesso" <<std::endl;
   }
   Circle(double a, double b, double c)
   {
	   centro.x = a;
	   centro.y = b;
	   r = c;
   }
   double getX()
   {
	   return centro.x;
   }
   double getY()
   {
	   return centro.y;
   }
   double area() {
      return PI * r * r;
   }
   double distanceTo(Circle* c)
   {
	  return sqrt(pow((c->centro.x - centro.x),2) + pow((c->centro.y - centro.y),2));
   }	
   void setRadius(double radius)
   {
		r = radius;
   }
};

int main() {
   Circle c1;
   Circle* c2 = new Circle(1.0,1.0,4.0);
   Circle* c3 = new Circle(6.0,1.0,4.0);
   //Circle circs[10];
   //c1.x = 0.5;
   std::cout << c3->area() << std::endl;
   std::cout << c1.area() << std::endl;
   c1.setRadius(5.0);
   std::cout << c1.area() << std::endl;
   std::cout << c2->area() << std::endl;
   c2->setRadius(5.0);
   std::cout << c2->area() << std::endl;
   std::cout << c3->distanceTo(c2)<<std::endl;
   delete c2;
   delete c3;
}
