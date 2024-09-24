#include <stdio.h>

void fusionar(int arreglo[], int inicio, int medio, int fin) {
    int i, j, k;
    int tamIzquierda = medio - inicio + 1;
    int tamDerecha = fin - medio;
    int Izquierda[tamIzquierda], Derecha[tamDerecha];

    // Copiar datos a los arreglos temporales Izquierda[] y Derecha[]
    for (i = 0; i < tamIzquierda; i++)
        Izquierda[i] = arreglo[inicio + i];
    for (j = 0; j < tamDerecha; j++)
        Derecha[j] = arreglo[medio + 1 + j];

    // Fusionar los arreglos temporales de nuevo en arreglo[inicio..fin]
    i = 0; // Índice inicial del primer subarreglo
    j = 0; // Índice inicial del segundo subarreglo
    k = inicio; // Índice inicial del subarreglo fusionado
    while (i < tamIzquierda && j < tamDerecha) {
        if (Izquierda[i] <= Derecha[j]) {
            arreglo[k] = Izquierda[i];
            i++;
        } else {
            arreglo[k] = Derecha[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de Izquierda[], si los hay
    while (i < tamIzquierda) {
        arreglo[k] = Izquierda[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de Derecha[], si los hay
    while (j < tamDerecha) {
        arreglo[k] = Derecha[j];
        j++;
        k++;
    }
}

void ordenFusion(int arreglo[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = inicio + (fin - inicio) / 2;

        ordenFusion(arreglo, inicio, medio);
        ordenFusion(arreglo, medio + 1, fin);

        fusionar(arreglo, inicio, medio, fin);
    }
}

// Función para imprimir un arreglo
void imprimirArreglo(int arreglo[], int tamano) {
    for (int i = 0; i < tamano; i++)
        printf("%d ", arreglo[i]);
}

void limpiarArreglo(int arreglo[], int tamano) {
    for (int i = 0; i < tamano; i++) {
        arreglo[i] = 0;
    }
}

int main() {
    int tamanoArreglo = 10;
    int arreglo[tamanoArreglo];
    for (int i = 0; i < tamanoArreglo; i++) {
        arreglo[i] = rand() % 100;
    }

    printf("Arreglo original: \n");
    imprimirArreglo(arreglo, tamanoArreglo);

    ordenFusion(arreglo, 0, tamanoArreglo - 1);

    printf("\nArreglo ordenado: \n");
    imprimirArreglo(arreglo, tamanoArreglo);
    
    limpiarArreglo(arreglo, tamanoArreglo);
    
    return 0;
}
