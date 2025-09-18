#include <iostream>
using namespace std;

struct Node {
    string namaItem;
    int jumlah;
    string tipe;
    Node* next;
};

Node* head = NULL;

// Variabel global, akan di-set setelah input NIM
int jumlah_item_awal = 0;
int posisi_sisip_item = 0;

void tambahItem(string nama, string tipe) {
    Node* baru = new Node{nama, jumlah_item_awal, tipe, NULL};
    if (!head) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = baru;
    }
}

string pilihTipeItem() {
    int tipePilihan;
    cout << "Pilih Tipe Item:\n";
    cout << "  1. Weapon\n";
    cout << "  2. Potion\n";
    cout << "  3. Food\n";
    cout << "  4. Drink\n";
    cout << "  5. Armor\n";
    cout << "Masukkan pilihan (1-5): ";
    cin >> tipePilihan;
    cin.ignore();

    switch (tipePilihan) {
        case 1: return "Weapon";
        case 2: return "Potion";
        case 3: return "Food";
        case 4: return "Drink";
        case 5: return "Armor";
        default:
            cout << "Input tipe salah! Item tidak ditambahkan.\n";
            return "";
    }
}

void sisipItem(string nama, string tipe) {
    Node* baru = new Node{nama, jumlah_item_awal, tipe, NULL};

    if (!head) {
        head = baru;
        return;
    }

    Node* temp = head;
    int hitung = 1;

    // sisipkan di posisi ke-(posisi_sisip_item) (atau akhir jika < posisi_sisip_item node)
    while (temp->next && hitung < posisi_sisip_item-1) {
        temp = temp->next;
        hitung++;
    }

    baru->next = temp->next;
    temp->next = baru;
}

void hapusTerakhir() {
    if (!head) {
        cout << "Inventory kosong!" << endl ;
        return;
    }
    if (!head->next) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void gunakanItem(string nama) {
    if (!head) {
        cout << "Inventory kosong!" << endl ;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp && temp->namaItem != nama) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Item tidak ditemukan!" << endl ;
        return;
    }

    temp->jumlah--;
    cout << "Menggunakan " << temp->namaItem << ". Sisa: " << temp->jumlah << endl;

    if (temp->jumlah == 0) {
        cout << temp->namaItem << " habis, dihapus dari inventory." << endl ;
        if (!prev) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }
}

void tampilkanInventory() {
    if (!head) {
        cout << "Inventory kosong!" << endl ;
        return;
    }
    Node* temp = head;
    int nomor = 1;
    cout << "\n--- Inventory ---" << endl ;
    while (temp) {
        cout << nomor++ << ". "
             << "Nama: " << temp->namaItem
             << " | Jumlah: " << temp->jumlah
             << " | Tipe: " << temp->tipe << endl;
        temp = temp->next;
    }
}


int main() {
    string nama;
    int nim;
    cout << "Masukkan Nama  : ";
    getline(cin, nama);
    cout << "Masukkan NIM   : ";
    cin >> nim;
    cin.ignore();

    // Ambil 2 digit terakhir nim untuk jumlah_item_awal
    jumlah_item_awal = nim % 100;
    // Ambil digit terakhir nim + 1 untuk posisi_sisip_item
    posisi_sisip_item = (nim % 10) + 1;

    int pilihan;
    do {
        cout << "\n========================================================" << endl ;
        cout << "           !  GAME INVENTORY MANAGEMENT  !" << endl ;
        cout << "--------------------------------------------------------" << endl ;
        cout << "   Player : " << nama << "" << endl ;
        cout << "   NIM    : " << nim  << "" << endl ;
        cout << "========================================================" << endl ;
        cout << "   [1] - Tambah Item Baru" << endl ;
        cout << "   [2] - Sisipkan Item" << endl ;
        cout << "   [3] - Hapus Item Terakhir" << endl ;
        cout << "   [4] - Gunakan Item" << endl ;
        cout << "   [5] - Tampilkan Inventory" << endl ;
        cout << "   [0] - Keluar" << endl ;
        cout << "========================================================" << endl ;
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
            case 0:
                cout << "Keluar program..." << endl ;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl ;
        }
    } while (pilihan != 0);

    return 0;
}
