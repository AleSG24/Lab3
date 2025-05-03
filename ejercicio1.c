#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numero;

    printf("Ingresa el numero de filas y columnas de la matriz cuadrada: ");
    scanf("%d", &numero);

    int matriz[numero][numero];

    srand(time(NULL));

    //Esta linea rellena la matriz cuadrada con numeros aleatorios generados por la semilla anterior
    for(int i=0; i < numero; i++) {
        for (int j = 0; j < numero; j++) {
            matriz[i][j] = rand() % 100;
        }
    }

    //Imprime la matriz generada en la terminal
    printf("\nMatriz generada:\n");

    for (int i = 0; i < numero; i++) {
        for (int j = 0; j < numero; j++) {
            printf("%3d", matriz[i][j]);
        }
        printf("\n");
    }
    
    //Suma la diagonal de la matriz e imprime su resultado 
    int suma;
    suma = 0;
    for (int i=0; i < numero; i++){
        suma = suma + matriz[i][i];
    }
    
    printf("La suma de la diagonal de la matriz anterior es la siguiente: ");
    printf("%3d", suma);
    printf("\n");



return 0;

}