#include <iostream>
using namespace std;

int main() {
    int matriks[3][3] = {
        {15, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    cout << "Matriks 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    int jumlahDiagonalUtama = 0, jumlahDiagonalSekunder = 0;

    for (int i = 0; i < 3; i++) {
        jumlahDiagonalUtama += matriks[i][i];
        jumlahDiagonalSekunder += matriks[i][3 - 1 - i];
    }

    cout << "\nJumlah diagonal utama = " << jumlahDiagonalUtama;
    cout << "\nJumlah diagonal sekunder = " << jumlahDiagonalSekunder;
    cout << "\nTotal = " << (jumlahDiagonalUtama + jumlahDiagonalSekunder);

    return 0;
}
