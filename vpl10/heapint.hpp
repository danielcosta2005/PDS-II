#ifndef HEAPINT_HPP
#define HEAPINT_HPP

#include <iostream>
using namespace std;

class HeapInt {
private:
    int* valor; 

public:
    HeapInt();

    HeapInt(int v);

    HeapInt(const HeapInt& outro);

    ~HeapInt();

    HeapInt& operator=(int v);

    HeapInt& operator=(const HeapInt& outro);

    HeapInt operator+(const HeapInt& outro) const;

    HeapInt operator-(const HeapInt& outro) const;

    bool operator==(const HeapInt& outro) const;

    friend istream& operator>>(istream& in, HeapInt& obj);

    friend ostream& operator<<(ostream& out, const HeapInt& obj);
};

#endif
