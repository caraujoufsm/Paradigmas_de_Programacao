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

class Total {
	

int main() {

   ifstream data("pontos.csv");
   
   string line;
   string cell[3];
   vector<Score> s;
   
   while (getline(data, line)) {
      stringstream linestream(line);
      getline(linestream, cell[0], ',');
      getline(linestream, cell[1], ',');
      getline(linestream, cell[2], ',');
      s.push_back(Score(cell[0], cell[1], stoi(cell[2])));
   }
   
   // ordena com operador '>' definido na classe (por idade)
   sort(s.begin(), s.end());
   
   vector<Score>::iterator it;
   for (it = s.begin(); it < s.end(); it++){
      cout<< it->getNome() << " ";
	  cout<< it->getDescr() << " ";
	  cout<< it->getPontos() << " "<< endl;
   }
}
