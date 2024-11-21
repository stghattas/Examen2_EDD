#include <iostream>
#include <stack>
using namespace std;

void insertarOrdenado(stack<int>& pila, int valor) {
    if (pila.empty() || pila.top() >= valor) {
        pila.push(valor);
    } else {
        int temp = pila.top();
        pila.pop();
        insertarOrdenado(pila, valor);
        pila.push(temp); 
    }
}

int main() {
    stack<int> pila;
    int n, valor;

    cout << "Cuantos elementos deseas insertar en la pila? ";
    cin >> n;

    if (n <= 0) {
        cout << "Por favor ingresa un numero mayor que 0." << endl;
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        cout << "Ingresa el valor del elemento #" << i + 1 << ": ";
        cin >> valor;
        insertarOrdenado(pila, valor);
    }

    cout << "Elementos en la pila: ";
    while (!pila.empty()) {
        cout << pila.top() << " ";
        pila.pop();
    }

    return 0;
}