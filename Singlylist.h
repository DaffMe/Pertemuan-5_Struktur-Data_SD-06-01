#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
#include "boolean.h"

#define Nil NULL

using namespace std;

// Definisi Tipe Data
typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

// Primitif ADT Singly Linked List (Modul 5 Latihan No. 2)

void CreateList(List &L);
void createList(List &L); // alias lowercase sesuai modul

address alokasi(infotype x);
void dealokasi(address &P);

void printInfo(List L);

void insertFirst(List &L, address P);

// Primitif Pencarian (Modul 5 Latihan No. 3)

address findElm(List L, infotype x);

// Primitif Perhitungan Total Info (Modul 5 Latihan No. 4)
int totalInfo(List L);

// Primitif Tambahan Singly Linked List
bool ListEmpty(List L);
int nbList(List L);
void insertLast(List &L, address P);
void insertAfter(List &L, address P, address Prec);
void delFirst(List &L, address &P);
void delLast(List &L, address &P);
void delAfter(List &L, address &P, address Prec);
void delAll(List &L);

#endif 
