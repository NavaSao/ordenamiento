#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenar(int arreglo[], int tamano){
    for (int i = 0; i < tamano - 1; i++){
        for(int j = 0; j < tamano - i - 1; j++){
            if(arreglo[j] > arreglo[j + 1]){
                int temporal = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temporal;
            }
        }
    }
}

int main(){
    int tamano = 30; 
    int arreglo[tamano];
    srand(time(0));

    for (int i = 0; i < tamano; i++){
        arreglo[i] = rand() % 100; 
    }

    printf("Arreglo desordenado:\n");
    for(int i = 0; i < tamano; i++){
        printf("%d, ", arreglo[i]);
    }

    printf("\n");

    ordenar(arreglo, tamano);
    printf("Arreglo ordenado:\n");
    for(int i = 0; i < tamano; i++){
        printf("%d ", arreglo[i]);
    }

    printf("\n");
    return 0;
}
