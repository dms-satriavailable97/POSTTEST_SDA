#include <iostream>
#include <limits>
using namespace std;

struct Node {
    string namaItem;
    int jumlah;
    string tipe;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

int jumlah_item_awal = 0;
int posisi_sisip_item = 0;

// tambah item di akhir
void tambahItem(string nama, string tipe) {
    Node* baru = new Node{nama, jumlah_item_awal, tipe, NULL, NULL};
    if (!head) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}

string pilihTipeItem() {
    int tipePilihan;
    string tipeItem;

    do {
        cout << "Pilih Tipe Item:\n";
        cout << "  1. Weapon\n";
        cout << "  2. Potion\n";
        cout << "  3. Food\n";
        cout << "  4. Drink\n";
        cout << "  5. Armor\n";
        cout << "Masukkan pilihan (1-5): ";

        if (!(cin >> tipePilihan)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input harus berupa angka!\n\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // buang enter

        switch (tipePilihan) {
            case 1: tipeItem = "Weapon"; break;
            case 2: tipeItem = "Potion"; break;
            case 3: tipeItem = "Food";   break;
            case 4: tipeItem = "Drink";  break;
            case 5: tipeItem = "Armor";  break;
            default:
                cout << "Pilihan tidak valid! Masukkan angka 1-5." << endl;
                tipeItem = "";
        }
    } while (tipeItem == "");

    return tipeItem;
}

// sisip item di posisi tertentu
void sisipItem(string nama, string tipe) {
    Node* baru = new Node{nama, jumlah_item_awal, tipe, NULL, NULL};

    if (!head) {
        head = tail = baru;
        return;
    }

    Node* temp = head;
    int hitung = 1;

    while (temp->next && hitung < posisi_sisip_item - 1) {
        temp = temp->next;
        hitung++;
    }

    baru->next = temp->next;
    baru->prev = temp;
    if (temp->next) {
        temp->next->prev = baru;
    } else {
        tail = baru;
    }
    temp->next = baru;
}

// hapus item terakhir
void hapusTerakhir() {
    if (!tail) {
        cout << "Inventory kosong!" << endl;
        return;
    }
    Node* hapus = tail;
    if (tail->prev) {
        tail = tail->prev;
        tail->next = NULL;
    } else {
        head = tail = NULL;
    }
    delete hapus;
}

// gunakan item (berdasarkan nama)
void gunakanItem(string nama) {
    if (!head) {
        cout << "Inventory kosong!" << endl;
        return;
    }

    Node* temp = head;
    while (temp && temp->namaItem != nama) {
        temp = temp->next;
    }

    if (!temp) {
        cout << "Item tidak ditemukan!" << endl;
        return;
    }

    temp->jumlah--;
    cout << "Menggunakan " << temp->namaItem << ". Sisa: " << temp->jumlah << endl;

    if (temp->jumlah == 0) {
        cout << temp->namaItem << " habis, dihapus dari inventory." << endl;
        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        else tail = temp->prev;
        delete temp;
    }
}

// tampilkan inventory dari depan
void tampilkanInventory() {
    if (!head) {
        cout << "Inventory kosong!" << endl;
        return;
    }
    Node* temp = head;
    int nomor = 1;
    cout << "\n--- Inventory ---" << endl;
    while (temp) {
        cout << nomor++ << ". "
             << "Nama: " << temp->namaItem
             << " | Jumlah: " << temp->jumlah
             << " | Tipe: " << temp->tipe << endl;
        temp = temp->next;
    }
}

// tampilkan inventory dari belakang
void tampilkanInventoryBelakang() {
    if (!tail) {
        cout << "Inventory kosong!" << endl;
        return;
    }
    Node* temp = tail;
    int nomor = 1;
    cout << "\n--- Inventory (dari belakang) ---" << endl;
    while (temp) {
        cout << nomor++ << ". "
             << "Nama: " << temp->namaItem
             << " | Jumlah: " << temp->jumlah
             << " | Tipe: " << temp->tipe << endl;
        temp = temp->prev;
    }
}

// tampilkan detail item berdasarkan input nama
void tampilkanDetail() {
    if (!head) {
        cout << "Inventory kosong!" << endl;
        return;
    }
    string namaCari;
    cout << "Masukkan Nama Item: ";
    getline(cin, namaCari);

    Node* temp = head;
    bool ketemu = false;
    while (temp) {
        if (temp->namaItem == namaCari) {
            ketemu = true;
            cout << "\n--- Detail Item ---\n";
            cout << "Nama   : " << temp->namaItem << endl;
            cout << "Jumlah : " << temp->jumlah << endl;
            cout << "Tipe   : " << temp->tipe << endl;
            break;
        }
        temp = temp->next;
    }
    if (!ketemu) cout << "Item tidak ditemukan!\n";
}

int main() {
    string nama;
    int nim;
    cout << "Masukkan Nama  : ";
    getline(cin, nama);
    cout << "Masukkan NIM   : ";
    cin >> nim;
    cin.ignore();

    jumlah_item_awal = nim % 100;      // 2 digit terakhir NIM
    posisi_sisip_item = (nim % 10) + 1; // digit terakhir NIM + 1

    int pilihan;
    do {
        cout << "\n========================================================" << endl;
        cout << "           !  GAME INVENTORY MANAGEMENT  !" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "   Player : Dimas Elang Satria" << endl;
        cout << "   NIM    : 2409106027" << endl;
        cout << "========================================================" << endl;
        cout << "   [1] - Tambah Item Baru" << endl;
        cout << "   [2] - Sisipkan Item" << endl;
        cout << "   [3] - Hapus Item Terakhir" << endl;
        cout << "   [4] - Gunakan Item" << endl;
        cout << "   [5] - Tampilkan Inventory (dari depan)" << endl;
        cout << "   [6] - Tampilkan Inventory (dari belakang)" << endl;
        cout << "   [7] - Tampilkan Detail Item (berdasarkan Nama)" << endl;
        cout << "   [0] - Keluar" << endl;
        cout << "========================================================" << endl;
        cout << "Pilih menu: ";

        cin >> pilihan;
        cin.ignore();

        string namaItem, tipe;
        switch (pilihan) {
            case 1:
                cout << "Nama Item: "; getline(cin, namaItem);
                tipe = pilihTipeItem();
                tambahItem(namaItem, tipe);
                break;
            case 2:
                cout << "Nama Item: "; getline(cin, namaItem);
                tipe = pilihTipeItem();
                sisipItem(namaItem, tipe);
                break;
            case 3:
                hapusTerakhir();
                break;
            case 4:
                cout << "Masukkan nama item yang ingin digunakan: ";
                getline(cin, namaItem);
                gunakanItem(namaItem);
                break;
            case 5:
                tampilkanInventory();
                break;
            case 6:
                tampilkanInventoryBelakang();
                break;
            case 7:
                tampilkanDetail();
                break;
            case 0:
                cout << "Keluar program..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
