#include <iostream>
#include <cmath>
using namespace std;
class Point 
{
private:
	double x;
	double y;
public:
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
	
	void mostra(void)
	{
		cout << "X:" << x << endl;
		cout << "Y:" << y << endl;
	}
	double distanceTo(Point p1,Point p2)
	{
		return sqrt(pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2));
	}	
};

int main()
{
	Point p1 = Point(1.0,1.0);
	Point* points = new Point[5];
	Point d;
	double a,b;
	for(int i =1; i<4; i++)
	{
		cout<<"Insira um valor para x:"<<endl;
		cin>>a;
		cout<<"Insira um valor para y:"<<endl;
		cin>>b;
		points[i] = Point(a,b);
	}
	points[0] = Point(6.0,1.0);
	points[4] = Point(3.0,4.0);
	
	for(int j=0; j<5; j++)
	{
		cout<<"Distância dos pontos para p1(1.0,1.0): "<<d.distanceTo(p1,points[j])<<endl;
	}
	delete[] points;
}
	
