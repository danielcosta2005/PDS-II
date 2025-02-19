#include <iostream>
using namespace std;

void incrementa(int a, int &b, int *c) {
    a++;
    b++;
    (*c)++;
}

int main() {
    // 1) Declarar uma variável inteira com valor da entrada
    int x;
    cin >> x;

    // 2) Declarar um ponteiro para inteiros e inicializar como nulo
    int *ptr = NULL;

    // 3) Declarar um vetor de inteiros e preencher com valores da entrada
    int n;
    cin >> n;
    int *arr = new int[n];  // Alocação dinâmica de vetor
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 4) Imprimir o ENDEREÇO da variável (1)
    cout << &x << endl;

    // 5) Imprimir o VALOR da variável (1)
    cout << x << endl;

    // 6) Imprimir o ENDEREÇO da variável (2)
    cout << &ptr << endl;

    // 7) Imprimir o VALOR da variável (2)
    cout << ptr << endl;

    // 8) Imprimir o ENDEREÇO da variável (3)
    cout << &arr << endl;

    // 9) Imprimir o ENDEREÇO da primeira posição do vetor (3)
    cout << &arr[0] << endl;

    // 10) Imprimir o VALOR da primeira posição do vetor (3)
    cout << arr[0] << endl;

    // 11) Atribuir o ENDEREÇO de (1) a (2)
    ptr = &x;

    // 12) Imprimir o VALOR da variável (2)
    cout << ptr << endl;

    // 13) Imprimir o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *ptr << endl;

    // 14) Atribuir o valor '5' ao ENDEREÇO apontado por (2)
    *ptr = 5;

    // 15) Imprimir o VALOR da variável (1)
    cout << x << endl;

    // 16) Atribuir o VALOR de (3) à variável (2)
    ptr = arr;

    // 17) Imprimir o VALOR da variável (2)
    cout << ptr << endl;

    // 18) Imprimir o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *ptr << endl;

    // 19) Atribuir o ENDEREÇO da primeira posição de (3) a (2)
    ptr = &arr[0];

    // 20) Comparar valores de (2) e (3), imprimir 'S' ou 'N'
    cout << ((ptr == &arr[0]) ? 'S' : 'N') << endl;

    // 21) Imprimir o VALOR de (2)
    cout << ptr << endl;

    // 22) Imprimir o VALOR guardado no ENDEREÇO de (2)
    cout << *ptr << endl;

    // 23) Multiplicar todos os valores do vetor por '10' usando o ponteiro
    for (int i = 0; i < n; i++) {
        *(ptr + i) *= 10;
    }

    // 24) Imprimir os elementos de (3) com notação []
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            cout << arr[i] << " ";
        } else {
            cout << arr[i];
        }
    }
    cout << endl;

    // 25) Imprimir os elementos de (3) com notação ponteiro/deslocamento
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            cout << *(arr + i) << " ";
        } else {
            cout << *(arr + i);
        }
    }
    cout << endl;

    // 26) Imprimir os elementos de (3) usando (2) e notação ponteiro/deslocamento
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            cout << *(ptr + i) << " ";
        } else {
            cout << *(ptr + i);
        }
    }
    cout << endl;

    // 27) Atribuir o ENDEREÇO da última posição de (3) a (2)
    ptr = &arr[n - 1];

    // 28) Imprimir o VALOR de (2)
    cout << ptr << endl;

    // 29) Imprimir o VALOR guardado no ENDEREÇO de (2)
    cout << *ptr << endl;

    // 30) Declarar um ponteiro para ponteiro e inicializá-lo com (2)
    int **ptr2 = &ptr;

    // 31) Imprimir o VALOR de (30)
    cout << ptr2 << endl;

    // 32) Imprimir o ENDEREÇO de (30)
    cout << &ptr2 << endl;

    // 33) Imprimir o VALOR guardado no ENDEREÇO de (30)
    cout << *ptr2 << endl;

    // 34) Imprimir o VALOR guardado no ENDEREÇO apontado por (30)
    cout << **ptr2 << endl;

    // 35) Declarar 3 variáveis inteiras e ler os valores da entrada
    int a, b, c;
    cin >> a >> b >> c;

    // 36) Chamar a função criada em (0)
    incrementa(a, b, &c);

    // 37) Imprimir o valor das 3 variáveis
    cout << a << " " << b << " " << c << endl;

    // Liberação de memória alocada dinamicamente
    delete[] arr;

    return 0;
}
