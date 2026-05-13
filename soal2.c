/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 3
 *   Hari dan Tanggal    : Rabu, 13 Mei 2026
 *   Nama (NIM)          : Khairina Safira Nurazizah (13224021)
 *   Nama File           : soal2
 *   Deskripsi           : menghitung jumlah pulau dan ukuran pulau terbesar pada grid biner, di mana sel bernilai 1 menunjukkan wilayah aktif 
                           dan sel bernilai 0 menunjukkan wilayah kosong. wilayah aktif yang terhubung secara vertikal atau horizontal 
                           dianggap sebagai satu pulau.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>

int jumlahBaris;
int jumlahKolom;
char peta[50][50];

int hitungPulauSize (int baris, int kolom){
    if (baris < 0 || baris >= jumlahBaris || kolom < 0 || kolom >= jumlahKolom){
        return 0;
    }
    if (peta[baris][kolom] == '0'){
        return 0;
    }

    peta[baris][kolom] = '0';

    int sizePulau = 1;

    sizePulau = sizePulau + hitungPulauSize(baris - 1, kolom);
    sizePulau = sizePulau + hitungPulauSize(baris + 1, kolom);
    sizePulau = sizePulau + hitungPulauSize(baris, kolom - 1);
    sizePulau = sizePulau + hitungPulauSize(baris, kolom + 1);

    return sizePulau;
}


int main(){
    int jumlahPulau = 0;
    int largestPulau = 0;

    scanf("%d %d", &jumlahBaris, &jumlahKolom);

    for(int baris = 0; baris<jumlahBaris; baris++){
        scanf("%s", peta[baris]);
    }

    for(int baris = 0; baris<jumlahBaris; baris++){
        for(int kolom = 0; kolom<jumlahKolom; kolom++){
            if(peta[baris][kolom] == '1'){
                jumlahPulau++;

                int ukuranSekarang = hitungPulauSize(baris, kolom);

                if(ukuranSekarang > largestPulau){
                    largestPulau = ukuranSekarang;
                }
            }
        }
    }

    printf("ISLANDS %d\n", jumlahPulau);
    printf("LARGEST %d\n", largestPulau);
}


/*
sources:
https://www.geeksforgeeks.org/c/c-program-for-find-the-number-of-islands-set-1-using-dfs/
https://www.w3schools.com/c/c_arrays_multi.php
https://www.programiz.com/c-programming/c-recursion

*/
