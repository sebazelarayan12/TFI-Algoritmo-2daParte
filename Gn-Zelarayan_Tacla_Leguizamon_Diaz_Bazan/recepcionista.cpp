#include <stdio.h>
#include <conio.h>


int main() {
    int opcion;
    bool sesion_iniciada = false;

    while (true) {
        printf("\nModulo del recepcionista\n");
        printf("=========================\n");
        printf("1.- Iniciar Sesión\n");
        printf("2.- Registrar Pacientes\n");
        printf("3.- Registrar Turno\n");
        printf("4.- Listado de Atenciones por Profesional y Fecha\n");
        printf("5.- Cerrar la aplicación.\n\n");
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
                    printf("\nRegistrando pacientes...\n");
                    // Aquí iría el código para registrar pacientes
                } else {
                    printf("\nDebes iniciar sesión primero.\n");
                }
                break;
            case 3:
                if (sesion_iniciada) {
                    printf("\nRegistrando turno...\n");
                    // Aquí iría el código para registrar turno
                } else {
                    printf("\nDebes iniciar sesión primero.\n");
                }
                break;
            case 4:
                if (sesion_iniciada) {
                    printf("\nMostrando listado de atenciones por profesional y fecha...\n");
                    // Aquí iría el código para mostrar el listado de atenciones
                } else {
                    printf("\nDebes iniciar sesión primero.\n");
                }
                break;
            case 5:
                printf("\nCerrando la aplicación...\n");
                return 0;
            default:
                printf("\nOpción inválida. Inténtalo de nuevo.\n");
        }
    }
}
