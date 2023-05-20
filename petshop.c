#include "petshop.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <windows.h>

void DaftarBarang()
{
    barang[0].key = 156;
    barang[0].harga = 45500;
    barang[0].stok = 25;
    strcpy(barang[0].kode, "156");
    strcpy(barang[0].nama, "Wiskas  ");
    strcpy(barang[0].jenis_hewan, "Kucing");
    strcpy(barang[0].kategori, "Kesehatan");

    barang[1].key = 236;
    barang[1].harga = 5000;
    barang[1].stok = 15;
    strcpy(barang[1].kode, "236");
    strcpy(barang[1].nama, "Kalung  ");
    strcpy(barang[1].jenis_hewan, "Anjing");
    strcpy(barang[1].kategori, "kecantikan");

    barang[2].key = 863;
    barang[2].harga = 16500;
    barang[2].stok = 12;
    strcpy(barang[2].kode, "863");
    strcpy(barang[2].nama, "Sisir   ");
    strcpy(barang[2].jenis_hewan, "Kucing");
    strcpy(barang[2].kategori, "Kesehatan");

    barang[3].key = 353;
    barang[3].harga = 22000;
    barang[3].stok = 50;
    strcpy(barang[3].kode, "353");
    strcpy(barang[3].nama, "Sampo   ");
    strcpy(barang[3].jenis_hewan, "Anjing");
    strcpy(barang[3].kategori, "Kesehatan");

    barang[4].key = 626;
    barang[4].harga = 83000;
    barang[4].stok = 6;
    strcpy(barang[4].kode, "626");
    strcpy(barang[4].nama, "Pasir   ");
    strcpy(barang[4].jenis_hewan, "Kucing");
    strcpy(barang[4].kategori, "Kesehatan");
}

void DaftarPaket()
{
    paket[0].key = 726;
    paket[0].harga = 40000;
    strcpy(paket[0].kode, "726");
    strcpy(paket[0].nama, "grooming   ");
    strcpy(paket[0].jenis_hewan, "Kucing");
    strcpy(paket[0].kategori, "Kesehatan");

    paket[1].key = 124;
    paket[1].harga = 35000;
    strcpy(paket[1].kode, "124");
    strcpy(paket[1].nama, "cuci telinga");
    strcpy(paket[1].jenis_hewan, "Kucing");
    strcpy(paket[1].kategori, "kecantikan");

    paket[2].key = 332;
    paket[2].harga = 28000;
    strcpy(paket[2].kode, "332");
    strcpy(paket[2].nama, "keramas    ");
    strcpy(paket[2].jenis_hewan, "Anjing");
    strcpy(paket[2].kategori, "Kecantikan");

    paket[3].key = 552;
    paket[3].harga = 12000;
    strcpy(paket[3].kode, "552");
    strcpy(paket[3].nama, "potong kuku");
    strcpy(paket[3].jenis_hewan, "Kucing");
    strcpy(paket[3].kategori, "Kesehatan");

    paket[4].key = 458;
    paket[4].harga = 72000;
    strcpy(paket[4].kode, "458");
    strcpy(paket[4].nama, "mandi kutu  ");
    strcpy(paket[4].jenis_hewan, "Kucing");
    strcpy(paket[4].kategori, "Kesehatan");
}

