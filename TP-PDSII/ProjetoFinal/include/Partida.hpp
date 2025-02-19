#ifndef PARTIDA_HPP
#define PARTIDA_HPP

#include "Jogo.hpp"
#include "Jogador.hpp"
#include "Reversi.hpp"
#include "Liga4.hpp"
#include "JogoDaVelha.hpp"
#include "CampoMinado.hpp"
#include "Sistema.hpp"

#include <map>

using namespace std;

class Partida {
private:
    Jogador* jogador1;
    Jogador* jogador2;
    Jogador* jogador_atual;

    map<char, Jogador*> pecas_jogadores;
    Jogo* jogo;

    void executarReversi();
    void executarLiga4();
    void executarVelha();
    void executarMinado();

public:
    Partida(Jogador* j1, Jogador* j2, Jogo* jogo);
    void sortearJogadorInicial();
    void atribuirPecas();

    // modelo => r = reversi, v = jogo da velha, l = liga4
    void iniciarPartida(char modelo);
    void finalizarPartida(char modelo);

    static bool isJogoValido(string modelo);
};

#endif