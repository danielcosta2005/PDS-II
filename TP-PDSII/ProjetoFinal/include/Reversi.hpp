#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "Jogo.hpp"
#include <vector>
#include <map>

using namespace std;

class Reversi : public Jogo{
private:
    bool isTurnoX;

public:
    Reversi();

    vector<pair<int,int>> getPossiveisJogadas();

    vector<pair<int, int>> getPecasConvertidas(pair<int,int> jogada);

    bool estaNoTabuleiro(pair<int,int> jogada);

    map <char, int> countPieces() const; 

    char getVencedor() override;

    bool isEstadoFinal() override;

    char getTurno() override;

    void trocaTurno();

    void fazerJogada(pair<int, int> jogada) override;

    bool isJogadaValida(pair<int,int> jogada) override;

    vector <vector<char>> getTabuleiroPossivel();

    void printTabuleiroPossivel();

    void printTabuleiro() override;
};

#endif