#include <cstdio>
using namespace std;

int main() {
    int opcion;
    bool sesion_iniciada = false;

    while (true) {
        printf("\nModulo Consultorios\n");
        printf("=========================\n");
        printf("1.- Iniciar Sesión\n");
        printf("2.- Visualizar Lista de Espera de Turnos (informe)\n");
        printf("3.- Registrar Historia Clínica\n");
        printf("4.- Cerrar la aplicación.\n\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (sesion_iniciada) {
                    printf("\nYa has iniciado sesión.\n");
                } else {
                    printf("\nIniciando sesión...\n");
                    // Aquí iría el código para iniciar sesión
                    sesion_iniciada = true;
                }
                break;
            case 2:
                if (sesion_iniciada) {
                    printf("\nMostrando lista de espera de turnos...\n");
                    // Aquí iría el código para mostrar la lista de espera de turnos
                } else {
                    printf("\nDebes iniciar sesión primero.\n");
                }
                break;
            case 3:
                if (sesion_iniciada) {
                    printf("\nRegistrando historia clínica...\n");
                    // Aquí iría el código para registrar la historia clínica
                } else {
                    printf("\nDebes iniciar sesión primero.\n");
                }
                break;
            case 4:
                printf("\nCerrando la aplicación...\n");
                return 0;
            default:
                printf("\nOpción inválida. Inténtalo de nuevo.\n");
        }
    }
}
