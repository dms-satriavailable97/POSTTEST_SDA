#include <iostream>
using namespace std;

void balikArray(int *array, int n) {
    int *awal = array;
    int *akhir = array + n - 1;
    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

int main() {
    int array[7];

    // isi dengan kelipatan 3
    for (int i = 0; i < 7; i++) {
        array[i] = (i + 1) * 3;
    }

    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < 7; i++) cout << array[i] << " ";

    balikArray(array, 7);

    cout << "\nArray sesudah dibalik: ";
    for (int i = 0; i < 7; i++) cout << array[i] << " ";

    return 0;
}
