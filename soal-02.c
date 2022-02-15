/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : Overview of C Language
*Percobaan        : -
*Hari dan Tanggal : Rabu, 16 Februari 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-02.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    // Input Angka Han
    printf("Masukkan angka Han: ");
    int input_han_number;
    scanf("%d", &input_han_number);
    int digit_han_number = 0;
    int temp = 1;
    while(input_han_number >= temp){
        digit_han_number += 1;
        temp *= 10;
    }

    // Pisah angka han berdasarkan digit.
    int han_number[digit_han_number];
    temp /= 10;
    for(int i = digit_han_number-1 ;i >= 0;i--){
        han_number[i] = input_han_number/temp;
        input_han_number = input_han_number -input_han_number/temp*temp;
        if(temp > 1){
            temp/=10;
        }
    }

    // Input basis han
    printf("Masukkan jumlah basis Han: ");
    int digit_basis_han;
    int max_basis_han;
    scanf("%d", &digit_basis_han);
    int basis_han[digit_han_number];
    for(int i = digit_han_number-1; i >= (digit_han_number-1)-(digit_basis_han-1);i--){
        printf("Masukkan basis Han indeks ke %d: ",(digit_basis_han-1)-((digit_han_number-1)-i));
        scanf("%d",&basis_han[i]);
        // Cari sekaligus nilai maksimum basis
        if(i == digit_han_number-1){
            max_basis_han = basis_han[i];
        }
        else{
            if(max_basis_han < basis_han[i]){
                max_basis_han = basis_han[i];
            }
        }
    }
    // Print untuk debugging
    // printf("max basis han = %d\n",max_basis_han);

    // Hitung angka han tahap 1
    // Sesuaikan isi array digit basis han
    if(digit_basis_han < digit_han_number){
        for(int i = (digit_han_number-1)-(digit_basis_han-1)-1; i>=0;i--){
            basis_han[i] = basis_han[i + digit_basis_han];
        }
    }
    // Lakukan perhitungan
    int han_result_1 = 0;
    for(int i=0;i<digit_han_number;i++){
        temp = 1;
        for (int j=0;j<i;j++){
            temp *= basis_han[i];
        }
        han_result_1 += temp*han_number[i];
    }
    // Print untuk debugging
    // printf("Han result 1 : %d\n",han_result_1);
    // Konversi Han Result ke digitnya masing-masing
    int digit_han_result_1 = 0;
    temp = 1;
    while(han_result_1 >= temp){
        digit_han_result_1 += 1;
        temp *= 10;
    }

    // Pisah angka han berdasarkan digit.
    int han_result_1_arr[digit_han_result_1-1];
    temp /= 10;
    for(int i = digit_han_result_1-1 ;i >= 0;i--){
        han_result_1_arr[i] = han_result_1/temp;
        han_result_1 = han_result_1 - han_result_1/temp*temp;
        if(temp > 1){
            temp/=10;
        }
        // Pencarian nilai maksimum
        if(max_basis_han < han_result_1_arr[i]){
            max_basis_han = han_result_1_arr[i];
        }
    }

    // Penyesuaian nilai berdasarkan nilai basis maksimum dan perhitungan nilai akhir
    int han_result_final = 0;
    for(int i = digit_han_result_1-1; i>=0; i--){
        if(han_result_1_arr[i] == max_basis_han){
            han_result_1_arr[i] = max_basis_han-1;
        }
        temp = 1;
        for (int j=0;j<i;j++){
            temp *= max_basis_han;
        }
        han_result_final += han_result_1_arr[i]*temp;
    }

    // Tampilkan hasil decode angka Han
    printf("Hasil decode angka Han adalah %d",han_result_final);

    // Debug array
    // for(int i=digit_han_number-1; i >= 0;i--){
    //     printf("han_number[%d]=%d ", i,han_number[i]);
    // }
    // printf("\n");
    // for(int i=digit_han_number-1; i >= 0;i--){
    //     printf("basis_han[%d]=%d ", i,basis_han[i]);
    // }
    // printf("\n");
    // for(int i=digit_han_result_1-1; i >= 0;i--){
    //     printf("han_result_1[%d]=%d ", i,han_result_1_arr[i]);
    // }
    // printf("\n");
    // printf("max basis han = %d\n",max_basis_han);
    return 0;
}
