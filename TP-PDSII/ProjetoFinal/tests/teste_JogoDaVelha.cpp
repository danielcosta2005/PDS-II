#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/JogoDaVelha.hpp"

//Testando o método getVencedor:
TEST_CASE("Não há vencedor"){
    JogoDaVelha jogo;
    
    jogo.fazerJogada({1,1});
    jogo.fazerJogada({1,2});
    jogo.fazerJogada({3,1});
    jogo.fazerJogada({2,1});
    jogo.fazerJogada({2,2});
    jogo.fazerJogada({3,3});
    jogo.fazerJogada({3,2});
    jogo.fazerJogada({1,3});
    jogo.fazerJogada({2,3});
    CHECK(jogo.getVencedor() == ' ');
}

TEST_CASE("Vitória por linha"){
    JogoDaVelha jogo;
    
    jogo.fazerJogada({1,1});
    jogo.fazerJogada({2,1});
    jogo.fazerJogada({1,2});
    jogo.fazerJogada({2,2});
    jogo.fazerJogada({1,3});
    CHECK(jogo.getVencedor() == 'X');
}

TEST_CASE("Vitória por coluna"){
    JogoDaVelha jogo;
    
    jogo.fazerJogada({2,2});
    jogo.fazerJogada({1,1});
    jogo.fazerJogada({1,3});
    jogo.fazerJogada({3,1});
    jogo.fazerJogada({3,2});
    jogo.fazerJogada({2,1});
    CHECK(jogo.getVencedor() == 'O');
}

TEST_CASE("Vitória pela diagonal principal"){
    JogoDaVelha jogo;
    
    jogo.fazerJogada({1,1});
    jogo.fazerJogada({3,1});
    jogo.fazerJogada({3,3});
    jogo.fazerJogada({1,2});
    jogo.fazerJogada({2,2});
    CHECK(jogo.getVencedor() == 'X');
}

TEST_CASE("Vitória pela diagonal secundária"){
    JogoDaVelha jogo;
    
    jogo.fazerJogada({1,1});
    jogo.fazerJogada({3,1});
    jogo.fazerJogada({3,3});
    jogo.fazerJogada({2,2});
    jogo.fazerJogada({1,2});
    jogo.fazerJogada({1,3});
    CHECK(jogo.getVencedor() == 'O');
}

//Testando o método isJogadaValida:

TEST_CASE("Jogadas válidas"){
    JogoDaVelha jogo;
    CHECK(jogo.isJogadaValida({1,1}));
    CHECK(jogo.isJogadaValida({1,3}));
    CHECK(jogo.isJogadaValida({2,2}));
    CHECK(jogo.isJogadaValida({3,1}));
    CHECK(jogo.isJogadaValida({1,3}));
}

TEST_CASE("Jogadas inválidas"){
    JogoDaVelha jogo;
    CHECK(!jogo.isJogadaValida({1,4}));
    CHECK(!jogo.isJogadaValida({-1,1}));
    CHECK(!jogo.isJogadaValida({0,-3}));
    CHECK(!jogo.isJogadaValida({8,100}));
    CHECK(!jogo.isJogadaValida({'a','b'}));
}