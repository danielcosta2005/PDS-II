#include "HeapInt.hpp"

HeapInt::HeapInt() {
    valor = new int(0);
}

HeapInt::HeapInt(int v) {
    valor = new int(v);
}

HeapInt::HeapInt(const HeapInt& outro) {
    valor = new int(*outro.valor);
}

HeapInt::~HeapInt() {
    delete valor;
}

HeapInt& HeapInt::operator=(int v) {
    *valor = v;
    return *this;
}

HeapInt& HeapInt::operator=(const HeapInt& outro) {
    if (this != &outro) { 
        *valor = *outro.valor;
    }
    return *this;
}

HeapInt HeapInt::operator+(const HeapInt& outro) const {
    return HeapInt(*valor + *outro.valor);
}

HeapInt HeapInt::operator-(const HeapInt& outro) const {
    return HeapInt(*valor - *outro.valor);
}

bool HeapInt::operator==(const HeapInt& outro) const {
    return *valor == *outro.valor;
}

istream& operator>>(istream& in, HeapInt& obj) {
    in >> *obj.valor;
    return in;
}

ostream& operator<<(ostream& out, const HeapInt& obj) {
    out << *obj.valor;
    return out;
}
