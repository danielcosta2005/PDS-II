#ifndef LIGA4_H
#define LIGA4_H

#include "Jogo.hpp"

using namespace std;

class Liga4 : public Jogo {
private:
    int contador_jogadas = 0;
    char turno_atual = 'X';
public:
    Liga4();
    char getVencedor() override;
    bool isEstadoFinal() override;
    char getTurno() override;
    void setTurno();
    void fazerJogada(pair<int, int> jogada) override;
    bool isJogadaValida(pair<int, int> jogada) override;
    void printTabuleiro() override;
    ~Liga4();
};

#endif