void belanja()
{
    int i, jumlah_beli;
    z = 0;
belanja:
    system("cls");
    printf("+=======================================================+\n");
    printf("|Kode   |Nama   \t|Jenis Hewan\t|Harga  |Stok\t|\n");
    printf("+=======================================================+\n");
    for (i = 0; i < 5; i++)
    {
        printf("|%s\t|%s\t|%s\t\t|%d\t|%d\t|\n", barang[i].kode, barang[i].nama, barang[i].jenis_hewan, barang[i].harga, barang[i].stok);
    }
    printf("+=======================================================+\n");

    printf("Cari Kode Barang yang mau dibeli: ");
    scanf("%s", kode_pil[z]);
    system("cls");
    printf("+=======================================================+\n");
    printf("|Kode   |Nama   \t|Jenis Hewan\t|Harga  |Stok\t|\n");
    printf("+=======================================================+\n");

    for (i = 0; i < 5; i++)
    {
        if (strstr(barang[i].kode, kode_pil[z]) != NULL)
        {
            printf("|%s\t|%s\t|%s\t\t|%d\t|%d\t|\n", barang[i].kode, barang[i].nama, barang[i].jenis_hewan, barang[i].harga, barang[i].stok);
        }
    }

    int st = 0;
    st = keranjang();
    if (st != 1)
    {
        goto belanja;
    }
    printf("=========================================================\n");
    if (st == 1)
    {
        for (i = 0; i < 5; i++)
        {
            if (strstr(barang[i].kode, kode_pil[z]) != NULL)
            {
                printf("Barang berhasil ditambah! Stok barang tersisa %d barang \n", barang[i].stok);
                printf("=========================================================\n");
                printf("Masukkan jumlah barang yang dibeli: ");
                scanf("%d", &barang[i].jumlah);
                if (barang[i].jumlah > barang[i].stok)
                {
                    printf("=========================================================\n");
                    printf("Maaf, stok hanya tersisa %d!", barang[i].stok);
                    Sleep(3000);
                    goto belanja;
                }
                barang[i].stok = barang[i].stok - barang[i].jumlah;
            }
        }
    }
    z++;
tambah1:
    system("cls");
    printf("=========================================================\n");
    printf("1. Bayar\n2. Tambah Barang\n");
    printf("=========================================================\n");
    printf("Pilih Menu: ");
    scanf("%d", &pil);
    switch (pil)
    {
    case 1:
        bayar(z);
        break;
    case 2:
        goto belanja;
        break;
    default:
        printf("=========================================================\n");
        printf("Pilihan tidak tersedia\n");
        printf("=========================================================\n");
        Sleep(3000);
        goto tambah1;
        break;
    }
}

void perawatan()
{
    int i, jumlah_beli;
    y = 0;
perawatan:
    system("cls");
    printf("+===============================================+\n");
    printf("|Kode\t|Nama Paket\t|Jenis Hewan\t|Harga  |\n");
    printf("+===============================================+\n");
    for (i = 0; i < 5; i++)
    {
        printf("|%s\t|%s\t|%s\t\t|%d\t|\n", paket[i].kode, paket[i].nama, paket[i].jenis_hewan, paket[i].harga);
    }
    printf("+===============================================+\n");

    printf("Cari Nama Paket yang mau dipilih: ");
    scanf("%s", kode_paket[y]);
    system("cls");
    printf("+===============================================+\n");
    printf("|Kode\t|Nama Paket\t|Jenis Hewan\t|Harga  |\n");
    printf("+===============================================+\n");

    for (i = 0; i < 5; i++)
    {
        if (strstr(paket[i].nama, kode_paket[y]) != NULL)
        {
            printf("|%s\t|%s\t|%s\t\t|%d\t|\n", paket[i].kode, paket[i].nama, paket[i].jenis_hewan, paket[i].harga);
        }
    }

    int st;
    st = konfirmasi();
    if (st != 1)
    {
        goto perawatan;
    }

    if (st == 1)
    {
        for (i = 0; i < 5; i++)
        {
            if (strstr(paket[i].nama, kode_paket[y]) != NULL)
            {
                printf("Masukkan banyak hewan yang akan diproses: ");
                scanf("%d", &paket[i].jumlah);
            }
        }
    }

    y++;
tambah2:
    system("cls");
    printf("=================================================\n");
    printf("1. Bayar\n2. Tambah Paket lainnya\n");
    printf("=================================================\n");
    printf("Pilih Menu: ");
    scanf("%d", &pil);
    switch (pil)
    {
    case 1:
        bayar_paket(y);
        break;
    case 2:
        goto perawatan;
        break;
    default:
        printf("=================================================\n");
        printf("Pilihan tidak tersedia\n");
        printf("=================================================\n");
        Sleep(3000);
        goto tambah2;
        break;
    }
}

