#include "Jogador.hpp"

Jogador::Jogador(std::string nome, std::string apelido) : nome(nome), apelido(apelido) {
    for (int i=0; i<4; i++){
        for (int j=0; j<2; j++){
            this->stats[i][j] = 0;
        }
    }
}

std::string Jogador::getNome(){
    return this->nome;
}

void Jogador::setNome(std::string nome){
    this->nome = nome;
}

bool Jogador::comparaNome(Jogador & J1, Jogador & J2){
    std::string nome1 = J1.getNome();
    std::string nome2 = J2.getNome();
    unsigned int ultimo_index = std::min(nome1.size(), nome2.size());
    for (unsigned int i=0; i<ultimo_index; i++){
        if (nome1[i] < nome2[i]) return true;
        if (nome1[i] > nome2[i]) return false;
    }
    if (nome2.size() != ultimo_index) return true;
    else return false;
}

std::string Jogador::getApelido(){
    return this->apelido;
}

void Jogador::setApelido(std::string apelido){
    this->apelido = apelido;
}

bool Jogador::comparaApelido(Jogador & J1, Jogador & J2){
    std::string apelido1 = J1.getApelido();
    std::string apelido2 = J2.getApelido();
    unsigned int ultimo_index = std::min(apelido1.size(), apelido2.size());
    for (unsigned int i=0; i<ultimo_index; i++){
        if (apelido1[i] < apelido2[i]) return true;
        if (apelido1[i] > apelido2[i]) return false;
    }
    if (apelido2.size() != ultimo_index) return true;
    else return false;
}

int Jogador::getStat(int jogo, int stat){
    return stats[jogo][stat];
}

void Jogador::setStat(int jogo, int stat, int value){
    stats[jogo][stat] = value;
}

bool Jogador::comparaStatsReversi(Jogador & J1, Jogador & J2){ //o critério de colocação considerado será a diferença de vitórias e derrotas de cada jogador em cada jogo
    int desempenho_J1 = J1.getStat(0, 0) - J1.getStat(0, 1); 
    int desempenho_J2 = J2.getStat(0, 0) - J2.getStat(0, 1);
    if (desempenho_J1 <= desempenho_J2) return true;
    else return false;
}

bool Jogador::comparaStatsLig4(Jogador & J1, Jogador & J2){ 
    int desempenho_J1 = J1.getStat(1, 0) - J1.getStat(1, 1); 
    int desempenho_J2 = J2.getStat(1, 0) - J2.getStat(1, 1);
    if (desempenho_J1 <= desempenho_J2) return true;
    else return false;
}

bool Jogador::comparaStatsVelha(Jogador & J1, Jogador & J2){ 
    int desempenho_J1 = J1.getStat(2, 0) - J1.getStat(2, 1); 
    int desempenho_J2 = J2.getStat(2, 0) - J2.getStat(2, 1);
    if (desempenho_J1 >= desempenho_J2) return true;
    else return false;
}

bool Jogador::comparaStatsCampo(Jogador & J1, Jogador & J2){ 
    int desempenho_J1 = J1.getStat(3, 0) - J1.getStat(3, 1); 
    int desempenho_J2 = J2.getStat(3, 0) - J2.getStat(3, 1);
    if (desempenho_J1 >= desempenho_J2) return true;
    else return false;
}