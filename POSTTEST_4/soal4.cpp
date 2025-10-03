#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void sortedInsert(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    // Kasus 1: list masih kosong
    if (head_ref == nullptr) {
        newNode->next = newNode; // menunjuk diri sendiri
        newNode->prev = newNode; // menunjuk diri sendiri
        head_ref = newNode;
        return;
    }

    // Kasus 2: data lebih kecil dari head -> sisip di depan
    if (data < head_ref->data) {
        Node* tail = head_ref->prev; // node terakhir

        newNode->next = head_ref;    // sambungkan ke head lama
        newNode->prev = tail;        // sambungkan ke tail

        tail->next = newNode;        // tail -> newNode
        head_ref->prev = newNode;    // head lama <- newNode

        head_ref = newNode;          // update head
        return;
    }

    // Kasus 3: cari posisi di tengah/akhir
    Node* current = head_ref;
    while (current->next != head_ref && current->next->data < data) {
        current = current->next;
    }

    // sisip setelah current
    newNode->next = current->next;
    newNode->prev = current;

    current->next->prev = newNode;
    current->next = newNode;
}

void printList(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

int main() {
    Node *head = nullptr;

    // Test sorted insert
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "Circular Doubly Linked List (sorted): ";
    printList(head); // Output: 10 20 30 40

    return 0;
}
