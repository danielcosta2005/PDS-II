#ifndef JOGO_H
#define JOGO_H

#include <vector>

using namespace std;

class Jogo {
protected:
    const int M;
    const int N;
    vector<vector<char>> tabuleiro;

public:
    /* Construtor */
    Jogo (int M, int N); 

    // Retorna qual jogador venceu 'X' 'O' ou '' (nenhum)
    virtual char getVencedor() = 0;

    // Retorna verdadeiro se o jogo terminou
    virtual bool isEstadoFinal() = 0;

    // Retorna qual jogador tem o turno 'X' ou 'O'
    virtual char getTurno() = 0;

    // Recebe um par de coordenadas (i, j) e, se for uma jogada valida, atualiza o tabuleiro conforme o jogador que tem o turno
    virtual void fazerJogada(pair<int, int> jogada) = 0;

    /* Retorna verdadeiro se a jogada é valida
    checar:
        movimento dentro do tabuleiro
        movimento em uma casa já preenchida
        movimento contraria alguma regra especifica do jogo
     */
    virtual bool isJogadaValida(pair<int,int> jogada) = 0;

    // Printa o tabuleiro, tem uma implementação padrao (ver PDF do TP), mas pode ser sobrecarregada
    // a depender do jogo
    virtual void printTabuleiro();
};


#endif
