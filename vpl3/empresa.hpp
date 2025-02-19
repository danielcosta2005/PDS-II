#ifndef EMPRESA_H
#define EMPRESA_H

#include "onibus.hpp"
#include <string>

using namespace std;

struct Empresa {
    Onibus *onibus[20];
    int total_onibus;

    Empresa();

    Onibus* adicionarOnibus(string placa, int capacidade_max);
    Onibus* buscaOnibus(string placa);
    void imprimirEstadoGeral();

};



#endif