#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10

// Struktur untuk menyimpan data transaksi
struct Transaksi {
    char kategori[50];
    double jumlah;
};

// Struktur untuk membuat persentase kategori
struct PersentaseKategori {
    char nama[50];
    float persentase;
};

// Struktur untuk menyimpan informasi kategori
struct AkumulasiKategori {
    char nama[50];
    double totalJumlah;
};
