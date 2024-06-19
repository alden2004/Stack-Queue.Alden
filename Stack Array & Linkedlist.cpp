#include <iostream>
using namespace std;

int maksimal = 5;
struct Film {
    string judul;
    int durasi;
    int harga;
};

Film arrayFilm[5];
int top = 0;

bool isFull() {
    return top == maksimal;
}

bool isEmpty() {
    return top == 0;
}

void pushArray(Film data) {
    if (isFull()) {
        cout << "Data penuh" << endl;
    } else {
        arrayFilm[top] = data;
        top++;
    }
}

void popArray() {
    if (isEmpty()) {
        cout << "Data kosong!!" << endl;
    } else {
        top--;
        arrayFilm[top] = {"", 0, 0};
    }
}

void displayArray() {
    if (isEmpty()) {
        cout << "Data kosong!!" << endl;
    } else {
        cout << "Data stack array : " << endl;
        for (int i = 0; i < top; i++) {
            cout << "Judul Film: " << arrayFilm[i].judul << endl;
            cout << "Harga: Rp. " << arrayFilm[i].harga << endl;
            cout << "Durasi: " << arrayFilm[i].durasi << " menit" << endl;
            cout << endl;
        }
    }
}

void peekArray(int posisi) {
    if (isEmpty()) {
        cout << "Data kosong!!" << endl;
    } else if (posisi > top || posisi <= 0) {
        cout << "Posisi tidak valid!!" << endl;
    } else {
        int index = posisi - 1;
        cout << "Data posisi ke-" << posisi << " : " << endl;
        cout << "Judul Film: " << arrayFilm[index].judul << endl;
        cout << "Harga: Rp. " << arrayFilm[index].harga << endl;
        cout << "Durasi: " << arrayFilm[index].durasi << " menit" << endl;
    }
}

void changeArray(Film data, int posisi) {
    if (isEmpty()) {
        cout << "Data kosong!!" << endl;
    } else if (posisi > top || posisi <= 0) {
        cout << "Posisi tidak valid!!" << endl;
    } else {
        int index = posisi - 1;
        arrayFilm[index] = data;
    }
}

int countArray() {
    return top;
}

void destroyArray() {
    for (int i = 0; i < top; i++) {
        arrayFilm[i] = {"", 0, 0};
    }
    top = 0;
}

struct dataFilm {
    string judul;
    int durasi;
    int harga;

    dataFilm *prev;
    dataFilm *next;
};

dataFilm *head = NULL, *tail = NULL, *cur = NULL, *newNode = NULL, *del = NULL;
int maksimalFilm = 5;

void createFilm(string judul, int durasi, int harga) {
    head = new dataFilm();
    head->judul = judul;
    head->durasi = durasi;
    head->harga = harga;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}

int countFilm() {
    int banyak = 0;
    cur = head;
    while (cur != NULL) {
        cur = cur->next;
        banyak++;
    }
    return banyak;
}

bool isFullFilm() {
    return countFilm() == maksimalFilm;
}

bool isEmptyFilm() {
    return countFilm() == 0;
}

void pushFilm(string judul, int durasi, int harga) {
    if (isFullFilm()) {
        cout << "Stack Full!!" << endl;
    } else {
        if (isEmptyFilm()) {
            createFilm(judul, durasi, harga);
        } else {
            newNode = new dataFilm();
            newNode->judul = judul;
            newNode->durasi = durasi;
            newNode->harga = harga;
            newNode->prev = tail;
            tail->next = newNode;
            newNode->next = NULL;
            tail = newNode;
        }
    }
}

void popFilm() {
    if (isEmptyFilm()) {
        cout << "Data kosong!!" << endl;
    } else {
        del = tail;
        if (tail->prev) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete del;
    }
}

void displayFilm() {
    if (isEmptyFilm()) {
        cout << "Data Film kosong" << endl;
    } else {
        cout << "\n\nData Film : " << endl;
        cur = tail;
        while (cur != NULL) {
            cout << "Judul Film: " << cur->judul << endl;
            cout << "Harga: Rp. " << cur->harga << endl;
            cout << "Durasi: " << cur->durasi << " menit" << endl;
            cout << endl;    
            cur = cur->prev;
        }
    }
}

void peekFilm(int posisi) {
    if (isEmptyFilm()) {
        cout << "Data Film kosong" << endl;
    } else if (posisi > countFilm() || posisi <= 0) {
        cout << "Posisi tidak valid!!" << endl;
    } else {
        int nomor = 1;
        cur = tail;
        while (nomor < posisi) {
            cur = cur->prev;
            nomor++;
        }
        cout << "Data Film Posisi ke-" << posisi << " : " << endl;
        cout << "Judul Film: " << cur->judul << endl;
        cout << "Harga: Rp. " << cur->harga << endl;
        cout << "Durasi: " << cur->durasi << " menit" << endl;
    }
}

void changeFilm(string judul, int durasi, int harga, int posisi) {
    if (isEmptyFilm()) {
        cout << "Data Film kosong" << endl;
    } else if (posisi > countFilm() || posisi <= 0) {
        cout << "Posisi tidak valid!!" << endl;
    } else {
        int nomor = 1;
        cur = tail;
        while (nomor < posisi) {
            cur = cur->prev;
            nomor++;
        }
        cur->judul = judul;
        cur->durasi = durasi;
        cur->harga = harga;
    }
}

void destroyFilm() {
    while (head != NULL) {
        del = head;
        head = head->next;
        delete del;
    }
    tail = NULL;
}

int main() {
    pushArray({"Ultraman Saga", 90, 45000});
    displayArray();
    pushArray({"The Nun 2", 120, 60000});
    pushArray({"The Walking Dead 2", 160, 90000});
    pushArray({"Power Ranger 2", 60, 25000});
    pushArray({"El Silbon", 120, 60000});
    displayArray();

    pushArray({"Toy Story 3", 180, 110000});
    displayArray();

    popArray();
    displayArray();

    cout << "Apakah data full ? : " << isFull() << endl;
    cout << "Apakah data kosong ? : " << isEmpty() << endl;

    peekArray(3);

    cout << "Banyak data : " << countArray() << endl;

    changeArray({"Database System", 140, 90000}, 2);
    displayArray();

    destroyArray();

    cout << "Apakah data full ? : " << isFull() << endl;
    cout << "Apakah data kosong ? : " << isEmpty() << endl;

    pushFilm("Ultraman Saga", 90, 45000);
    displayFilm();

    pushFilm("The Nun 2", 120, 60000);
    pushFilm("The Walking Dead 2", 160, 90000);
    pushFilm("Power Ranger 2", 60, 25000);
    pushFilm("El Silbon", 120, 60000);
    displayFilm();
    pushFilm("Toy Story 3", 180, 110000);
    displayFilm();

    cout << "Apakah data film full ? : " << isFullFilm() << endl;
    cout << "Apakah data film kosong ? : " << isEmptyFilm() << endl;
    cout << "Jumlah data film : " << countFilm() << endl;

    popFilm();
    displayFilm();

    peekFilm(3);

    changeFilm("Database System", 140, 90000, 2);
    displayFilm();

    destroyFilm();
    cout << "Apakah data film full ? : " << isFullFilm() << endl;
    cout << "Apakah data film kosong ? : " << isEmptyFilm() << endl;
    cout << "Jumlah data film : " << countFilm() << endl;
    displayFilm();

    return 0;
}