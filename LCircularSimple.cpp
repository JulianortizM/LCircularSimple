#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;

    friend class LinkedList;
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    int getFront() const;
    int getBack() const;
    void addFront(int va);
    void addBack(int va);
    void removeFront();
    void removeBack();
    void printForward();
    void update(int oldValue, int newValue);
private:
    Node* header;
};

LinkedList::LinkedList() {
    header = new Node;
    header->next = header; // Hacer que el nodo header apunte a sí mismo para formar un ciclo circular
};

int LinkedList::getFront() const {
    return header->next->data;
};

int LinkedList::getBack() const {
    return header->data; // Como la lista es circular, el último elemento se encuentra en header
};

void LinkedList::addFront(int va) {
    Node* nd = new Node;
    nd->data = va;
    nd->next = header->next;
    header->next = nd;
};

void LinkedList::addBack(int va) {
    Node* nd = new Node;
    nd->data = va;
    Node* current = header;

    // Avanzar hasta el último nodo
    while (current->next != header) {
        current = current->next;
    }

    // Agregar el nuevo nodo al final
    current->next = nd;
    nd->next = header;
};

void LinkedList::removeFront() {
    if (header->next != header) {
        Node* nd = header->next;
        header->next = nd->next;
        delete nd;
    }
};

void LinkedList::removeBack() {
    Node* current = header;

    // Avanzar hasta el penúltimo nodo
    while (current->next->next != header) {
        current = current->next;
    }

    // Eliminar el último nodo
    Node* nd = current->next;
    current->next = header;
    delete nd;
};

void LinkedList::printForward() {
    Node* current = header->next;

    while (current != header) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
};

void LinkedList::update(int oldValue, int newValue) {
    Node* current = header->next;

    while (current != header) {
        if (current->data == oldValue) {
            current->data = newValue;
        }
        current = current->next;
    }
};

LinkedList::~LinkedList() {
    while (header->next != header)
        removeFront();

    delete header;
};

int main() {
    LinkedList myList;

    while (true) {
        cout << "\nElija una opción:\n";
        cout << "1. Agregar dato al inicio\n";
        cout << "2. Agregar dato al final\n";
        cout << "3. Eliminar valor del inicio\n";
        cout << "4. Eliminar valor del final\n";
        cout << "5. Mostrar lista\n";
        cout << "6. Actualizar valor\n";
        cout << "7. Salir\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Ingrese el valor a agregar al frente: ";
            int value;
            cin >> value;
            myList.addFront(value);
        } else if (choice == 2) {
            cout << "Ingrese el valor a agregar al final: ";
            int value;
            cin >> value;
            myList.addBack(value);
        } else if (choice == 3) {
            myList.removeFront();
        } else if (choice == 4) {
            myList.removeBack();
        } else if (choice == 5) {
            cout << "Lista: ";
            myList.printForward();
        } else if (choice == 6) {
            int oldValue, newValue;
            cout << "Ingrese el valor antiguo: ";
            cin >> oldValue;
            cout << "Ingrese el nuevo valor: ";
            cin >> newValue;
            myList.update(oldValue, newValue);
        } else if (choice == 7) {
            break;
        } else {
            cout << "Opción no válida. Por favor, elija una opción válida.\n";
        }
    }
    return 0;
}

