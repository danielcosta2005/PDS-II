#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip> 
#include "aluno.hpp"

using namespace std;

int main() {
    vector<Aluno> alunos;

    while (true) {
        string nome; 
        getline(cin, nome);
        if (nome == "END") break;

        int matricula;
        cin >> matricula;

        vector<int> notas;
        int nota;
        while (true) {
            cin>> nota;
            if (nota==-1){
                break;
            }
            notas.push_back(nota);
        }
        cin.ignore();

        Aluno aluno(nome, matricula, notas);
        alunos.push_back(aluno);
    }

    sort(alunos.begin(), alunos.end(), [](const Aluno& a, const Aluno& b) {
        return a.getNome() < b.getNome();
    });

    for (auto aluno : alunos) {
        cout << aluno.getMatricula() << " " << aluno.getNome() << " ";
        for (int nota : aluno.getNotas()) {
            cout << nota << " ";
        }
        cout << endl;

        cout << fixed << setprecision(2);
        cout << aluno.mediaNotas() << " " << aluno.maiorNota() << " " << aluno.menorNota() << endl;
    }

    return 0;
}
