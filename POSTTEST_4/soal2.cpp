#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

// cek apakah bracket seimbang
bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    for (char c : expr) {
        // kalau ketemu kurung buka, masuk ke stack
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        // kalau ketemu kurung tutup
        else if (c == ')' || c == '}' || c == ']') {
            if (stackTop == nullptr) return false; // stack kosong

            char topChar = pop(stackTop); // ambil kurung terakhir

            // cek pasangan
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    // stack harus kosong kalau seimbang
    return stackTop == nullptr;
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    // Output: Seimbang

    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;
    // Output: Tidak Seimbang

    return 0;
}
