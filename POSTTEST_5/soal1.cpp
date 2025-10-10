#include <iostream>
using namespace std;

// Struktur Node untuk Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor untuk membuat node baru
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi untuk menambahkan nilai ke dalam tree (BST)
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        // Jika belum ada node, buat node baru
        return new Node(val);
    }
    // Jika nilai lebih kecil dari data node sekarang, masuk ke kiri
    if (val < root->data) {
        root->left = insert(root->left, val);
    } 
    // Jika nilai lebih besar, masuk ke kanan
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root; // Kembalikan root agar struktur tree tetap utuh
}

 // Fungsi untuk menghitung jumlah total node dalam tree.

int countNodes(Node* root) {
    // Jika tree kosong, jumlah node = 0
    if (root == nullptr) {
        return 0;
    }

    // Hitung total node:
    // 1 (node sekarang) + jumlah node di kiri + jumlah node di kanan
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = nullptr;   // Mulai dari tree kosong

    // Tambahkan beberapa node ke dalam tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);

    // Cetak hasil total node dalam tree
    cout << "Jumlah total node dalam tree adalah: " << countNodes(root) << endl; 
    // Output seharusnya: 4

    return 0;
}
