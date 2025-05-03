#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int findLargestLine(int matrix[SIZE][SIZE]) {
    int largest = 0;
    int try = 0;
    int consecutivo = 0;
//comienza desde la diagonal principal hacia la esquina superiro derecha
    while (try < SIZE) {
        for (int i = 0; i < SIZE - try; i++) {
            if (matrix[i][i + try] == 1) {
                consecutivo = consecutivo + 1;
                if (consecutivo > largest) {
                    largest = consecutivo;
                }
            } else {
                consecutivo = 0;
            }
        }
        consecutivo = 0;
        try = try + 1;
    }
//comienza desde la izquierda de la diagonal central y se mueve hasta la esquina inferior derecha
    try = 1;
    consecutivo = 0;

    while (try < SIZE) {
        for (int i = 0; i < SIZE - try; i++) {
            if (matrix[i + try][i] == 1) {
                consecutivo = consecutivo + 1;
                if (consecutivo > largest) {
                    largest = consecutivo;
                }
            } else {
                consecutivo = 0;
            }
        }
        consecutivo = 0;
        try = try + 1;
    }

    try = 0;
    consecutivo = 0;
//ambos ciclos while hacen lo mismo pero analizan las diagonales desde la esquina superior derecha hacia la esquina inferior izquierda
    while (try < SIZE) {
        for (int i = 0; i < SIZE - try; i++) {
            if (matrix[i][SIZE - 1 - i - try] == 1) {
                consecutivo = consecutivo + 1;
                if (consecutivo > largest) {
                    largest = consecutivo;
                }
            } else {
                consecutivo = 0;
            }
        }
        consecutivo = 0;
        try = try + 1;
    }

    try = 1;
    consecutivo = 0;

    while (try < SIZE) {
        for (int i = 0; i < SIZE - try; i++) {
            if (matrix[i + try][SIZE - 1 - i] == 1) {
                consecutivo = consecutivo + 1;
                if (consecutivo > largest) {
                    largest = consecutivo;
                }
            } else {
                consecutivo = 0;
            }
        }
        consecutivo = 0;
        try = try + 1;
    }

    printf("La diagonal con mas 1s consecutivos contiene:");
    printf("%3d", largest);
    printf("\n");

    return largest;
}

int main() {
    int matrix[SIZE][SIZE];

    srand(time(NULL));
//se rellena la matriz con 0s y 1s aleatorios
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            matrix[i][j] = rand() % 2;
        }
    }
    printf("\nLa matriz utilizada corresponde a:\n");
    printf("\n");

    for (int i = 0; i<SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }

    findLargestLine(matrix);

    return 0;
}

