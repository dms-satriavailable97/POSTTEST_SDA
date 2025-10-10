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
    
//Fungsi untuk melakukan post-order traversal pada tree.
//Urutan: kiri -> kanan -> root

void postOrderTraversal(Node* root) {
    // Base case: jika node kosong, hentikan
    if (root == nullptr) {
        return;
    }

    // 1. Telusuri subtree kiri
    postOrderTraversal(root->left);

    // 2. Telusuri subtree kanan
    postOrderTraversal(root->right);

    // 3. Cetak nilai node saat ini (setelah kiri & kanan)
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr; // Awalnya tree kosong

    // Tambahkan node ke dalam tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Post-order traversal dari tree adalah: ";
    postOrderTraversal(root); 
    // Output seharusnya: 20 40 30 60 80 70 50

    cout << endl;
    return 0;
}
