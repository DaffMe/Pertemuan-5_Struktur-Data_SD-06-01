# Praktikum Struktur Data - Modul 5: Singly Linked List (Bagian 2)
## Dokumentasi & Penyelesaian Latihan Subbab 5.2

Repositori ini memuat implementasi dan pengujian Abstract Data Type (ADT) **Singly Linked List** berbasis bahasa C++ untuk tugas praktikum Struktur Data, khususnya pada **Modul 5 (Singly Linked List Bagian Kedua) - Subbab 5.2 Latihan**.

---

## 📁 Struktur Berkas Proyek

Berikut rincian berkas sumber (*source code*) yang menyusun proyek ini:

| Berkas | Keterangan |
| :--- | :--- |
| `Singlylist.h` | Berkas *header* yang memuat definisi tipe data ADT (`infotype`, `address`, `ElmList`, `List`) serta deklarasi prototipe fungsi dan prosedur. |
| `Singlylist.cpp` | Berkas implementasi logika dari seluruh fungsi dan prosedur ADT Singly Linked List. |
| `main.cpp` | Program penguji (*driver*) yang mengeksekusi skenario tugas latihan nomor 2, 3, dan 4. |
| `boolean.h` | Berkas pendukung definisi tipe dan nilai logika (`boolean`, `true`, `false`) sesuai format modul. |

---

## 📌 Rincian & Analisis Pengerjaan Latihan

### 1. Latihan No. 2 — Perancangan ADT & Pengisian Data ke List

Pada latihan ini, dibuat struktur dasar linked list serta operasi penyisipan data ke elemen terdepan:

* **Struktur Tipe Data:**
  * `infotype`: data integer (`int`) yang ditampung pada simpul.
  * `address`: tipe pointer penunjuk ke simpul (`ElmList*`).
  * `ElmList`: simpul (*node*) yang terdiri dari komponen `info` (`infotype`) dan pointer penerus `next` (`address`).
  * `List`: struktur pembungkus list yang memegang pointer kepala/simpul pertama (`First`).

* **Primitif Pokok yang Digunakan:**
  * `createList(List &L)`: Menginisialisasi list baru agar bernilai kosong (`L.First = Nil`).
  * `alokasi(infotype x)`: Mengalokasikan memori dinamis untuk elemen baru berisi data `x`.
  * `dealokasi(address &P)`: Mengembalikan ruang memori elemen `P` ke sistem.
  * `insertFirst(List &L, address P)`: Memasukkan simpul `P` ke urutan pertama pada list `L`.
  * `printInfo(List L)`: Melakukan penelusuran (*traversal*) dan menampilkan isi elemen dalam list.

* **Alur Pengisian Data (Mengacu Gambar 5-1):**
  Elemen dialokasikan dan disisipkan secara berurutan menggunakan prosedur `insertFirst`:
  ```cpp
  P1 = alokasi(2);  insertFirst(L, P1);
  P2 = alokasi(0);  insertFirst(L, P2);
  P3 = alokasi(8);  insertFirst(L, P3);
  P4 = alokasi(12); insertFirst(L, P4);
  P5 = alokasi(9);  insertFirst(L, P5);
  ```
  Mengingat `insertFirst` menaruh setiap data baru di posisi terdepan (`First`), susunan akhir dari list adalah:
  ```text
  [First] -> [ 9 ] -> [ 12 ] -> [ 8 ] -> [ 0 ] -> [ 2 ] -> Nil
  ```

* **Hasil Luaran Latihan No. 2 (Gambar 5-2):**
  ```text
  9 12 8 0 2
  ```

---

### 2. Latihan No. 3 — Pencarian Elemen List (`findElm`)

Latihan ini bertujuan mengimplementasikan pencarian data simpul berdasarkan nilai `info`:

* **Prototipe Fungsi:**
  ```cpp
  address findElm(List L, infotype x);
  ```

* **Mekanisme Kerja:**
  1. Penelusuran dimulai dari simpul awal list (`L.First`).
  2. Program memeriksa apakah nilai simpul saat ini (`P->info`) sama dengan `x`.
  3. Jika nilai ditemukan, fungsi mengembalikan alamat memori pointer `P`.
  4. Jika penelusuran mencapai ujung list (`Nil`) tanpa kecocokan, fungsi mengembalikan nilai `Nil`.

* **Pengujian Simpul dengan Nilai 8 (Gambar 5-3):**
  ```cpp
  address P_cari = findElm(L, 8);
  if (P_cari != Nil) {
      cout << P_cari->info << " ditemukan dalam list" << endl;
  } else {
      cout << "8 tidak ditemukan dalam list" << endl;
  }
  ```
  *Luaran Konsol:*
  ```text
  8 ditemukan dalam list
  ```

---

### 3. Latihan No. 4 — Perhitungan Total Nilai Elemen (`totalInfo`)

Latihan ini menghitung jumlah kumulatif dari seluruh elemen yang ada pada list:

* **Prototipe Fungsi:**
  ```cpp
  int totalInfo(List L);
  ```

* **Mekanisme Kerja:**
  1. Melakukan traversal satu per satu dari simpul pertama hingga simpul terakhir.
  2. Menjumlahkan seluruh nilai `info` setiap node:
     $$9 + 12 + 8 + 0 + 2 = 31$$
  3. Mengembalikan nilai hasil penjumlahan tersebut.

* **Pengujian Fungsi (Gambar 5-4):**
  ```cpp
  int total = totalInfo(L);
  cout << "Total info dari kelima elemen adalah " << total << endl;
  ```
  *Luaran Konsol:*
  ```text
  Total info dari kelima elemen adalah 31
  ```

---

## 🛠️ Panduan Kompilasi dan Eksekusi

### 1. Menggunakan Command Line / Terminal (g++)

Jalankan perintah berikut di dalam direktori proyek:

```bash
g++ main.cpp Singlylist.cpp -o main
./main
```
*(Pada sistem operasi Windows, jalankan dengan `./main.exe`)*

### 2. Menggunakan Code::Blocks IDE

1. Buka aplikasi **Code::Blocks**.
2. Buat proyek baru melalui menu: **File > New > Project... > Console Application > C++**.
3. Masukkan seluruh berkas (`Singlylist.h`, `Singlylist.cpp`, dan `main.cpp`) ke dalam proyek yang dibuat.
4. Tekan tombol **F9** (*Build and Run*) untuk mengompilasi sekaligus menjalankan program.

---

## 📊 Hasil Eksekusi Program

Berikut tangkapan output lengkap saat program dijalankan:

```text
9 12 8 0 2 
8 ditemukan dalam list
Total info dari kelima elemen adalah 31
```