void penitipan()
{
    int i, jumlah_beli, pil, pil_h, byk_hewan, malam;
    char *dftr_hewan[3] = {'\0'};
    dftr_hewan[0] = "anjing";
    dftr_hewan[1] = "kucing";
    dftr_hewan[2] = "kelinci";

    w = 0;
penitipan:
    system("cls");
    printf("=========================================================\n");
    printf("Daftar Hewan yang bisa dititipkan :\n1. Anjing\n2. Kucing\n3. Kelinci\n");
    printf("=========================================================\n");

    printf("Pilih hewan yang akan Anda titipkan : ");
    scanf("%d", &pil_h);

    if (pil_h > 3 || pil_h < 1)
    {
        printf("=========================================================\n");
        printf("Maaf! hewan tidak tersedia\n");
        printf("=========================================================\n");
        Sleep(3000);
        goto penitipan;
    }

    int st;
    st = konfirmasi2();
    if (st != 1)
    {
        goto penitipan;
    }

    system("cls");
    printf("=========================================================\n");
    switch (pil_h)
    {
    case 1:
        strcpy(jenis_hwn, dftr_hewan[anjing]);
        printf("Harga penitipan seekor %s adalah 45 rb per malam.\nFasilitas dan pelayanan yang didapat berupa makanan hewan\n3x sehari dan 1 buah keranjang hewan ukuran %s. ", dftr_hewan[anjing], dftr_hewan[anjing]);
        st;
        break;
    case 2:
        strcpy(jenis_hwn, dftr_hewan[kucing]);
        printf("Harga penitipan seekor %s adalah 45 rb per malam.\nFasilitas dan pelayanan yang didapat berupa makanan hewan\n3x sehari dan 1 buah keranjang hewan ukuran %s. ", dftr_hewan[kucing], dftr_hewan[kucing]);
        st;
        break;
    case 3:
        strcpy(jenis_hwn, dftr_hewan[kelinci]);
        printf("Harga penitipan seekor %s adalah 45 rb per malam.\nFasilitas dan pelayanan yang didapat berupa makanan hewan\n3x sehari dan 1 buah keranjang hewan ukuran %s. ", dftr_hewan[kelinci], dftr_hewan[kelinci]);
        st;
        break;
    default:
        printf("Maaf Anda memasukkan angka yang salah");
        break;
    }
    printf("\n=========================================================");
    if (st == 1)
    {
        printf("\nMasukkan banyak hewan yang akan diproses: ");
        scanf("%d", &byk_hewan);
        printf("=========================================================");
        printf("\nBerapa malam hewan Anda akan dititipkan: ");
        scanf("%d", &malam);
    }
    bayar_penitipan(w, byk_hewan, pil_h, malam);
}

