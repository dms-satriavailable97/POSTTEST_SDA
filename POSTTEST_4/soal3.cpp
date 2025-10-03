#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

// tambahkan dokumen ke antrian (enqueue)
void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    if (front == nullptr) {
        // kalau kosong, front dan rear sama-sama newNode
        front = rear = newNode;
    } else {
        // kalau tidak kosong, sambungkan ke belakang
        rear->next = newNode;
        rear = newNode;
    }
}

// keluarkan dokumen dari antrian (dequeue)
string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // queue kosong

    Node* temp = front;
    string doc = temp->document;

    // geser front ke node berikutnya
    front = front->next;
    if (front == nullptr) {
        // kalau kosong, rear juga null
        rear = nullptr;
    }

    delete temp;
    return doc;
}

// proses semua dokumen dalam antrian
void processAllDocuments(Node*& front, Node*& rear) {
    while (front != nullptr) {
        string doc = dequeue(front, rear);
        cout << "Memproses: " << doc << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}
