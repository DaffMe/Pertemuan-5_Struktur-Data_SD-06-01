#include <iostream>
#include "Singlylist.h"

using namespace std;

int main() {
    List L;
    address P1 = Nil, P2 = Nil, P3 = Nil, P4 = Nil, P5 = Nil;
    createList(L);

    // Modul 5 - Latihan 5.2
    // Soal No. 2:
    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    // Soal No. 3:
    address P_cari = findElm(L, 8);
    if (P_cari != Nil) {
        cout << P_cari->info << " ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }

    // Soal No. 4:
    int total = totalInfo(L);
    cout << "Total info dari kelima elemen adalah " << total << endl;

    return 0;
}
