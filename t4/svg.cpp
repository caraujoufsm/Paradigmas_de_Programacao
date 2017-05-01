#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
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
public:
   Point centro;
   double r;

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
   double distanceTo(Circle* c1, Circle* c2)
   {
	  double dist;
	  dist = sqrt(pow((c1->centro.x - c2->centro.x),2) + (pow((c1->centro.y - c2->centro.y),2)));
	  return dist;
   }	
   void setRadius(double radius)
   {
		r = radius;
   }
};

using namespace std;

//Cria um numero double randomico
double randNumber(){
    return ((double) rand() / (RAND_MAX)) + rand()%255;
}
void iniciaSvgDoc(ofstream& entrada){
    auto n = 800;
    entrada << "<!DOCTYPE html><html><body>";
    entrada << "<svg  xmlns='http://www.w3.org/2000/svg' height='" << n << "' width='" << n << "'>" << endl;
}
void imprimeCircle(Circle* circulo,ofstream& entrada){
    entrada << "<circle cx='" << circulo->centro.x << "' cy='" << circulo->centro.y;
    entrada << "' r='"<< circulo->r << "' style='stroke: rgb("<< (int)randNumber() << ","<< (int)randNumber() << ","<< (int)randNumber() << ");'";
    entrada << " stroke-width='3' fill='blue' />" << endl;
}
void imprimeLine(Circle* circulo1, Circle* circulo2, ofstream& entrada){
    entrada << "<line x1='"<< circulo1->centro.x << "' y1='" << circulo1->centro.y;
    entrada << "' x2='"<< circulo2->centro.x << "' y2='" << circulo2->centro.y<< "'";
    entrada << " style='stroke:rgb("<< (int)randNumber() << ","<< (int)randNumber() << ","<< (int)randNumber() << "); stroke-width:2' />";
}
void terminaSvgDoc(ofstream& entrada){
    entrada << "</svg>" << endl;
    entrada << "</body></html>";
}
//Adiciona valores randomicos para o x e y dos circulos e deixa valor fixo para o raio
void circleGeneretor(Circle* circulo,int n){
    for(auto i = 0; i < n; i++){
        circulo[i] = Circle(randNumber(),randNumber(),50);
    }
}

int main()
{
    int n;
    // inicializa random
    srand (time(NULL));
    //Abre arquivo para salvar os dados
    ofstream entrada {"circulo.svg"};
    //Verificação de arquivo abriu ou não
    if(entrada.is_open() == false){
        cout << "Nao foi possivel abrir arquivo!" << endl;
        exit(-1);
    }
    //Recebe quantos circulos deseja
    cout << "Quantos circulos deseja?" << endl;
    cin >> n;
    //Adiciona as tags iniciais no arquivo
    iniciaSvgDoc(entrada);
    //Cria um vetor - n circulos
    Circle* circulo = new Circle[n];
    //Gerador de circulos
    circleGeneretor(circulo, n);
    //Envia pro arquivo os dados dos circulos
    for(auto i = 0; i < n; i++){
        imprimeCircle(&circulo[i], entrada);
        //Gera linha até um a menos que o total de circulos
        if(i+1<n){
            imprimeLine(&circulo[i], &circulo[i+1], entrada);
        }
    }
    //Adiciona as tags finais no arquivo
    terminaSvgDoc(entrada);
    //Destroi os circulos
    delete[] circulo;
    return(0);
}
