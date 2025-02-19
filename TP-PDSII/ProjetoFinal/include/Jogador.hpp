#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>

class Jogador {
    private:
        std::string nome;
        std::string apelido;
        int stats[4][2];
    public:
        Jogador(std::string nome, std::string apelido);
        std::string getNome();
        static bool comparaNome(Jogador & J1, Jogador & J2);
        void setNome(std::string nome);
        std::string getApelido();
        void setApelido(std::string apelido);
        static bool comparaApelido(Jogador & J1, Jogador & J2);
        int getStat(int jogo, int stat);
        void setStat(int jogo, int stat, int value);
        //stat: 0 = vitórias | 1 = derrotas
        //jogo: 0 = Reversi | 1 = Lig4 | 2 = Velha | 3 = Campo Minado
        static bool comparaStatsReversi(Jogador &J1, Jogador & J2);
        static bool comparaStatsLig4(Jogador &J1, Jogador & J2);
        static bool comparaStatsVelha(Jogador &J1, Jogador & J2);
        static bool comparaStatsCampo(Jogador &J1, Jogador & J2);
};

#endif