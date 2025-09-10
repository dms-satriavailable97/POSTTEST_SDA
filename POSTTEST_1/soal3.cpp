#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

bool cekNIM(string nim) {
    if (nim.length() < 10 || nim.length() > 13) return false;
    for (char c : nim) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int main() {
    Mahasiswa mhs[5];

    // input data
    for (int i = 0; i < 5 ; i++) {
        cout << "Mahasiswa ke-" << i+1 << endl;
        cout << "Nama : "; cin >> mhs[i].nama;
        
        do {
            cout << "NIM  : ";
            cin >> mhs[i].nim;
            if (!cekNIM(mhs[i].nim)) {
                cout << "NIM harus terdiri dari 10-13 digit angka!\n";
            }
        } while (!cekNIM(mhs[i].nim));

        do {
            cout << "IPK  : ";
            cin >> mhs[i].ipk;
            if (mhs[i].ipk < 0.0 || mhs[i].ipk > 4.0) {
                cout << "IPK harus antara 0.00 - 4.00!\n";
            }
        } while (mhs[i].ipk < 0.0 || mhs[i].ipk > 4.0);

        cout << endl;
    }

    // cari ipk tertinggi
    int tertinggi = 0;
    for (int i = 1; i < 5; i++) {
        if (mhs[i].ipk > mhs[tertinggi].ipk) {
            tertinggi = i;
        }
    }

    cout << "\nMahasiswa dengan IPK tertinggi:" << endl;
    cout << "Nama : " << mhs[tertinggi].nama << endl;
    cout << "NIM  : " << mhs[tertinggi].nim << endl;
    cout << "IPK  : " << mhs[tertinggi].ipk << endl;

    return 0;
}
