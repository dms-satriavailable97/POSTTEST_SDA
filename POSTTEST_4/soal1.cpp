#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk linked list
struct Node {
    char data;   // menyimpan data karakter
    Node* next;  // pointer ke node berikutnya
};

// Fungsi untuk menaruh data ke stack
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};        // buat node baru dengan data dan arahkan ke top sekarang
    top = newNode;                                  // geser top ke node baru
}

// Fungsi untuk mengambil data dari stack
char pop(Node*& top) {
    if (top == nullptr) return '\0';            // kalau stack kosong, balikin karakter kosong
    Node* temp = top;                           // simpan node paling atas       
    char poppedValue = temp->data;              // ambil data dari node paling atas
    top = top->next;                            // geser top ke node berikutnya
    delete temp;                                // hapus node lama biar ga bocor memori
    return poppedValue;                         // balikin data yang di-pop 
}

// Fungsi untuk membalik string pakai stack
string reversedString(string s) {
    Node* stackTop = nullptr;  // stack awal kosong
    string reversed = "";      // hasil string terbalik

    /* Karena sifat Stack adalah LIFO (Last-In, First-Out),
    karakter terakhir yang dimasukkan akan menjadi yang pertama kali dikeluarkan. 
    Ini secara alami membalik urutan karakter.*/

    // 1. Masukkan semua karakter string ke stack
    for (char c : s) {
        push(stackTop, c); 
    }

    // 2. Ambil lagi semua karakter dari stack
    while (stackTop != nullptr) {
        reversed += pop(stackTop); // pop satu per satu, otomatis kebalik
    }

    return reversed; // balikin string yang udah dibalik
}

int main() {
    string text = "Struktur Data";  
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reversedString(text) << endl; 
    // hasilnya: ataD rutkurtS
    return 0;
}
