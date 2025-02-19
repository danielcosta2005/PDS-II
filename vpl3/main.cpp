#include "empresa.hpp"
#include "onibus.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
    Empresa empresa;
    char comando;
    string placa, placa_destino;
    int capacidade_max, num_passageiros;

    while (cin >> comando) {
        if (comando == 'C') {
            // Comando para cadastrar um novo ônibus
            cin >> placa >> capacidade_max;
            empresa.adicionarOnibus(placa, capacidade_max);

        } else if (comando == 'S') {
            // Comando para subir passageiros
            cin >> placa >> num_passageiros;
            Onibus* onibus = empresa.buscaOnibus(placa);
            if (onibus != nullptr) {
                onibus->subirPassageiros(num_passageiros);
            } else {
                cout << "ERRO : onibus inexistente" << endl;
            }

        } else if (comando == 'D') {
            // Comando para descer passageiros
            cin >> placa >> num_passageiros;
            Onibus* onibus = empresa.buscaOnibus(placa);
            if (onibus != nullptr) {
                onibus->descerPassageiros(num_passageiros);
            } else {
                cout << "ERRO : onibus inexistente" << endl;
            }

        } else if (comando == 'T') {
            // Comando para transferir passageiros entre ônibus
            cin >> placa >> placa_destino >> num_passageiros;
            Onibus* onibus_origem = empresa.buscaOnibus(placa);
            Onibus* onibus_destino = empresa.buscaOnibus(placa_destino);

            if (onibus_origem != nullptr && onibus_destino != nullptr) {
                onibus_origem->transferePassageiros(onibus_destino, num_passageiros);
            } else {
                cout << "ERRO : onibus inexistente" << endl;
            }

        } else if (comando == 'I') {
            // Comando para imprimir o estado de todos os ônibus
            empresa.imprimirEstadoGeral();

        } else if (comando == 'F') {
            // Comando para finalizar o programa
            break;
        }
    }
    
    return 0;
}