void bayar(int n)
{
    int sub_total = 0;
    int i, pil;
    for (i = 0; i < 5; i++)
    {
        total_harga[i] = 0;
    }
    system("cls");
    printf("+===============================================================+\n");
    printf("|Kode   |Nama   \t|Jumlah Barang\t|Harga  |Total\t\t|\n");
    printf("+===============================================================+\n");

    for (n = 0; n < z; n++)
    {
        for (i = 0; i < 5; i++)
        {
            if (strstr(barang[i].kode, kode_pil[n]) != NULL)
            {
                total_harga[i] = barang[i].jumlah * barang[i].harga;
                sub_total = sub_total + total_harga[i];
            }
        }
    }

    sorting(n);

    for (i = 0; i < 5; i++)
    {
        if ((strstr(barang[i].kode, kode_pil[n]) != NULL) && barang[i].jumlah > 0)
        {
            printf("|%d\t|%s\t|%d\t\t|%d\t|Rp.%d\t|\n", barang[i].key, barang[i].nama, barang[i].jumlah, barang[i].harga, total_harga[i]);
        }
    }
    printf("+===============================================================+\n");
    printf("SUBTOTAL: Rp.%d\n", sub_total);
bayar1:
    printf("=================================================================\n");
    printf("Masukkan nominal uang Anda: Rp.");
    scanf("%d", &nominal);
    printf("=================================================================\n");

    if (nominal > sub_total)
    {
        kembalian = nominal - sub_total;
        printf("Terimakasih, kembalian Anda sebesar Rp.%d\n", kembalian);
    }
    else if (nominal == sub_total)
    {
        printf("Terimakasih telah membayar sebesar Rp.%d\n", nominal);
    }
    else
    {
        printf("Maaf uang Anda kurang, karena total yang harus dibayar\nsebesar Rp.%d\n", sub_total);
        goto bayar1;
    }
    printf("=================================================================\n");
    struk(n, kembalian, nominal, sub_total);
    printf("\n=================================================================\n");
    printf("1. Kembali ke HOME PAGE\n2. Keluar\nPilih Menu: ");
    scanf("%d", &pil);
    switch (pil)
    {
    case 1:
        menu();
        break;
    case 2:
        printf("=================================================================\n");
        terimakasih();
        printf("=================================================================\n");

        break;
    default:
        printf("=================================================================\n");
        printf("Pilihan tidak tersedia\n");
        printf("=================================================================\n");
        break;
    }
}

void bayar_paket(int n)
{
    int sub_total = 0;
    int i, pil;
    system("cls");

    printf("+===============================================================+\n");
    printf("|Kode   |Nama Paket  |Jumlah Barang\t|Harga  |Total\t\t|\n");
    printf("+===============================================================+\n");

    for (n = 0; n < y; n++)
    {
        for (i = 0; i < 5; i++)
        {
            total_harga[i] = paket[i].jumlah * paket[i].harga;
            sub_total = sub_total + total_harga[i];
        }
    }

    sorting2(n);
    for (i = 0; i < 5; i++)
    {
        if ((strstr(paket[i].kode, kode_pil[n]) != NULL) && paket[i].jumlah > 0)
        {
            printf("|%d\t|%s\t|%d\t\t|%d\t|Rp.%d\t|\n", paket[i].key, paket[i].nama, paket[i].jumlah, paket[i].harga, total_harga[i]);
        }
    }

    sub_total = sub_total / y;

    printf("=================================================================\n");
    printf("SUBTOTAL: Rp.%d\n", sub_total);
bayar2:
    printf("=================================================================");
    printf("\nMasukkan nominal uang Anda: Rp.");
    scanf("%d", &nominal);
    printf("=================================================================\n");

    if (nominal > sub_total)
    {
        kembalian = nominal - sub_total;
        printf("Terimakasih, kembalian Anda sebesar Rp.%d\n", kembalian);
    }
    else if (nominal == sub_total)
    {
        printf("Terimakasih telah membayar sebesar Rp.%d\n", nominal);
    }
    else
    {
        printf("Maaf uang Anda kurang, karena total yang harus\ndibayar sebesar Rp.%d\n", sub_total);
        goto bayar2;
    }

    printf("=================================================================\n");
    struk2(n, kembalian, nominal, sub_total);
    printf("\n=================================================================\n");
    printf("1. Kembali ke HOME PAGE\n2. Keluar\nPilih Menu: ");
    scanf("%d", &pil);
    switch (pil)
    {
    case 1:
        menu();
        break;
    case 2:
        printf("=================================================================\n");
        terimakasih();
        printf("=================================================================\n");
        break;
    default:
        printf("=================================================================\n");
        printf("Pilihan tidak tersedia\n");
        printf("=================================================================\n");

        break;
    }
}

