#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>
using namespace std;

class Aluno {
private:
    string nome;
    int num_matricula;
    vector <int> notas;

public:
    Aluno (string nome, int num_matricula, vector <int> notas);
    
    float mediaNotas ();
    int maiorNota ();
    int menorNota (); 

    string getNome() const;
    int getMatricula() const;
    vector<int> getNotas() const;
};


#endif 