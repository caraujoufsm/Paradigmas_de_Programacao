#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

class Score {
private:
	string nome;
	string descr;
	int pontos;
public:
	Score(string nome, string descr, int pontos) {
		this->nome = nome;
		this->descr = descr;
		this->pontos = pontos;
	}
	string getNome() {
		return nome;
	}
	string getDescr() {
		return descr;
	}
	int getPontos() {
		return pontos;
	}
	bool operator<(Score& s) {
      return this->pontos > s.pontos;
   }

};
	bool compareatvepts(Score& s1, Score& s2) {
		return s1.getDescr() > s2.getDescr() && s1.getPontos() > s2.getPontos();
	}
	
	bool comparenome(Score& s1, Score& s2) {
		return s1.getNome() > s2.getNome();
	}

class Total {
private:
		Score Jogador;
		int tot;
public:
	int gettot() {
		return tot;
	}
	string getNome() {
		return Jogador.getNome();
	}
	string getDescr() {
		return Jogador.getDescr();
	}
	int getPontos() {
		return Jogador.getPontos();
	}
};

int main() {

   ifstream data("pontos.csv");
   
   string line;
   string cell[3];
   vector<Score> s;
   int contador = 1;
   
   while (getline(data, line)) {
      stringstream linestream(line);
      getline(linestream, cell[0], ',');
      getline(linestream, cell[1], ',');
      getline(linestream, cell[2], ',');
      s.push_back(Score(cell[0], cell[1], stoi(cell[2])));
   }
    
   
   // ordena com operador '>' definido na classe (por pontos)
   sort(s.begin(), s.end());
   
   vector<Score>::iterator it;
   vector<Score>::iterator it2;
   for (it = s.begin(); it < s.end(); it++){
      cout<< it->getNome() << " ";
	  cout<< it->getDescr() << " ";
	  cout<< it->getPontos() << " "<< endl;
   }
	// ordena por atividade
	sort(s.begin(), s.end(), compareatvepts);
	
	for (it = s.begin(),it2 = s.begin()+1; it < s.end(); it++,contador++){
		cout <<contador<<":"<< it->getNome() <<":"<< it->getDescr() <<":"<< it->getPontos()<<endl;
	}
}
