#include "Singlylist.h"

// Primitif ADT Singly Linked List (Modul 5 Latihan No. 2)

void CreateList(List &L) {
    L.First = Nil;
}

void createList(List &L) {
    CreateList(L);
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    if (P != Nil) {
        P->next = L.First;
        L.First = P;
    }
}

// Primitif Pencarian (Modul 5 Latihan No. 3)

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// Primitif Perhitungan Total Info (Modul 5 Latihan No. 4)

int totalInfo(List L) {
    int total = 0;
    address P = L.First;
    while (P != Nil) {
        total += P->info;
        P = P->next;
    }
    return total;
}

// Primitif Tambahan Singly Linked List

bool ListEmpty(List L) {
    return (L.First == Nil);
}

int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void insertLast(List &L, address P) {
    if (P != Nil) {
        if (L.First == Nil) {
            L.First = P;
        } else {
            address Q = L.First;
            while (Q->next != Nil) {
                Q = Q->next;
            }
            Q->next = P;
        }
        P->next = Nil;
    }
}

void insertAfter(List &L, address P, address Prec) {
    if (P != Nil && Prec != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void delFirst(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
    } else {
        P = L.First;
        L.First = P->next;
        P->next = Nil;
    }
}

void delLast(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
    } else if (L.First->next == Nil) {
        P = L.First;
        L.First = Nil;
    } else {
        address Q = L.First;
        while (Q->next->next != Nil) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = Nil;
    }
}

void delAfter(List &L, address &P, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    } else {
        P = Nil;
    }
}

void delAll(List &L) {
    address P;
    while (L.First != Nil) {
        delFirst(L, P);
        dealokasi(P);
    }
}
