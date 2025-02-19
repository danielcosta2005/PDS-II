#include "list.hpp"

#include <iostream>

void List::insertNode(int data) {
    Node* aux = new Node;
    aux->data = data;
    aux->next = nullptr;
    if (head == nullptr) {
        head = aux;
        tail = aux;
    } else {
        tail->next = aux;
        tail = aux;
    }
}

void List::display() {
    Node* aux = head;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

// Você deverá implementar apenas esse método
void List::inverte() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    // Inverter os ponteiros dos nós
    while (current != nullptr) {
        next = current->next;  // Salvar próximo nó
        current->next = prev; // Inverter o ponteiro
        prev = current;       // Avançar prev
        current = next;       // Avançar current
    }

    // Atualizar head e tail
    tail = head;
    head = prev;
}

