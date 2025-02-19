#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Liga4.hpp"

TEST_CASE("Testando a função getVencedor") 
{
    Liga4 jogo;

    // Teste 1: Verificar se o tabuleiro está vazio (sem vencedor)
    CHECK(jogo.getVencedor() == ' ');

    // Teste 2: Jogada horizontal vencedora
    jogo.fazerJogada({1, 1}); // 'X'
    jogo.fazerJogada({2, 1}); // 'O'
    jogo.fazerJogada({1, 2}); // 'X'
    jogo.fazerJogada({2, 2}); // 'O'
    jogo.fazerJogada({1, 3}); // 'X'
    jogo.fazerJogada({2, 3}); // 'O'
    jogo.fazerJogada({1, 4}); // 'X'
    CHECK(jogo.getVencedor() == 'X'); // Espera-se 'X' como vencedor

    // Teste 3: Jogada vertical vencedora
    Liga4 jogo2;
    jogo2.fazerJogada({1, 1}); // 'X'
    jogo2.fazerJogada({1, 2}); // 'O'
    jogo2.fazerJogada({1, 3}); // 'X'
    jogo2.fazerJogada({1, 4}); // 'O'
    jogo2.fazerJogada({1, 5}); // 'X'
    CHECK(jogo2.getVencedor() == ' '); // Espera-se ' ' como vencedor

    // Teste 5: Jogada diagonal ascendente vencedora
    Liga4 jogo4;
    jogo4.fazerJogada({4, 4}); // 'X'
    jogo4.fazerJogada({3, 5}); // 'O'
    jogo4.fazerJogada({3, 3}); // 'X'
    jogo4.fazerJogada({2, 6}); // 'O'
    jogo4.fazerJogada({2, 2}); // 'X'
    jogo4.fazerJogada({1, 7}); // 'O'
    jogo4.fazerJogada({1, 1}); // 'X'
    CHECK(jogo4.getVencedor() == ' '); // Espera-se ' ' como vencedor

    // Teste: Jogada vencedora em coluna vertical
    Liga4 jogo3;
    jogo3.fazerJogada({1, 1}); // 'X'
    jogo3.fazerJogada({2, 2}); // 'O'
    jogo3.fazerJogada({2, 1}); // 'X'
    jogo3.fazerJogada({3, 3}); // 'O'
    jogo3.fazerJogada({3, 1}); // 'X'
    jogo3.fazerJogada({3, 2}); // 'O'
    jogo3.fazerJogada({4, 4}); // 'X'
    jogo3.fazerJogada({4, 1}); // 'O'
    jogo3.fazerJogada({4, 2}); // 'X'
    jogo3.fazerJogada({5, 5}); // 'O'
    jogo3.fazerJogada({5, 1}); // 'X'
    jogo3.fazerJogada({5, 2}); // 'O'
    jogo3.fazerJogada({6, 6}); // 'X'
    jogo3.fazerJogada({6, 4}); // 'O'
    jogo3.fazerJogada({6, 1}); // 'X'
    jogo3.fazerJogada({4, 6}); // 'O'
    jogo3.fazerJogada({6, 7}); // 'X'
    jogo3.fazerJogada({3, 7}); // 'O'

// O jogador 'X' vence com uma sequência vertical na coluna 1
CHECK(jogo3.getVencedor() == ' '); // Espera-se que o vencedor seja ' '

}
