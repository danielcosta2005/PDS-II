#include "empresa.hpp"
#include <iostream>
using namespace std;

Empresa::Empresa() {
    total_onibus = 0;
    for (int i = 0; i < 20; i++) {
        onibus[i] = nullptr;
    }
}

Onibus* Empresa::adicionarOnibus(string placa, int capacidade_max) {
    if (buscaOnibus(placa) != nullptr) {
        cout << "ERRO : onibus repetido" << endl;
        return nullptr;
    }
    if (total_onibus < 20) {
        Onibus* novo_onibus = new Onibus(placa, capacidade_max);
        onibus[total_onibus] = novo_onibus;  
        total_onibus++;
        cout << "novo onibus cadastrado" << endl;
        return novo_onibus;  
    } else {
        cout << "ERRO : limite de onibus atingido" << endl;
        return nullptr;  
    }
}

Onibus* Empresa::buscaOnibus(string placa) {
    for (int i = 0; i < total_onibus; i++) {
        if (onibus[i] != nullptr && onibus[i]->placa == placa) {
            return onibus[i];
        }
    }
    return nullptr;  
}

void Empresa::imprimirEstadoGeral() {
    for (int i = 0; i < total_onibus; i++) {
        if (onibus[i] != nullptr) {
            onibus[i]->imprimirEstado();  
        }
    }
}
