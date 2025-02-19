#include "CampoMinado.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

CampoMinado::CampoMinado(int linhas, int colunas, int numBombas) 
    :Jogo(colunas, linhas),
     turno_atual('X'),
     perdedor(' '),
     numBombas(numBombas),
     jogoAtivo(true),
     count_jogadas(0),
     jogadasRestantes(linhas*colunas-numBombas),
     tabuleiro_oculto(linhas, vector<char>(colunas, ' ')),
     tabuleiro_visivel(linhas, vector<char>(colunas, ' '))
     {
        colocarBombas();
        atualizarTabuleiro();
        revelarCasasIniciais(6);
     }

void CampoMinado::colocarBombas() 
{
    srand(time(NULL)); 
    int bombasColocadas = 0;

    while (bombasColocadas < numBombas) 
    {
        int linha = rand() % this->M;  // Gera índice aleatório para linha
        int coluna = rand() % this->N;  // Gera índice aleatório para coluna

        if (tabuleiro_oculto[linha][coluna] != 'B') 
        {
            tabuleiro_oculto[linha][coluna] = 'B';
            bombasColocadas++;
        }
    }
}


void CampoMinado::atualizarTabuleiro() 
{
    for (int i = 0; i < this->M; i++) 
    {
        for (int j = 0; j < this->N; j++) 
        {
            if (tabuleiro_oculto[i][j] == 'B') continue;
            int bombasVizinhas = contarBombasAdjacentes(i, j);
            tabuleiro_oculto[i][j] = bombasVizinhas > 0 ? '0' + bombasVizinhas : 'O';
        }
    }
}
    
int CampoMinado::contarBombasAdjacentes(int linha, int coluna) const 
{
    int contador = 0;
    for (int i = -1; i <= 1; i++) 
    {
        for (int j = -1; j <= 1; j++) 
        {
            int novaLinha = linha + i;
            int novaColuna = coluna + j;
            if (novaLinha >= 0 && novaLinha < this->M &&
                novaColuna >= 0 && novaColuna < this->N &&
                tabuleiro_oculto[novaLinha][novaColuna] == 'B') 
            {
                contador++;
            }
        }
    }
    return contador;
}

void CampoMinado::colocarSinalizador(pair<int, int> jogada) 
{
    int linha = jogada.first - 1;
    int coluna = jogada.second - 1;

    if (tabuleiro_visivel[linha][coluna] == ' ') 
    {
        tabuleiro_visivel[linha][coluna] = 'F'; 
    } 
    else if (tabuleiro_visivel[linha][coluna] == 'F') 
    {
        tabuleiro_visivel[linha][coluna] = ' ';
    } 
    else 
    {
        cout << "Não é possível colocar um sinalizador nesta célula." << endl;
    }
}



char CampoMinado::getVencedor(){
    if(perdedor == ' ')  return ' ';//empate
    else if(perdedor == 'O') return 'X';
    else if(perdedor == 'X') return 'O';
    else { cerr << "Perdedor está com um valor inválido: (" << perdedor << "). Corrigir erro!!!" << endl; return ' ';}
}

bool CampoMinado::isEstadoFinal(){
    if(jogadasRestantes <= 0){
        jogoAtivo = false;
        return true;
    }
        else if(jogoAtivo == false) return true;
        else return false;
}

void CampoMinado::setTurno(){//troca de turno a cada jogada válida
    if(turno_atual == 'X') turno_atual = 'O';
        else if(turno_atual == 'O') turno_atual = 'X';
        else cerr << "Erro Inesperado: turno_atual possui um valor inválido (" << turno_atual << " )." << endl;
}

char CampoMinado::getTurno(){
    return turno_atual;
}


