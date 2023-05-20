#ifndef petshop_H
#define petshop_H
#define anjing 0
#define kucing 1
#define kelinci 2

typedef struct
{
    int harga, jumlah, stok, waktu, key;
    char kategori[30];
    char jenis_hewan[30];
    char nama[50];
    char kode[5];
} petshop;

petshop barang[5];
petshop paket[5];

char kode_pil[99][5];
char kode_paket[99][5];
char jenis_hwn[10];

int z, y, w;
int nominal, kembalian, sa, pil;
int total_harga[5];

int keranjang();
int konfirmasi();
int konfirmasi2();

void belanja();
void perawatan();
void penitipan();
void menu();
void bayar(int n);
void bayar_penitipan(int n, int byk_hewan, int pil_h, int malam);
void bayar_paket(int n);
void DaftarBarang();
void struk(int n, int kembalian, int nominal, int sub_total);
void struk2(int n, int kembalian, int nominal, int sub_total);
void struk3(int n, int kembalian, int nominal, int sub_total, int byk_hewan, int malam);
void terimakasih();

void sorting(int n);
void sorting2(int n);

#endif
