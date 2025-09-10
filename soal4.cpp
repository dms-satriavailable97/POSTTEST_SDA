#include <iostream>
using namespace std;

void swap(int **a, int **b) {
    int temp = **a;
    **a = **b;
    **b = temp;
}

int main() {
    int x, y;
    cout << "Masukkan nilai x: "; cin >> x;
    cout << "Masukkan nilai y: "; cin >> y;

    int *ptrx = &x;
    int *ptry = &y;

    cout << "\nSebelum ditukar: x = " << x << ", y = " << y << endl;
    swap(&ptrx, &ptry);
    cout << "Sesudah ditukar : x = " << x << ", y = " << y << endl;

    return 0;
}