void CampoMinado::fazerJogada(pair<int, int> jogada)
{
    int coluna, linha;
    linha = jogada.first-1;
    coluna = jogada.second-1;
    
        tabuleiro_visivel[linha][coluna] = tabuleiro_oculto[linha][coluna];
        jogadasRestantes -= 1;
        count_jogadas += 1;
        if(tabuleiro_oculto[linha][coluna] == 'B')
        {   
            //o jogo só irá ser encerrado se um jogador encontrar uma primeira bomba e os dois jogadores tiverem a mesma quantidade de jogadas;
            if(count_jogadas%2==0) jogoAtivo = false;
            else{
            system("cls");
            printTabuleiro();
            cout << endl << "Atencao! Voce encontrou uma bomba, se o proximo jogador tambem encontrar sera empate." << endl << endl;
            cout << endl << "Pressione qualquer tecla para continuar..."<< std::flush;
            cin.get();

            }
        //Inicialmente perdedor = ' ', se um jogador perder na rodada anterior, o atributo perdedor vai ser setado como 'X' ou 'O'
            //Caso na próxima jogada o outro jogador perca, será considerado empate
        }
        
        if(perdedor == 'O' || perdedor == 'X')
            {   
                if(tabuleiro_oculto[linha][coluna] == 'B') perdedor = ' '; //define o empate
                jogoAtivo = false;
                return;
            }

        if(tabuleiro_oculto[linha][coluna] == 'B') perdedor = turno_atual;

        setTurno();
}

bool CampoMinado::isJogadaValida(pair<int, int> jogada){
    int coluna, linha;
    linha = jogada.first-1;
    coluna = jogada.second-1;
    
    if(coluna < this->M && coluna >=0 && linha < this->N && linha >= 0)
    {
        if(tabuleiro_visivel[linha][coluna] == ' ' || tabuleiro_visivel[linha][coluna] == 'F')
            return true;
            else
            {
                cout << "A coordenada ja esta revelada! Por favor escolha outra." << endl;
                return false;
            }
    }
    else
    {
        cout << "Coordenada invalida! Por favor Escolha uma coluna de 1 a " << M << " e linha de 1 a " << N << "." << endl;
        return false;
    }
}

void CampoMinado::printTabuleiro() {
    // Imprime os índices das colunas
    cout << "    ";  // Espaço para os índices das linhas
    for (int j = 0; j < M; j++) {
        if(j<9)
            cout << " " << j+1 << "  ";  // Índice da coluna abaixo do numero 10
        else{
            cout << j+1 << "  "; //Índice da coluna acima do numero 9
        }
    }
    cout << endl;

    // Imprime o tabuleiro linha por linha, com os índices das linhas
    for (int i = 0; i < M; i++) {
        if(i<9)
            cout << " " << i+1 << " ";  // Índice da linha abaixo do numero 10
        else
            cout << i+1 << " ";  // Índice da linha acima do numero 9
        for (int j = 0; j < N; j++) {
            cout << "| " << tabuleiro_visivel[i][j] << " ";
        }
        cout << "|" << endl << endl;
    }
}

void CampoMinado::revelarTabuleiro() {
    // Imprime os índices das colunas
    cout << "    ";  // Espaço para os índices das linhas
    for (int j = 0; j < M; j++) {
        if(j<9)
            cout << " " << j+1 << "  ";  // Índice da coluna abaixo do numero 10
        else{
            cout << j+1 << "  "; //Índice da coluna acima do numero 9
        }
    }
    cout << endl;

    // Imprime o tabuleiro linha por linha, com os índices das linhas
    for (int i = 0; i < M; i++) {
        if(i<9)
            cout << " " << i+1 << " ";  // Índice da linha abaixo do numero 10
        else
            cout << i+1 << " ";  // Índice da linha acima do numero 9
            
        for (int j = 0; j < N; j++) {
            cout << "| " << tabuleiro_oculto[i][j] << " ";
        }
        cout << "|" << endl << endl;
    }
}

void CampoMinado::revelarCasasIniciais(int numCasasParaRevelar)
{
    srand(time(NULL)); 
    int casasReveladas = 0;

    while (casasReveladas < numCasasParaRevelar) 
    {
        int linha = rand() % this->M;  // Gera índice aleatório para linha
        int coluna = rand() % this->N;  // Gera índice aleatório para coluna

        if (tabuleiro_oculto[linha][coluna] != 'B' && tabuleiro_visivel[linha][coluna] == ' ') 
        {
            tabuleiro_visivel[linha][coluna] = tabuleiro_oculto[linha][coluna];
            casasReveladas++;
        }
    }
}

CampoMinado::~CampoMinado() {
    // Destrutor
}

