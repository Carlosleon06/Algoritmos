#include <stdio.h>
#include <stdbool.h>

//prototipos
int sumaRecursiva(int arr[], int n);
bool existeNumero(int arr[], int n, int num);


int sumaRecursiva(int arr[], int n) {
    if (n == 0)  
        return 0;
    else
        return arr[n - 1] + sumaRecursiva(arr, n - 1);
}

bool existeNumero(int arr[], int n, int num) {
    if (n == 0)  
        return false;
    if (arr[n - 1] == num)  
        return true;
    return existeNumero(arr, n - 1, num);  
}

int main() {
    int n, i, opcion, buscar;

    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &n);

    int arr[n];  

    printf("Ingrese los %d elementos del arreglo:\n", n);
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n--- MENU ---\n");
        printf("1. Sumar todos los elementos\n");
        printf("2. Buscar un numero en el arreglo\n");
        printf("3. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("La suma de los elementos es: %d\n", sumaRecursiva(arr, n));
                break;

            case 2:
                printf("Ingrese el numero a buscar: ");
                scanf("%d", &buscar);
                if (existeNumero(arr, n, buscar))
                    printf("El numero %d SI existe en el arreglo\n", buscar);
                else
                    printf("El numero %d NO existe en el arreglo\n", buscar);
                break;

            case 3:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 3);

    return 0;
}
