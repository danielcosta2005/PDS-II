#include "Jogo.hpp"
#include <iostream>

using namespace std;

Jogo::Jogo (int M, int N) :
    M(M),
    N(N),
    tabuleiro(M, vector<char>(N, ' ')) {}


void Jogo::printTabuleiro() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << "| " << tabuleiro[i][j]  << " ";
        }
        cout << "|" << endl << endl;
    }
};
