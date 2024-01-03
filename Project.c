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

void inputKategori(struct PersentaseKategori persentaseKategori[], int *jumlahKategori) {

    *jumlahKategori = 0;
    double akumulasiPersen = 0.00;
    int i = 0;
    int test;

    for (int i = 0; i < CATEGORIES_MAX; i++) {
        while (getchar() != '\n');
        printf("Masukkan nama kategori %d (masukkan 0 untuk berhenti): ", i + 1);
        fgets(persentaseKategori[i].nama, sizeof(persentaseKategori[i].nama), stdin);
        persentaseKategori[i].nama[strcspn(persentaseKategori[i].nama, "\n")] = '\0';

        if (strcmp(persentaseKategori[i].nama, "0") == 0) {
            break;
        }

        printf("Masukkan persentase untuk kategori %s: ", persentaseKategori[i].nama);
        test = scanf("%f", &persentaseKategori[i].persentase);

        if (test == 0) {
            printf("Mohon masukkan angka untuk input: ");
            fflush(stdin);}

        akumulasiPersen += persentaseKategori[i].persentase;

        if (akumulasiPersen == 100) {
            printf("Berhasil! Kembali ke Menu Awal\n");
            (*jumlahKategori)++;
            break;
        }

        if (persentaseKategori[i].persentase < 0 || persentaseKategori[i].persentase > 100) {
            printf("Persentase tidak valid. Silakan masukkan persentase antara 0 dan 100.\n");
            printf("Persentase kategori tidak ditambahkan. Silakan coba lagi.\n");
            i--;
        } else {
            if (akumulasiPersen > 100) {
                printf("Akumulasi Persentase melebihi 100! Gagal Input Kategori %d\n", i + 1);
                akumulasiPersen -= persentaseKategori[i].persentase;
                i--;
            } else {
                (*jumlahKategori)++;
            }
        }
    }
}

void inputPengeluaran(double *totalPengeluaran, double totalPemasukan, struct AkumulasiKategori kategori[], struct PersentaseKategori persentaseKategori[], int jumlahKategori) {
    struct Transaksi pengeluaran;
    int kembaliKePilihanKategori;
    int test;

    if (jumlahKategori == 0) {
        printf("Silakan tambahkan kategori terlebih dahulu.\n");
        return;
    }

    do {
        printf("Pilih kategori pengeluaran:\n");
        for (int i = 0; i < jumlahKategori; i++) {
            printf("%d. %s\n", i + 1, persentaseKategori[i].nama);
        }

        int kategoriTerpilih;
        printf("Pilih nomor kategori (1-%d) atau 0 untuk kembali ke menu utama: ", jumlahKategori);
        scanf("%d", &kategoriTerpilih);

        if (kategoriTerpilih == 0) {
            return;
        }

        if (kategoriTerpilih < 1 || kategoriTerpilih > jumlahKategori) {
            printf("Nomor tidak terdaftar!.\n");
            return;
        }

        strcpy(pengeluaran.kategori, kategori[kategoriTerpilih - 1].nama);

        do {
            printf("Masukkan nominal pengeluaran (tekan 1 untuk kembali ke pilih kategori, tekan 0 untuk kembali ke menu utama): ");
            test = scanf("%lf", &pengeluaran.jumlah);

            if (test == 0) {
                printf("Mohon masukkan angka untuk input.\n");
                fflush(stdin);}

             else if (pengeluaran.jumlah == 1) {
                kembaliKePilihanKategori = 1;
                break;
            } else if (pengeluaran.jumlah != 0) {
                *totalPengeluaran += pengeluaran.jumlah;
                kategori[kategoriTerpilih - 1].totalJumlah += pengeluaran.jumlah;
                if (kategori[kategoriTerpilih - 1].totalJumlah > persentaseKategori[kategoriTerpilih - 1].persentase / 100 * totalPemasukan) {
                    printf("Pengeluaran anda melebihi batas!\n");
                }
            }
        } while (pengeluaran.jumlah != 0 && pengeluaran.jumlah != 1);
    } while (kembaliKePilihanKategori == 1);
}