void bayar_penitipan(int n, int byk_hewan, int pil_h, int malam)
{
    int sub_total = 0;
    int i, pil;
    system("cls");
    printf("+===============================================================+\n");
    printf("|Jenis Hewan\t|Jumlah Hewan\t|Waktu Penitipan|Total Harga\t|\n");
    printf("+===============================================================+\n");

    total_harga[0] = byk_hewan * 45000 * malam;
    sub_total = sub_total + total_harga[0];
    printf("|%s  \t|%d\t\t|%d\t\t|Rp.%d\t|\n", jenis_hwn, byk_hewan, malam, total_harga[0]);

    printf("+===============================================================+\n");
    printf("SUBTOTAL: Rp.%d\n", sub_total);
bayar3:
    printf("=================================================================\n");
    printf("Masukkan nominal uang Anda: Rp.");
    scanf("%d", &nominal);
    printf("=================================================================\n");
    if (nominal > sub_total)
    {
        kembalian = nominal - sub_total;
        printf("Terimakasih, kembalian Anda sebesar Rp.%d\n", kembalian);
    }
    else if (nominal == sub_total)
    {
        printf("Terimakasih telah membayar sebesar Rp.%d\n", nominal);
    }
    else
    {
        printf("Maaf uang Anda kurang, karena total yang harus dibayar\nsebesar Rp.%d\n", sub_total);
        goto bayar3;
    }

    printf("=================================================================\n");
    struk3(n, kembalian, nominal, sub_total, byk_hewan, malam);
    printf("\n=================================================================\n");
    printf("1. Kembali ke HOME PAGE\n2. Keluar\nPilih Menu: ");
    scanf("%d", &pil);
    switch (pil)
    {
    case 1:
        menu();
        break;
    case 2:
        printf("=================================================================\n");
        terimakasih();
        printf("=================================================================\n");
        break;
    default:
        printf("=================================================================\n");
        printf("Pilihan tidak tersedia\n");
        printf("=================================================================\n");
        break;
    }
}

void sorting(int n)
{
    int k = 5;
    int i, j, p, q, r, s, t;
    char temp[100];
    char temp_nama[100];

    for (i = 0; i < k - 1; i++)
    {
        for (j = 0; j < (k - i - 1); j++)
        {
            if (barang[j].key > barang[j + 1].key)
            {

                strcpy(temp, barang[j].kode);
                strcpy(barang[j].nama, barang[j + 1].kode);
                strcpy(barang[j + 1].kode, temp);

                strcpy(temp_nama, barang[j].nama);
                strcpy(barang[j].nama, barang[j + 1].nama);
                strcpy(barang[j + 1].nama, temp_nama);

                p = barang[j].jumlah;
                barang[j].jumlah = barang[j + 1].jumlah;
                barang[j + 1].jumlah = p;

                q = barang[j].harga;
                barang[j].harga = barang[j + 1].harga;
                barang[j + 1].harga = q;

                r = total_harga[j];
                total_harga[j] = total_harga[j + 1];
                total_harga[j + 1] = r;

                s = barang[j].key;
                barang[j].key = barang[j + 1].key;
                barang[j + 1].key = s;
            }
        }
    }

    strcpy(barang[4].nama, "Sisir   ");
}

void sorting2(int n)
{
    int k = 5;
    int i, j, p, q, r, s, t;
    char temp[100];
    char temp_nama[100];

    for (i = 0; i < k - 1; i++)
    {
        for (j = 0; j < (k - i - 1); j++)
        {
            if (paket[j].key > paket[j + 1].key)
            {

                strcpy(temp, paket[j].kode);
                strcpy(paket[j].nama, paket[j + 1].kode);
                strcpy(paket[j + 1].kode, temp);

                strcpy(temp_nama, paket[j].nama);
                strcpy(paket[j].nama, paket[j + 1].nama);
                strcpy(paket[j + 1].nama, temp_nama);

                p = paket[j].jumlah;
                paket[j].jumlah = paket[j + 1].jumlah;
                paket[j + 1].jumlah = p;

                q = paket[j].harga;
                paket[j].harga = paket[j + 1].harga;
                paket[j + 1].harga = q;

                r = total_harga[j];
                total_harga[j] = total_harga[j + 1];
                total_harga[j + 1] = r;

                s = paket[j].key;
                paket[j].key = paket[j + 1].key;
                paket[j + 1].key = s;
            }
        }
    }

    strcpy(paket[4].nama, "grooming   ");
}

