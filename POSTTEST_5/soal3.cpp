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

// Fungsi untuk menambahkan data ke dalam tree (BST)
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        // Jika tree kosong, buat node baru
        return new Node(val);
    }
    if (val < root->data) {
        // Jika nilai lebih kecil, masukkan ke subtree kiri
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        // Jika nilai lebih besar, masukkan ke subtree kanan
        root->right = insert(root->right, val);
    }
    return root;
}

// Fungsi untuk mencari nilai terbesar dalam BST.

int findMaxValue(Node* root) {
    // Jika tree kosong, kembalikan -1
    if (root == nullptr) {
        return -1;
    }

    // Bergerak terus ke kanan sampai tidak ada anak kanan lagi
    while (root->right != nullptr) {
        root = root->right;
    }

    // Node paling kanan menyimpan nilai terbesar
    return root->data;
}

int main() {
    Node* root = nullptr; // Awalnya tree kosong
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);

    // Cetak nilai terbesar dalam tree
    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl; 
    // Output seharusnya: 80

    return 0;
}
