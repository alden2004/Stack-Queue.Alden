#include <iostream>
using namespace std;

int maksimalAntrianArray = 5, front = 0, back = 0;
struct Movie {
    string judul;
    int durasi;
    int harga;
} antrianFilm[5];

bool isFullArray() {
    return back == maksimalAntrianArray;
}

bool isEmptyArray() {
    return back == 0;
}

void enqueueArray(string judul, int durasi, int harga) {
    if (isFullArray()) {
        cout << "Antrian penuh!!" << endl;
    } else {
        antrianFilm[back].judul = judul;
        antrianFilm[back].durasi = durasi;
        antrianFilm[back].harga = harga;
        back++;
    }
}

void dequeueArray() {
    if (isEmptyArray()) {
        cout << "Antrian kosong!!" << endl;
    } else {
        for (int i = 0; i < back - 1; i++) {
            antrianFilm[i] = antrianFilm[i + 1];
        }
        back--;
    }
}

int countArray() {
    return back;
}

void destroyArray() {
    back = 0;
    front = 0;
}

void viewArray() {
    cout << "Jumlah data yang antri: " << countArray() << " data." << endl;
    cout << "Data Antrian Film: " << endl;
    if (isEmptyArray()) {
        cout << "Antrian kosong!!" << endl;
    } else {
        for (int i = 0; i < maksimalAntrianArray; i++) {
            if (i < back) {
                cout << i + 1 << ". Judul: " << antrianFilm[i].judul << endl;
                cout << "   Durasi: " << antrianFilm[i].durasi << " menit" << endl;
                cout << "   Harga: Rp" << antrianFilm[i].harga << endl;
            } else {
                cout << i + 1 << ". (kosong)" << endl;
            }
        }
    }
    cout << endl;
}

int main() {
    enqueueArray("Ultraman Saga", 90, 45000);
    viewArray();

    enqueueArray("The Nun 2", 120, 60000);
    enqueueArray("The Walking Dead 2", 160, 90000);
    enqueueArray("Power Ranger 2", 60, 25000);
    enqueueArray("El Silbon", 120, 60000);
    viewArray();

    enqueueArray("Toy Story 3", 180, 110000);
    viewArray();

    dequeueArray();
    viewArray();

    destroyArray();
    viewArray();

    return 0;
}