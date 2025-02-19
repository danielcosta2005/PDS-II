#ifndef VELHA_H
#define VELHA_H

#include "Jogo.hpp"

class JogoDaVelha : public Jogo {
    private:
        char turno;
    public:
        JogoDaVelha();
        char getVencedor() override;
        bool isEstadoFinal() override;
        void alternaTurno();
        char getTurno() override;
        bool isJogadaValida(std::pair<int,int> jogada) override;
        void fazerJogada(std::pair<int, int> jogada) override;
        void printTabuleiro();
};

#endif