#ifndef ONIBUS_H
#define ONIBUS_H

#include <string>
using namespace std;

struct Onibus {
    string placa;
    int capacidade_max, lotacao_atual;

    Onibus(string placa , int capacidade_max);
    void subirPassageiros(int add_passageiros);
    void descerPassageiros(int menos_passageiros);
    void transferePassageiros(Onibus* outro_onibus, int n_passageiros);
    void imprimirEstado();
};


#endif 
