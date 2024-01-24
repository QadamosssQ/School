#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);

        if (!head || value < head->data) {
            newNode->next = head;
            if (head)
                head->prev = newNode;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next && current->next->data < value) {
            current = current->next;
        }

        newNode->next = current->next;
        if (current->next)
            current->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
    }

    void remove(int value) {
        Node* current = head;

        while (current && current->data != value) {
            current = current->next;
        }

        if (!current) {
            std::cout << "Element o wartosci " << value << " nie istnieje w liscie." << std::endl;
            return;
        }

        if (current->prev)
            current->prev->next = current->next;
        else
            head = current->next;

        if (current->next)
            current->next->prev = current->prev;

        delete current;
        std::cout << "Element o wartosci " << value << " zostal usuniety z listy." << std::endl;
    }

    void show() {
        Node* current = head;

        std::cout << "Zawartosc listy: ";
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList myList;

    myList.insert(5);
    myList.insert(3);
    myList.insert(7);
    myList.insert(1);

    myList.show();

    myList.insert(4);
    myList.show();

    myList.remove(3);
    myList.show();

    myList.remove(8);

    return 0;
}
