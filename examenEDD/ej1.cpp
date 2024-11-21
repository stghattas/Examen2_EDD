#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class DynamicStructure {
private:
    Node<T>* head;
    Node<T>* tail;
    bool isFIFO;

public:
    DynamicStructure(bool fifo) : head(nullptr), tail(nullptr), isFIFO(fifo) {}

    ~DynamicStructure() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (isFIFO) {
            if (tail != nullptr) {
                tail->next = newNode;
            }
            tail = newNode;
            if (head == nullptr) {
                head = newNode;
            }
        } else {
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) {
                tail = newNode;
            }
        }
    }

    T pop() {
        if (head == nullptr) {
            throw runtime_error("La estructura está vacia.");
        }

        if (isFIFO) {
            Node<T>* temp = head;
            T value = head->data;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
            delete temp;
            return value;
        } else {
            Node<T>* temp = head;
            T value = head->data;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
            delete temp;
            return value;
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }
};

int main() {
    int cantidad, valor;
    bool modoFIFO;

    cout << "Elija el modo de la estructura: FIFO (1) o FILO (0): ";
    cin >> modoFIFO;
    DynamicStructure<int> structure(modoFIFO);

    cout << "Ingrese la cantidad de elementos que desea agregar: ";
    cin >> cantidad;

    for (int i = 0; i < cantidad; ++i) {
        cout << "Ingrese el valor del elemento " << i + 1 << ": ";
        cin >> valor;
        structure.push(valor);
    }

    cout << "\nExtrayendo elementos de la estructura:\n";
    while (!structure.isEmpty()) {
        try {
            cout << "Elemento extraido: " << structure.pop() << endl;
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}