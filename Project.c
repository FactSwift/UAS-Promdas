#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CATEGORIES_MAX 99
#define CATEGORIES_NAMA 99

struct Transaksi {
    char kategori[50];
    double jumlah;
};

struct PersentaseKategori {
    char nama[50];
    float persentase;
};

struct AkumulasiKategori {
    char nama[50];
    double totalJumlah;
};
