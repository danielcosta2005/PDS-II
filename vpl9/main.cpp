
#include <iostream>
#include "vetor.hpp"

int main()
{
    Vetor<char> a(5);
    for(char i='a'; i<='e'; i++)
        a.AdicionaElemento(i);

    Vetor<char> b = a;
    b.SetElemento(1,b.GetElemento(4));
    b.SetElemento(2,'i');
    b.SetElemento(3,'o');
    b.SetElemento(4,'u');
   
    a.Imprime();
    b.Imprime();
    return 0;
}
