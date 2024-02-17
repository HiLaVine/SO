#include <windows.h>
#include <stdio.h>

DWORD WINAPI funcion_hilo(LPVOID lpParam) {
    // Código a ejecutar en el hilo
    printf("Hola desde el hilo\n");
    return 0;
}

int main() {
    HANDLE hilo;
    
    // Crear el hilo
    hilo = CreateThread(NULL, 0, funcion_hilo, NULL, 0, NULL);
    if (hilo == NULL) {
        printf("Error al crear el hilo. Código de error: %ld\n", GetLastError());
        return 1;
    }
    
    // Esperar a que el hilo termine
    WaitForSingleObject(hilo, INFINITE);
    
    printf("Hola desde el hilo principal\n");
    return 0;
}
