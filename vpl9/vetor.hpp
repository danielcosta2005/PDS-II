#ifndef VETOR_HPP
#define VETOR_HPP

#include <iostream>

template <typename T>
class Vetor {
private:
    T* elementos;
    int tamanhoMaximo;
    int tamanhoAtual;

public:
    explicit Vetor(int n) 
        : tamanhoMaximo(n), tamanhoAtual(0) {
        elementos = new T[tamanhoMaximo];
    }

    Vetor(const Vetor& outro)
        : tamanhoMaximo(outro.tamanhoMaximo), tamanhoAtual(outro.tamanhoAtual) {
        elementos = new T[tamanhoMaximo];
        for (int i = 0; i < tamanhoAtual; ++i) {
            elementos[i] = outro.elementos[i];
        }
    }

    ~Vetor() {
        delete[] elementos;
    }

    void SetElemento(int i, T x) {
        if (i >= 0 && i < tamanhoMaximo) {
            elementos[i] = x;
            if (i >= tamanhoAtual) {
                tamanhoAtual = i + 1;
            }
        }
    }

    T GetElemento(int i) const {
        if (i >= 0 && i < tamanhoAtual) {
            return elementos[i];
        }
        return T();
    }

    void AdicionaElemento(T x) {
        if (tamanhoAtual < tamanhoMaximo) {
            elementos[tamanhoAtual++] = x;
        }
    }

    void Imprime() const {
        for (int i = 0; i < tamanhoAtual; ++i) {
            std::cout << elementos[i];
            if (i < tamanhoAtual - 1) {
                std::cout << " ";
            } else {
                std::cout << std::endl;
            }
        }
    }
};

#endif