void terimakasih()
{
    printf("Terimakasih telah berkunjung ke Toko kami :)\n");
}

void struk(int n, int kembalian, int nominal, int sub_total)
{
    int i;
    sub_total = 0;
    FILE *fp;
    fp = fopen("struk.txt", "w");

    for (n = 0; n < z; n++)
    {
        for (i = 0; i < 5; i++)
        {
            if (strstr(barang[i].kode, kode_pil[n]) != NULL)
            {
                total_harga[i] = barang[i].jumlah * barang[i].harga;
                sub_total = sub_total + total_harga[i];
            }
        }
    }

    fprintf(fp, "+=======================================================+\n");
    fprintf(fp, "                STRUK TRANSAKSI PETSHOP D\n");
    fprintf(fp, "+=======================================================+\n");
    fprintf(fp, "+=======================================================+\n");
    fprintf(fp, "|Kode \t|   Nama\t|Jumlah Barang|Harga |Total\t\t|\n");
    fprintf(fp, "+=======================================================+\n");

    for (i = 0; i < 5; i++)
    {
        if ((strstr(barang[i].kode, kode_pil[n]) != NULL) && barang[i].jumlah > 0)
        {
            fprintf(fp, "|%s\t|%s\t|%d\t\t|%d\t|Rp.%d   \t|\n", barang[i].kode, barang[i].nama, barang[i].jumlah, barang[i].harga, total_harga[i]);
        }
    }

    fprintf(fp, "+=======================================================+\n");
    fprintf(fp, "SUBTOTAL: Rp.%d\n", sub_total);
    fprintf(fp, "=========================================================\n");
    fprintf(fp, "Nominal uang Anda: Rp.%d\n", nominal);
    if (nominal > sub_total)
    {
        fprintf(fp, "=========================================================\n");
        fprintf(fp, "Kembalian Anda sebesar Rp.%d\n", kembalian);
    }
    fprintf(fp, "=========================================================\n");
    fprintf(fp, "     TERIMAKASIH TELAH BERKUNJUNG KE PETSHOP KAMI !\n");
    fprintf(fp, "=========================================================\n");

    fclose(fp);

    printf("STRUK BERHASIL DICETAK!");
}

void struk2(int n, int kembalian, int nominal, int sub_total)
{
    int i;
    FILE *fq;
    fq = fopen("struk.txt", "w");
    sub_total = 0;

    for (n = 0; n < y; n++)
    {
        for (i = 0; i < 5; i++)
        {
            if (strstr(paket[i].kode, kode_pil[n]) != NULL)
            {
                total_harga[i] = paket[i].jumlah * paket[i].harga;
                sub_total = sub_total + total_harga[i];
            }
        }
    }

    fprintf(fq, "+=======================================================+\n");
    fprintf(fq, "                STRUK TRANSAKSI PETSHOP D\n");
    fprintf(fq, "+=======================================================+\n");
    fprintf(fq, "+=======================================================+\n");
    fprintf(fq, "|Kode \t|   Nama\t|Jumlah Barang|Harga |Total\t\t|\n");
    fprintf(fq, "+=======================================================+\n");

    for (i = 0; i < 5; i++)
    {
        if ((strstr(paket[i].kode, kode_pil[n]) != NULL) && paket[i].jumlah > 0)
        {
            fprintf(fq, "|%s\t|%s\t|%d\t\t|%d\t|Rp.%d   \t|\n", paket[i].kode, paket[i].nama, paket[i].jumlah, paket[i].harga, total_harga[i]);
        }
    }
    sub_total = sub_total / y;
    fprintf(fq, "+=======================================================+\n");
    fprintf(fq, "SUBTOTAL: Rp.%d\n", sub_total);
    fprintf(fq, "+=======================================================+\n");
    fprintf(fq, "Nominal uang Anda: Rp.%d\n", nominal);

    if (nominal > sub_total)
    {
        fprintf(fq, "=========================================================\n");
        fprintf(fq, "Kembalian Anda sebesar Rp.%d\n", kembalian);
    }
    fprintf(fq, "=========================================================\n");
    fprintf(fq, "   TERIMAKASIH TELAH BERKUNJUNG KE PETSHOP KAMI !\n");
    fprintf(fq, "=========================================================\n");

    fclose(fq);

    printf("STRUK BERHASIL DICETAK!");
}

