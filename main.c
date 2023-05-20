/*
Program  : Program Mengelola Toko Petshop
NRP-Nama :  162021018 - Alfius Stevanus Ginting
            162019004 - Puteri Brilian
            162021001 - M.Hilmy Aiman.
            162021015 - Kevin Salomon
            162021017 - Reihandi Putra Z.
Tanggal Pengumpulan : 02-06-2022
Praktikum: Tugas Besar Grup D
*/

#include "petshop.c"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <windows.h>
int main()
{
    int i, j;
    DaftarBarang();
    DaftarPaket();
    menu();
    return 0;
}
