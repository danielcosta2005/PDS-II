#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

int main() {
    string nomeArquivo;
    cin >> nomeArquivo;

    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    vector<string> linhas;
    string linha;
    while (getline(arquivo, linha)) {
        linhas.push_back(linha); 
    }

    arquivo.close();

    vector<string> palavras;

    for (auto l : linhas) {
        string palavra;
        for (char c : l) {
            if (isalnum(c)) { 
                palavra += tolower(c); 
            } else if (!palavra.empty()) { 
                palavras.push_back(palavra); 
                palavra.clear(); 
            }
        }
        if (!palavra.empty()) { // Adiciona a última palavra se tiver 
            palavras.push_back(palavra);
        }
    }

    map<string, int> frequencia;
    for (auto p : palavras) {
        frequencia[p]++;
    }

for (auto par : frequencia) {
    cout << par.first << " " << par.second << endl;
}

    return 0;
}
