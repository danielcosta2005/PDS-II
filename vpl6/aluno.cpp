#include <iostream>
#include <vector>
#include <algorithm>
#include "aluno.hpp"

using namespace std;

Aluno::Aluno(string nome, int num_matricula, vector<int>notas) : nome(nome), num_matricula(num_matricula), notas(notas){}

float Aluno::mediaNotas(){
    if (notas.empty()){
        return 0.0f;
    }

    int soma=0;
    for (auto nota:notas){
        soma+=nota;
    }

    return static_cast<float>(soma)/notas.size();
}

int Aluno::maiorNota(){
    if (notas.empty()){
        return 0;
    }

     auto it=max_element(notas.begin(), notas.end());
     return *it; 
}

int Aluno::menorNota(){
    if (notas.empty()){
        return 0;
    }

     auto it=min_element(notas.begin(), notas.end());
     return *it; 
}

string Aluno::getNome() const {
    return nome;
}

int Aluno::getMatricula() const{
    return num_matricula;
}

vector<int> Aluno::getNotas() const{
    return notas;
}
