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
        // Jika nilai lebih kecil, masuk ke subtree kiri
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        // Jika nilai lebih besar, masuk ke subtree kanan
        root->right = insert(root->right, val);
    }
    return root;
}

//Fungsi untuk melakukan pre-order traversal.
// Urutan: root -> kiri -> kanan

void preOrderTraversal(Node* root) {
    // Base case: jika node kosong, hentikan
    if (root == nullptr) {
        return;
    }

    // 1. Cetak data node sekarang (root)
    cout << root->data << " ";

    // 2. Telusuri subtree kiri
    preOrderTraversal(root->left);

    // 3. Telusuri subtree kanan
    preOrderTraversal(root->right);
}

int main() {
    Node* root = nullptr; // Awalnya tree kosong
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Pre-order traversal dari tree adalah: ";
    preOrderTraversal(root); 
    // Output seharusnya: 50 30 20 40 70 60 80

    cout << endl;
    return 0;
}
