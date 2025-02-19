#ifndef SISTEMA_H
#define SISTEMA_H

#include "Jogador.hpp"
#include <iostream>
#include <vector>
#include <fstream>

class Sistema {
    private:
        std::vector<Jogador> vetor_jogadores;
        std::fstream arq_jogadores;
        int num_jogadores_cadastrados;
    public:
        Sistema();
        ~Sistema();
        void loadSistema();
        void saveSistema();
        int getNumJogadores();
        void cadastrarJogador(std::string nome, std::string apelido);
        void printSistema(char parametro);
        void printLeaderBoard();
        void removerJogador(std::string apelido);
        bool jogadorRegistrado(std::string apelido);
        Jogador* getJogador(std::string apelido);
};

#endif