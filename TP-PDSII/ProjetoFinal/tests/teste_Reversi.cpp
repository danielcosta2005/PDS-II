#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/Reversi.hpp"


TEST_CASE("Testando estaNoTabuleiro") {
    Reversi jogo;

    CHECK(jogo.estaNoTabuleiro({0, 0}) == true);
    CHECK(jogo.estaNoTabuleiro({7, 7}) == true);
    CHECK(jogo.estaNoTabuleiro({-1, 0}) == false);
    CHECK(jogo.estaNoTabuleiro({8, 8}) == false);
}

TEST_CASE("Testar getPecasConvertidas") {
    Reversi jogo;

    SUBCASE("Jogada válida - conversão horizontal para direita") {
        jogo.fazerJogada({2, 3}); // X joga em (2,3)
        vector<pair<int, int>> convertidas = jogo.getPecasConvertidas({2, 3});
        CHECK(convertidas.size() == 1);
        CHECK(convertidas[0] == make_pair(3, 3)); // Converte a peça em (3,3)
    }

    SUBCASE("Jogada válida - conversão horizontal para esquerda") {
        jogo.fazerJogada({5, 4}); // X joga em (5,4)
        vector<pair<int, int>> convertidas = jogo.getPecasConvertidas({5, 4});
        CHECK(convertidas.size() == 1);
        CHECK(convertidas[0] == make_pair(4, 4)); // Converte a peça em (4,4)
    }

    SUBCASE("Jogada válida - conversão vertical para cima") {
        jogo.fazerJogada({3, 2}); // X joga em (3,2)
        vector<pair<int, int>> convertidas = jogo.getPecasConvertidas({3, 2});
        CHECK(convertidas.size() == 1);
        CHECK(convertidas[0] == make_pair(3, 3)); // Converte a peça em (3,3)
    }

    SUBCASE("Jogada válida - conversão vertical para baixo") {
        jogo.fazerJogada({4, 5}); // X joga em (4,5)
        vector<pair<int, int>> convertidas = jogo.getPecasConvertidas({4, 5});
        CHECK(convertidas.size() == 1);
        CHECK(convertidas[0] == make_pair(4, 4)); // Converte a peça em (4,4)
    }

    SUBCASE("Jogada válida - conversão diagonal (noroeste)") {
        jogo.fazerJogada({2, 2}); // X joga em (2,2)
        vector<pair<int, int>> convertidas = jogo.getPecasConvertidas({2, 2});
        CHECK(convertidas.size() == 1);
        CHECK(convertidas[0] == make_pair(3, 3)); // Converte a peça em (3,3)
    }

    SUBCASE("Jogada válida - conversão diagonal (sudoeste)") {
        jogo.fazerJogada({5, 5}); // X joga em (5,5)
        vector<pair<int, int>> convertidas = jogo.getPecasConvertidas({5, 5});
        CHECK(convertidas.size() == 1);
        CHECK(convertidas[0] == make_pair(4, 4)); // Converte a peça em (4,4)
    }

    SUBCASE("Jogada válida - conversão diagonal (nordeste)") {
        jogo.fazerJogada({2, 4}); // X joga em (2,4)
        vector<pair<int, int>> convertidas = jogo.getPecasConvertidas({2, 4});
        CHECK(convertidas.size() == 1);
        CHECK(convertidas[0] == make_pair(3, 4)); // Converte a peça em (3,4)
    }

    SUBCASE("Jogada válida - conversão diagonal (sudeste)") {
        jogo.fazerJogada({5, 2}); // X joga em (5,2)
        vector<pair<int, int>> convertidas = jogo.getPecasConvertidas({5, 2});
        CHECK(convertidas.size() == 1);
        CHECK(convertidas[0] == make_pair(4, 3)); // Converte a peça em (4,3)
    }

    SUBCASE("Jogada inválida - fora do tabuleiro") {
        vector<pair<int, int>> convertidas = jogo.getPecasConvertidas({-1, -1});
        CHECK(convertidas.empty());

        convertidas = jogo.getPecasConvertidas({8, 8});
        CHECK(convertidas.empty());
    }

    SUBCASE("Jogada inválida - posição ocupada") {
        vector<pair<int, int>> convertidas = jogo.getPecasConvertidas({3, 3});
        CHECK(convertidas.empty());
    }

    SUBCASE("Jogada inválida - sem peças para converter") {
        vector<pair<int, int>> convertidas = jogo.getPecasConvertidas({0, 0});
        CHECK(convertidas.empty());
    }
}

TEST_CASE("Testar fazerJogada") {
    Reversi jogo;

    SUBCASE("Jogada válida - deve alterar tabuleiro corretamente") {
        CHECK(jogo.isJogadaValida({2, 3}));
        jogo.fazerJogada({2, 3});
        CHECK(jogo.getTabuleiroPossivel()[2][3] == 'X'); // Jogador X
        CHECK(jogo.getTabuleiroPossivel()[3][3] == 'X'); // Peça convertida
    }

    SUBCASE("Jogada inválida - não deve alterar tabuleiro") {
        jogo.fazerJogada({0, 0});
        CHECK(jogo.getTabuleiroPossivel()[0][0] != 'X');
        CHECK(jogo.getTabuleiroPossivel()[0][0] != 'O');
    }

    SUBCASE("Troca de turno após jogada válida") {
        CHECK(jogo.getTurno() == 'X');
        jogo.fazerJogada({2, 3});
        CHECK(jogo.getTurno() == 'O'); // Deve ser 'O' após a jogada de 'X'
    }
}

TEST_CASE("Testar getPecasConvertidas") {
    Reversi jogo;

    SUBCASE("Jogada válida - deve converter peças corretamente") {
        vector<pair<int, int>> convertidas = jogo.getPecasConvertidas({2, 3});
        CHECK(convertidas.size() == 1);
        CHECK(convertidas[0] == make_pair(3, 3)); // Peça convertida
    }

    SUBCASE("Jogada inválida - não deve converter peças") {
        vector<pair<int, int>> convertidas = jogo.getPecasConvertidas({0, 0});
        CHECK(convertidas.empty());
    }
}

TEST_CASE("Testar isJogadaValida") {
    Reversi jogo;

    SUBCASE("Jogada válida - dentro do tabuleiro e com conversão") {
        CHECK(jogo.isJogadaValida({2, 3}) == true);
        CHECK(jogo.isJogadaValida({5, 4}) == true);
    }

    SUBCASE("Jogada inválida - fora do tabuleiro") {
        CHECK(jogo.isJogadaValida({-1, 3}) == false);
        CHECK(jogo.isJogadaValida({8, 8}) == false);
    }

    SUBCASE("Jogada inválida - posição já ocupada") {
        CHECK(jogo.isJogadaValida({3, 3}) == false);
        CHECK(jogo.isJogadaValida({4, 4}) == false);
    }

    SUBCASE("Jogada inválida - sem peças para converter") {
        CHECK(jogo.isJogadaValida({0, 0}) == false);
    }
}