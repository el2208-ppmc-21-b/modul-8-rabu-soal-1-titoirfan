/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
*   Modul               : 
*   Soal                : 
*   Hari dan Tanggal    : 
*   Nama (NIM)          : 
*   Asisten (NIM)       : 
*   Nama File           : 
*   Deskripsi           : 
*/

/*
    Template Kode M8
    Bucket fill by David Fauzi
*/

// Header
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  INSTRUKSI PENGERJAAN : 
    fungsi untuk membuat matriks dinamis dan parsing data dari .txt ke matrix telah dibuatkan, 
    struct Queue beserta isi node nya sudah dibuatkan, fungsi main() juga sudah dibuatkan
    Praktikan hanya perlu mengisi implementasi fungsi" queue, algoritma utama, dan fungsi display matriks
*/

// Deklarasi struct
typedef struct // Simpan koordinat sel matriks
{
    int x;
    int y;
} queueNode;

typedef struct // Queue
{
    int front, rear, size;
    unsigned capacity;
    queueNode *array;
} Queue;

// Definisi dari fungsi yang digunakan

// FUNGSI YANG SUDAH DIBERIKAN IMPLEMENTASINYA
/*  Alokasikan memori untuk matriks 2D lalu return pointer dari elemen pertama matriks  */
char **createArr(int row_in, int col_in);
/* Parsing gambar dari file .txt lalu return pointer dari elemen pertama matriks gambar  */
char **parseData(int *matrixRow, int *matrixCol, char filename[50]);

// FUNGSI YANG IMPLEMENTASINYA HARUS DIISIKAN PRAKTIKAN
// Dapat membuat fungsi baru jika dirasa perlu
/*Alokasikan memori untuk Queue lalu return pointer dari Queue*/
Queue *createQueue(unsigned capacity);
/* enqueue/push queue dari rear */
void enqueue(Queue *queue, queueNode item);
/* dequeue/pop queue dari front */
void dequeue(Queue *queue);
/* fungsi peek (melihat node paling depan tanpa di-dequeue) */
queueNode front(Queue *queue);

/* cetak kondisi matrix gambar saat ini */
void displayImage(char **grid, int row, int col);
/* algoritma utama untuk bucket fill  */
void bucketFill(char **mat, int matRow, int matCol, int startX, int startY, char replacement);

int main()
{
    char inputUser[100];
    int startX, startY;
    char replacement;
    char **matrix;
    int matrixRow, matrixCol; // dimensi matriks
    printf("Nama file: ");
    scanf("%s", inputUser);                                // nama file gambar
    matrix = parseData(&matrixRow, &matrixCol, inputUser); // parse data dari file .txt
    printf("\nGambar:\n");
    displayImage(matrix, matrixRow, matrixCol); //tampilkan gambar awal
    printf("Masukan koordinat pixel yang ingin diklik serta warna penggantinya\n");
    printf("Titik X(baris): ");
    scanf("%d", &startX); // koordinat x (baris) pixel
    printf("Titik Y(kolom): ");
    scanf("%d", &startY); // koordinat y (kolom) pixel
    printf("Ganti warna menjadi: ");
    scanf(" %c", &replacement); // Warna replacement
    printf("Titik (%d,%d) dengan warna %c -> %c\n\n", startX, startY, matrix[startX-1][startY-1],replacement);
    bucketFill(matrix, matrixRow, matrixCol, startX - 1, startY - 1, replacement);
    // startX - 1, startY - 1 karena baris dan kolom dalam rentang [1-N] sedangkan array [0-(N-1)]
    printf("Gambar setelah di bucket fill:\n\n");
    displayImage(matrix, matrixRow, matrixCol); // gambar setelah di paint bucket
    return 0;
}

Queue *createQueue(unsigned capacity)
{
    /*Isi implementasi fungsinya disini*/
}

void enqueue(Queue *queue, queueNode item)
{ // asumsi tidak ada kasus queue full karena kapasitas sudah di set agar selalu cukup

    /*Isi implementasi fungsinya disini*/
}

void dequeue(Queue *queue)
{ // asumsi sudah tidak ada lagi kasus queue empty lalu di dequeue

    /*Isi implementasi fungsinya disini*/
}

queueNode front(Queue *queue)
{
    /*Isi implementasi fungsinya disini*/
}

void bucketFill(char **mat, int matRow, int matCol, int startX, int startY, char replacement)
{
    /*Isi implementasi fungsinya disini*/
}

void displayImage(char **grid, int row, int col)
{
    /*Isi implementasi fungsinya disini*/
}
