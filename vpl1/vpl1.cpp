#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> // Necessário para std::find

using namespace std;

// Função para processar a palavra de tentativa e comparar com a chave
string processarTentativa(const string& chave, const string& tentativa, vector<char>& letras_erradas) {
    string resultado = "";
    for (int i = 0; i < 5; ++i) {
        if (tentativa[i] == chave[i]) {
            resultado += toupper(tentativa[i]); // Letra correta no lugar certo
        } else if (chave.find(tentativa[i]) != string::npos) {
            resultado += tolower(tentativa[i]); // Letra presente, mas no lugar errado
        } else {
            // Verifica se a letra já está no vetor de letras erradas
            if (find(letras_erradas.begin(), letras_erradas.end(), tentativa[i]) == letras_erradas.end()) {
                letras_erradas.push_back(tentativa[i]); // Adiciona à lista de letras erradas se não estiver lá
            }
            resultado += '*'; // Letra não está presente
        }
    }
    return resultado;
}

int main() {
    ifstream arquivo("palavras.txt");
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    // Leitura do número de palavras
    int n;
    arquivo >> n;
    vector<string> palavras(n);

    // Leitura das palavras
    for (int i = 0; i < n; ++i) {
        arquivo >> palavras[i];
    }
    arquivo.close();

    // Entrada para escolher a palavra-chave
    int escolha;
    cin >> escolha;

    string chave = palavras[escolha - 1];
    vector<char> letras_erradas;

    // Loop para as tentativas
    for (int tentativas = 0; tentativas < 5; ++tentativas) {
        string tentativa;
        cin >> tentativa;

        // Processa a tentativa e exibe o resultado
        string resultado = processarTentativa(chave, tentativa, letras_erradas);
        cout << resultado;

        // Exibe as letras erradas sem duplicatas
        cout << " (";
        for (char c : letras_erradas) {
            cout << c;
        }
        cout << ")" << endl;

        // Verifica se o jogador ganhou
        if (tentativa == chave) {
            cout << "GANHOU!" << endl;
            return 0;
        }
    }

    // Se não acertou após 5 tentativas
    cout << "PERDEU! " << chave << endl;
    return 0;
}
