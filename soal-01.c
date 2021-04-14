/*
    Usulan Soal M8
    Bucket fill by David Fauzi
*/

// Header
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void bucketFill(char **mat, int matRow, int matCol, int startX, int startY, char replacement)
{
    // 8 movement
    int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    // Buat queue
    Queue *q = createQueue(300);
    // enqueue pixel awal
    queueNode pixel = {startX, startY};
    enqueue(q, pixel);

    // color target
    int target = mat[startX][startY];

    // loop sampai gak nemu node queue baru lagi
    while (q->size != 0)
    {
        // dequeue front node
        queueNode node = front(q);
        dequeue(q);

        //  pixel saat ini
        int x = node.x;
        int y = node.y;

        // replace the current pixel color with that of replacement
        mat[x][y] = replacement;

        // looping untuk kedelapan tetangga disekitar pixel
        for (int k = 0; k < 8; k++)
        {
            // jika pixel adjadent (x + row[k], y + col[k]) valid dan
            // warnanya sama dengan pixel saat ini (yg mau direplace)
            // maka masukin pixel itu ke queue
            int xCheck = x + row[k], yCheck = y + col[k];
            if ((xCheck >= 0 && xCheck < matRow && yCheck >= 0 && yCheck < matCol) &&
                mat[xCheck][yCheck] == target)
            {
                // enqueue adjacent pixel
                queueNode new = {xCheck, yCheck};
                enqueue(q, new);
            }
        }
    }
}
char **createArr(int row_in, int col_in)
{
    char **grid;
    grid = malloc(row_in * sizeof(int *));
    for (int i = 0; i < row_in; i++)
    {
        grid[i] = malloc(col_in * sizeof(int));
    }
    return grid;
}

char **parseData(int *matrixRow, int *matrixCol, char filename[50])
{
    char temp[100];
    FILE *stream = fopen(filename, "r");
    fgets(temp, 30, stream);
    *matrixRow = atoi(temp);
    fgets(temp, 30, stream);
    *matrixCol = atoi(temp);
    char **mat = createArr(*matrixRow, *matrixCol);
    for (int i = 0; i < *matrixRow; i++)
    {
        fgets(temp, 100, stream);
        for (int j = 0; j < *matrixCol; j++)
        {
            mat[i][j] = temp[j];
        }
    }
    fclose(stream);
    return mat;
}

void displayImage(char **grid, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

Queue *createQueue(unsigned capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (queueNode *)malloc(queue->capacity * sizeof(queueNode));
    return queue;
}


void enqueue(Queue *queue, queueNode item)
{// asumsi tidak ada kasus queue full karena kapasitas sudah di set agar besar
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

void dequeue(Queue *queue)
{ // asumsi tidak ada kasus queue empty lalu di dequeue
    queueNode item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
}

queueNode front(Queue *queue) { return queue->array[queue->front]; }
