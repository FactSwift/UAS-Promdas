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

void inputPemasukan(double *totalPemasukan, struct AkumulasiKategori kategori[], int *jumlahKategori) {
    double pemasukan;
    int test;

    do {
        printf("Masukkan pemasukan (masukkan 0 untuk kembali ke menu utama): ");
        test = scanf("%lf", &pemasukan);

        if (test == 0) {
            printf("Mohon masukkan angka untuk input.\n");
            fflush(stdin);

        } else if (pemasukan != 0) {
            *totalPemasukan += pemasukan;
        }
    } while (pemasukan != 0);
}
