#include <stdio.h>
#include <conio.h>

int main() {
    int opcion;
    bool sesion_iniciada = false;

    while (true) {
        printf("\nMódulo Administración\n");
        printf("=========================\n");
        printf("1.- Registrar Profesionales\n");
        printf("2.- Registrar Usuario Recepcionista\n");
        printf("3.- Atenciones por Profesional\n");
        printf("5.- Ranking de Profesionales por Atenciones\n");
        printf("6.- Cerrar la aplicación.\n\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (sesion_iniciada) {
                    printf("\nRegistrando profesionales...\n");
                    // Aquí iría el código para registrar profesionales
                } else {
                    printf("\nDebes iniciar sesión primero.\n");
                }
                break;
            case 2:
                if (sesion_iniciada) {
                    printf("\nRegistrando usuario recepcionista...\n");
                    // Aquí iría el código para registrar usuario recepcionista
                } else {
                    printf("\nDebes iniciar sesión primero.\n");
                }
                break;
            case 3:
                if (sesion_iniciada) {
                    printf("\nMostrando atenciones por profesional...\n");
                    // Aquí iría el código para mostrar las atenciones por profesional
                } else {
                    printf("\nDebes iniciar sesión primero.\n");
                }
                break;
            case 5:
                if (sesion_iniciada) {
                    printf("\nMostrando ranking de profesionales por atenciones...\n");
                    // Aquí iría el código para mostrar el ranking de profesionales por atenciones
                } else {
                    printf("\nDebes iniciar sesión primero.\n");
                }
                break;
            case 6:
                printf("\nCerrando la aplicación...\n");
                return 0;
            default:
                printf("\nOpción inválida. Inténtalo de nuevo.\n");
        }
    }
}
