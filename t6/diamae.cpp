#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>

using namespace std;

class Figura {
public:
	virtual double calculaarea() const = 0;
	virtual double valor() const = 0;
	//string tipo() const { return tipo; }
};

class Circulo: public Figura
{
public:
	Circulo(double r) : raio(r) {};
	virtual double calculaarea() const {return pi * raio * raio;}
	virtual double valor() const {
		if(calculaarea() > 10)
		{
				return 0.50;
		}
		else if(calculaarea() > 5 && calculaarea() < 10)
		{
			return 0.30;
		}
		else
		{
			return 0.20;
		}
	}
private:
	double raio; //Raio do Circulo
	static const double pi;
};

const double Circulo::pi = 3.1415;

class Retangulo: public Figura
{
public:
	Retangulo(double b, double a) : base(b), altura(a) {}
	virtual double calculaarea() const { return base * altura; }
	virtual double valor() const {
		if(calculaarea() > 10)
		{
				return 0.50;
		}
		else if(calculaarea() > 5 && calculaarea() < 10)
		{
			return 0.30;
		}
		else
		{
			return 0.20;
		}
	}
private:
	double base, altura; //Valores de base e altura do retangulo
};

class Triangulo: public Figura
{
public:
	Triangulo(double b, double a) : base(b), altura(a) {}
	virtual double calculaarea() const { return (base * altura) / 2; }
	virtual double valor() const {
		if(calculaarea() > 10)
		{
				return 0.50;
		}
		else if(calculaarea() > 5 && calculaarea() < 10)
		{
			return 0.30;
		}
		else
		{
			return 0.20;
		}
	}
private:
	double base,altura; // Valores de base e altura do triangulo
};

bool cmparea (const Figura* f1,const Figura* f2) {
	return f1->calculaarea() < f2->calculaarea();
}

double randfrom(double min, double max)
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

int main()
{
	int quantia;
	int p,m,g = 0;
	double valor = 0.0;
	srand(time(NULL));
	vector<Figura*> fig;
	cout<<"Informe a quantidade de biscoitos desejada:"<<endl;
	cin>>quantia;

	for(auto x=0; x<quantia; x++)
	{
		double rgerado = randfrom(0.5,2.0);
		double xgerado = randfrom(1.0,4.0);
		double ygerado = randfrom(1.0,4.0);
		int ngerado = rand() % 3 + 1;

		switch (ngerado)
		{
			case 1:
			fig.push_back(new Circulo(rgerado));
			break;
			case 2:
			fig.push_back(new Retangulo(xgerado, ygerado));
			break;
			default:
			fig.push_back(new Triangulo(xgerado, ygerado));
			break;
		}
	}

sort(fig.begin(), fig.end(), cmparea);

	for (int i =0; i< fig.size(); i++)
	{
		valor+=fig[i]->valor();
		cout.precision(3);
		cout<<"Tamanho do biscoito em cm2:" << fig[i]->calculaarea()<<endl;
		cout.precision(2);
		cout<< "Valor: "<< fixed << fig[i]->valor()<<endl;
		if(fig[i]->calculaarea() > 10)
		{
			g++;
		}
		else if(fig[i]->calculaarea() <= 5)
		{
			p++;
		}
	}
	cout<<"Foram gerados:"<<endl;
	cout<<g<<" biscoitos grandes"<<endl;
	cout<<(fig.size()-g-p)<<" biscoitos medios"<<endl;
	cout<<p<<" biscoitos pequenos"<<endl;
	cout.precision(2);
	cout<<"Valor do pacote: R$"<< fixed << valor <<endl;
	return 0;
}

// Falta gerar os valores random para calcular a area;
// Falta os case pois o circulo precisa de 1 valor;
