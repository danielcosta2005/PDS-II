#include "Sistema.hpp"
#include "Jogador.hpp"
#include <algorithm>

Sistema::Sistema(){
    arq_jogadores.open("jogadores.txt", std::fstream::in);
    num_jogadores_cadastrados = 0;
}

Sistema::~Sistema(){
    arq_jogadores.close();
}

std::vector<std::string> nomes_jogos = {"REVERSI", "LIGA4", "VELHA", "CAMPO MINADO"};

int Sistema::getNumJogadores() {
    return num_jogadores_cadastrados;
}

void Sistema::cadastrarJogador(std::string nome, std::string apelido){
    if (apelido.empty() || nome.empty()){
        std::cout << "ERRO: dados incorretos " << nome << " | " << apelido <<std::endl;
        return;
    }
    for (unsigned int i=0; i < vetor_jogadores.size(); i++){
        if (vetor_jogadores[i].getApelido() == apelido) {
            std::cout << "ERRO: o apelido \"" << apelido  << "\" ja esta em uso" << std::endl;
            return;
        }
    } 
    Jogador aux(nome, apelido);
    vetor_jogadores.push_back(aux);
    num_jogadores_cadastrados++;
    saveSistema();
    std::cout << "Jogador " << apelido << " cadastrado com sucesso" << std:: endl;
}

void Sistema::loadSistema(){

    std::string nome, apelido;
    int stat;

    while (true) {
        if (!std::getline(arq_jogadores, nome) || nome.empty()) break;

        if (!std::getline(arq_jogadores, apelido) || apelido.empty()) {
            std::cout << "ERRO: informacoes ausentes em jogadores.txt" << std::endl;
            break;
        } 

        cadastrarJogador(nome, apelido);
        Jogador* adicionado = &vetor_jogadores.back();

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 2; j++) {
                if (!(arq_jogadores >> stat)) {
                    std::cout << "ERRO: informacoes ausentes em jogadores.txt" << std::endl;
                    break;
                } 
                adicionado->setStat(i, j, stat);
            }
        }

        arq_jogadores.ignore(10000, '\n'); // ignora \n no final da leitura da ultima estatistica
    }
}

void Sistema::saveSistema(){
    std::ofstream output("jogadores.txt", std::ios::trunc);

    for (unsigned int k=0; k < vetor_jogadores.size(); k++){
        output << vetor_jogadores[k].getNome() << std::endl << vetor_jogadores[k].getApelido() << std::endl;
        for (int i=0; i<4; i++){
            for (int j=0; j<2; j++){
                output << vetor_jogadores[k].getStat(i, j);
                if(j == 0){
                    output << " ";
                }
            }
            output << std::endl;
        }
    }
    output.close();
}

void Sistema::printSistema(char parametro){
    if ((parametro == 'A') || (parametro == 'a')) {
        std::sort(vetor_jogadores.begin(), vetor_jogadores.end(), Jogador::comparaApelido);
    }
    else if ((parametro == 'N') || (parametro == 'n')) {
        std::sort(vetor_jogadores.begin(), vetor_jogadores.end(), Jogador::comparaNome);
    }
    for (unsigned int i=0; i < vetor_jogadores.size(); i++){
        std::cout << vetor_jogadores[i].getApelido() << " | " << vetor_jogadores[i].getNome() << std::endl;
        for (int j=0; j<4; j++){
            std::cout << nomes_jogos[j] << " - V: " << vetor_jogadores[i].getStat(j, 0) << " D: " << vetor_jogadores[i].getStat(j, 1) << std::endl;
        }
        std::cout << std::endl;
    }
}

void Sistema::printLeaderBoard(){
    for (int i=0; i<4; i++){
        if (i==0) std::sort(vetor_jogadores.begin(), vetor_jogadores.end(), Jogador::comparaStatsReversi);
        if (i==1) std::sort(vetor_jogadores.begin(), vetor_jogadores.end(), Jogador::comparaStatsLig4);
        if (i==2) std::sort(vetor_jogadores.begin(), vetor_jogadores.end(), Jogador::comparaStatsVelha);
        if (i==3) std::sort(vetor_jogadores.begin(), vetor_jogadores.end(), Jogador::comparaStatsCampo);
        for (unsigned int j = 0; j != vetor_jogadores.size(); j++){
            std::cout << nomes_jogos[i] << ":" << std::endl;
            std::cout << vetor_jogadores[j].getNome() << " [" << vetor_jogadores[j].getApelido() << "]:" << std::endl;
            std::cout << vetor_jogadores[j].getStat(i,0) << " VITÓRIAS" << std::endl;
            std::cout << vetor_jogadores[j].getStat(i,1) << " DERROTAS" << std::endl;
        }
    }
}

bool Sistema::jogadorRegistrado(std::string apelido) {
    for (auto& jogador : vetor_jogadores) {
        if (jogador.getApelido() == apelido) {
            return true;
        }
    }
    return false;
}

void Sistema::removerJogador(std::string apelido){
    if (jogadorRegistrado(apelido)) {
        for (unsigned int i = 0; i != vetor_jogadores.size(); i++){
            if (vetor_jogadores[i].getApelido() == apelido){
                vetor_jogadores.erase(vetor_jogadores.begin()+i);
                num_jogadores_cadastrados--;
                break;
            }
        }
    }
    else {
        std::cout << "ERRO: jogador \"" << apelido  << "\" inexistente" << std::endl;
        return;
    }
    std::cout << "Jogador " << apelido << " removido com sucesso" << std::endl;
    arq_jogadores.close();
    arq_jogadores.open("jogadores.txt", std::fstream::out);
    saveSistema();
    arq_jogadores.close();
    arq_jogadores.open("jogadores.txt", std::fstream::in | std::fstream::out | std::fstream::app);
}

Jogador* Sistema::getJogador(std::string apelido) {
    if (jogadorRegistrado(apelido)) {
        for (auto& jogador : vetor_jogadores) {
            if (jogador.getApelido() == apelido) 
                return &jogador;
        }
    }
    std::cout << "ERRO: jogador <" << apelido  << "> inexistente" << std::endl;
    return NULL;
}

