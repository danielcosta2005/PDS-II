#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <iomanip>

using namespace std;

class Ponto {
private:
    float x, y;

public:
    Ponto(float x = 0, float y = 0) : x(x), y(y) {}

    float getX() const { return x; }
    void setX(float x) { this->x = x; }

    float getY() const { return y; }
    void setY(float y) { this->y = y; }
};

class FiguraGeometrica {
protected:
    Ponto centro;

public:
    FiguraGeometrica(float x, float y) : centro(x, y) {}
    virtual ~FiguraGeometrica() {}

    virtual void Desenha() const {
        cout << centro.getX() << " " << centro.getY() << " ";
    }

    virtual float CalculaArea() const = 0;
};

class Retangulo : public FiguraGeometrica {
private:
    float lado1, lado2;

public:
    Retangulo(float x, float y, float lado1, float lado2)
        : FiguraGeometrica(x, y), lado1(lado1), lado2(lado2) {}

    void Desenha() const override {
        FiguraGeometrica::Desenha();
        cout << "RETANGULO" << endl;
    }

    float CalculaArea() const override {
        return lado1 * lado2;
    }
};

class Circulo : public FiguraGeometrica {
private:
    float raio;

public:
    Circulo(float x, float y, float raio)
        : FiguraGeometrica(x, y), raio(raio) {}

    void Desenha() const override {
        FiguraGeometrica::Desenha();
        cout << "CIRCULO" << endl;
    }

    float CalculaArea() const override {
        return M_PI * raio * raio;
    }
};

class Triangulo : public FiguraGeometrica {
private:
    float base, altura;

public:
    Triangulo(float x, float y, float base, float altura)
        : FiguraGeometrica(x, y), base(base), altura(altura) {}

    void Desenha() const override {
        FiguraGeometrica::Desenha();
        cout << "TRIANGULO" << endl;
    }

    float CalculaArea() const override {
        return 0.5f * base * altura;
    }
};

int main() {
    vector<unique_ptr<FiguraGeometrica>> figuras;
    char comando;

    while (cin >> comando) {
        if (comando == 'E') {
            break;
        } else if (comando == 'R') {
            float x, y, l1, l2;
            cin >> x >> y >> l1 >> l2;
            figuras.push_back(unique_ptr<FiguraGeometrica>(new Retangulo(x, y, l1, l2)));
        } else if (comando == 'C') {
            float x, y, r;
            cin >> x >> y >> r;
            figuras.push_back(unique_ptr<FiguraGeometrica>(new Circulo(x, y, r)));
        } else if (comando == 'T') {
            float x, y, b, a;
            cin >> x >> y >> b >> a;
            figuras.push_back(unique_ptr<FiguraGeometrica>(new Triangulo(x, y, b, a)));
        } else if (comando == 'D') {
            for (const auto& figura : figuras) {
                figura->Desenha();
            }
        } else if (comando == 'A') {
            float areaTotal = 0;
            for (const auto& figura : figuras) {
                areaTotal += figura->CalculaArea();
            }
            cout << fixed << setprecision(2) << areaTotal << endl;
        }
    }

    return 0;
}
