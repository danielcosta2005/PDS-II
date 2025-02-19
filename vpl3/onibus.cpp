#include "Onibus.hpp"
#include <iostream>
#include <string>

using namespace std;

Onibus::Onibus(string placa_, int capacidade_max_) {
    placa = placa_;
    capacidade_max = capacidade_max_;
    lotacao_atual = 0;
}

void Onibus::subirPassageiros(int add_passageiros) {
    if (lotacao_atual + add_passageiros <= capacidade_max) {
        lotacao_atual += add_passageiros;
        cout << "passageiros subiram com sucesso" << endl;
    } else {
        cout << "ERRO : onibus lotado" << endl;
    }
}

void Onibus::descerPassageiros(int menos_passageiros) {
    if (lotacao_atual - menos_passageiros >= 0) {
        lotacao_atual -= menos_passageiros;
        cout << "passageiros desceram com sucesso" << endl;
    } else {
        cout << "ERRO : faltam passageiros" << endl;
    }
}

void Onibus::transferePassageiros(Onibus* outro_onibus, int n_passageiros) {
    if (outro_onibus != nullptr &&
        lotacao_atual >= n_passageiros &&
        outro_onibus->lotacao_atual + n_passageiros <= outro_onibus->capacidade_max) {
        
        lotacao_atual -= n_passageiros;
        outro_onibus->lotacao_atual += n_passageiros;
        cout << "transferencia de passageiros efetuada" << endl;
    } else {
        cout << "ERRO : transferencia cancelada" << endl;
    }
}

void Onibus::imprimirEstado() {
    cout << placa << " (" << lotacao_atual << "/" << capacidade_max << ")" << endl;
}