void struk3(int n, int kembalian, int nominal, int sub_total, int byk_hewan, int malam)
{
    int i;
    FILE *fq;
    fq = fopen("struk.txt", "w");
    sub_total = 0;

    fprintf(fq, "+=========================================================+\n");
    fprintf(fq, "                  STRUK TRANSAKSI PETSHOP D\n");
    fprintf(fq, "+=========================================================+\n");
    fprintf(fq, "+=========================================================+\n");
    fprintf(fq, "|Jenis Hewan\t|Jumlah Hewan\t|Waktu Penitipan|Total Harga  |\n");
    fprintf(fq, "+=========================================================+\n");

    total_harga[0] = byk_hewan * 45000 * malam;
    sub_total = sub_total + total_harga[0];
    fprintf(fq, "|%s    \t|%d\t\t|%d\t\t  |Rp.%d\t  |\n", jenis_hwn, byk_hewan, malam, total_harga[0]);

    fprintf(fq, "+=========================================================+\n");
    fprintf(fq, "SUBTOTAL: Rp.%d\n", sub_total);
    fprintf(fq, "===========================================================\n");
    fprintf(fq, "Nominal uang Anda: Rp.%d\n", nominal);

    if (nominal > sub_total)
    {
        fprintf(fq, "===========================================================\n");
        fprintf(fq, "Kembalian Anda sebesar Rp.%d\n", kembalian);
    }
    fprintf(fq, "===========================================================\n");
    fprintf(fq, "       TERIMAKASIH TELAH BERKUNJUNG KE PETSHOP KAMI !\n");
    fprintf(fq, "===========================================================\n");

    fclose(fq);

    printf("STRUK BERHASIL DICETAK!");
}

int konfirmasi()
{
    int stat = 0;
    char bt[4];
    printf("=================================================\n");
    printf("Konfirmasi dan lanjutkan? (ya/tidak) : ");
    scanf("%s", &bt);
    fgetc(stdin);
    printf("=================================================\n");

    if (strstr(bt, "ya") != NULL)
    {
        stat = 1;
    }
    return stat;
}

int konfirmasi2()
{
    int stat = 0;
    char bt[4];
    printf("=========================================================\n");
    printf("Konfirmasi dan lanjutkan? (ya/tidak) : ");
    scanf("%s", &bt);
    fgetc(stdin);
    printf("=========================================================\n");

    if (strstr(bt, "ya") != NULL)
    {
        stat = 1;
    }
    return stat;
}

int keranjang()
{
    int stat = 0;
    char bt[4];
    printf("+=======================================================+\n");
    printf("Tambah ke Troli? (ya/tidak) : ");
    scanf("%s", &bt);
    fgetc(stdin);

    if (strstr(bt, "ya") != NULL)
    {
        stat = 1;
    }
    return stat;
}

void menu()
{

    int pil;
menu:
    system("cls");
    printf("=========================================================\n");
    printf("               MENU PETSHOP KELOMPOK D\n");
    printf("=========================================================\n");
    printf("1. Belanja Barang\n2. Jasa Perawatan\n3. Jasa Penitipan\n4. Keluar\n");
    printf("=========================================================\n");

    DaftarBarang();
    printf("Masukkan pilihan: ");
    scanf("%d", &pil);
    fgetc(stdin);
    switch (pil)
    {
    case 1:
        belanja();
        break;
    case 2:
        perawatan();
        break;
    case 3:
        penitipan();
        break;
    case 4:
        printf("Anda telah berhasil keluar!\n");
        break;
    default:
        printf("Pilihan Anda tidak tersedia, silahkan coba lagi!\n\n");
        goto menu;
        break;
    }
}
