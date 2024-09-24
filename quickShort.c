#include <stdio.h>

void intercambiar(int* x, int* y) {
    int temporal = *x;
    *x = *y;
    *y = temporal;
}

int particion(int arreglo[], int bajo, int alto) {
    int pivote = arreglo[alto];
    int i = (bajo - 1);

    for (int j = bajo; j <= alto - 1; j++) {
        if (arreglo[j] <= pivote) {
            i++;
            intercambiar(&arreglo[i], &arreglo[j]);
        }
    }
    intercambiar(&arreglo[i + 1], &arreglo[alto]);
    return (i + 1);
}

void ordenRapido(int arreglo[], int bajo, int alto) {
    if (bajo < alto) {
        int indiceParticion = particion(arreglo, bajo, alto);
        ordenRapido(arreglo, bajo, indiceParticion - 1);
        ordenRapido(arreglo, indiceParticion + 1, alto);
    }
}

// Función para imprimir el arreglo
void imprimirArreglo(int arreglo[], int tamano) {
    for (int i = 0; i < tamano; ++i) {
        printf("%d  ", arreglo[i]);
    }
    printf("\n");
}

int main() {
    int datos[] = {33, 12, 15, 16, 23, 56, 32, 1, 23, 56, 32, 16, 88, 76, 43, 23};
    int tamano = sizeof(datos) / sizeof(datos[0]);

    printf("Arreglo original\n");
    imprimirArreglo(datos, tamano);

    ordenRapido(datos, 0, tamano - 1);

    printf("Arreglo Organizado\n");
    imprimirArreglo(datos, tamano);

    return 0;
}
