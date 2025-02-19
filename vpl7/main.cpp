#include <iostream>
#include <list>
#include <memory>

using namespace std;

class Objeto {
private:
    static int contadorObjetos;
    static int proximoId;
    int id;

public:
    Objeto(int id = 0) {
        if (id < 0) {
            this->id = id;
        } else {
            this->id = proximoId++;
        }
        contadorObjetos++;
    }

    ~Objeto() {
        contadorObjetos--;
    }

    static int getContadorObjetos() {
        return contadorObjetos;
    }

    int getId() const {
        return id;
    }

    const Objeto* getEndereco() const {
        return this;
    }
};

int Objeto::contadorObjetos = 0;
int Objeto::proximoId = 1;

int main() {
    list<unique_ptr<Objeto>> objetos;
    char comando;

    while (cin >> comando) {
        if (comando == 'A') {
            auto obj = unique_ptr<Objeto>(new Objeto());
            cout << obj->getId() << " " << obj->getEndereco() << endl;
            objetos.push_back(move(obj));
        } else if (comando == 'C') {
            int id;
            cin >> id;
            if (id >= 0) {
                cout << "ERRO" << endl;
            } else {
                auto obj = unique_ptr<Objeto>(new Objeto(id));
                cout << obj->getId() << " " << obj->getEndereco() << endl;
                objetos.push_front(move(obj));
            }
        } else if (comando == 'R') {
            if (objetos.empty()) {
                cout << "ERRO" << endl;
            } else {
                auto obj = move(objetos.front());
                objetos.pop_front();
                cout << obj->getId() << " " << obj->getEndereco() << endl;
            }
        } else if (comando == 'N') {
            cout << Objeto::getContadorObjetos() << endl;
        } else if (comando == 'P') {
            int i;
            cin >> i;
            if (i < 1 || static_cast<size_t>(i) > objetos.size()) {
                cout << "ERRO" << endl;
            } else {
                auto it = objetos.begin();
                advance(it, i - 1);
                cout << (*it)->getId() << " " << (*it)->getEndereco() << endl;
            }
        } else if (comando == 'L') {
            for (const auto& obj : objetos) {
                cout << obj->getId() << " " << obj->getEndereco() << endl;
            }
        } else if (comando == 'E') {
            break;
        }
    }

    return 0;
}
