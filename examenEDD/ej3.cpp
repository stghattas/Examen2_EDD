#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Estudiante {
    string nombre;
    int edad;

    Estudiante(string n, int e) : nombre(n), edad(e) {}

    bool operator<(const Estudiante& otro) const {
        if (nombre != otro.nombre)
            return nombre > otro.nombre;
        return edad > otro.edad;
    }
};

int main() {
    int n;
    cout << "Ingrese el numero de estudiantes: ";
    cin >> n;

    priority_queue<Estudiante> cola;

    for (int i = 0; i < n; ++i) {
        string nombre;
        int edad;

        cout << "Ingrese el nombre del estudiante #" << i + 1 << ": ";
        cin >> ws;
        getline(cin, nombre);

        cout << "Ingrese la edad de " << nombre << ": ";
        cin >> edad;

        Estudiante estudiante(nombre, edad);
        cola.push(estudiante);
    }

    cout << "\nEstudiantes ordenados:\n";
    while (!cola.empty()) {
        Estudiante estudiante = cola.top();
        cola.pop();
        cout << "Nombre: " << estudiante.nombre << ", Edad: " << estudiante.edad << endl;
    }

    return 0;
}