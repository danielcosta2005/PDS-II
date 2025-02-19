#include <iostream>
#include <memory> 
using namespace std;

class Teste {
private:
    int valor;

public:
    Teste() : valor(0) {
        cout << "Construtor " << valor << endl;
    }

    Teste(int v) : valor(v) {
        cout << "Construtor " << valor << endl;
    }

    ~Teste() {
        cout << "Destrutor " << valor << endl;
    }

    void setValor(int v) {
        valor = v;
    }

    int getValor() const {
        return valor;
    }
};

int main() {
    int n;
    cin >> n; 

    if (n % 2 == 0) { 
        for (int c = 1; c <= n; c++) {
            Teste* ptrTradicional = new Teste(c);
            delete ptrTradicional;

            unique_ptr<Teste> ptrUnico = make_unique<Teste>(c);
        }
    } else { 
        shared_ptr<Teste> ptrCompartilhado = make_shared<Teste>(0);

        for (int c = 1; c <= n; c++) {
            shared_ptr<Teste> outroPtrCompartilhado = ptrCompartilhado;
            outroPtrCompartilhado->setValor(c);
        }

        cout << ptrCompartilhado.use_count() << endl;
    }

    return 0;
}
