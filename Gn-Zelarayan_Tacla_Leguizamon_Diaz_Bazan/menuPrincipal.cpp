#include <conio.h>
#include <stdio.h>

void moduloConsultorios() {
    int opcion;
    bool continuar = true;

    while (continuar) {
        printf("\nModulo Consultorios\n");
        printf("=========================\n");
        printf("1.- Iniciar Sesion\n");
        printf("2.- Visualizar Lista de Espera de Turnos (informe)\n");
        printf("3.- Registrar Historia Clinica\n");
        printf("4.- Volver al menu principal\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Aqui va el codigo para iniciar sesion
                break;
            case 2:
                // Aqui va el codigo para mostrar la lista de espera de turnos
                break;
            case 3:
                // Aqui va el codigo para registrar la historia clinica
                break;
            case 4:
                printf("\nVolviendo al menu principal...\n");
                continuar = false;
                break;
            default:
                printf("\nOpcion invalida. Intenta de nuevo.\n");
        }
    }
}

void moduloRecepcionista() {
    int opcion;
    bool continuar = true;

    while (continuar) {
        printf("\nModulo del recepcionista\n");
        printf("=========================\n");
        printf("1.- Iniciar Sesion\n");
        printf("2.- Registrar Pacientes\n");
        printf("3.- Registrar Turno\n");
        printf("4.- Listado de Atenciones por Profesional y Fecha\n");
        printf("5.- Volver al menu principal\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Aqui va el codigo para iniciar sesion
                break;
            case 2:
                // Aqui va el codigo para registrar pacientes
                break;
            case 3:
                // Aqui va el codigo para registrar turno
                break;
            case 4:
                // Aqui va el codigo para mostrar el listado de atenciones
                break;
            case 5:
                printf("\nVolviendo al menu principal...\n");
                continuar = false;
                break;
            default:
                printf("\nOpcion invalida. Intenta de nuevo.\n");
        }
    }
}

void moduloAdministracion() {
    int opcion;
    bool continuar = true;

    while (continuar) {
        printf("\nModulo Administracion\n");
        printf("=========================\n");
        printf("1.- Registrar Profesionales\n");
        printf("2.- Registrar Usuario Recepcionista\n");
        printf("3.- Atenciones por Profesional\n");
        printf("4.- Ranking de Profesionales por Atenciones\n");
        printf("5.- Volver al menu principal\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Aqui va el codigo para registrar profesionales
                break;
            case 2:
                // Aqui va el codigo para registrar usuario recepcionista
                break;
            case 3:
                // Aqui va el codigo para mostrar las atenciones por profesional
                break;
            case 4:
                // Aqui va el codigo para mostrar el ranking de profesionales por atenciones
                break;
            case 5:
                printf("\nVolviendo al menu principal...\n");
                continuar = false;
                break;
            default:
                printf("\nOpcion invalida. Intenta de nuevo.\n");
        }
    }
}

int main() {
    int opcion;

    while (true) {
        printf("\nMenu Principal\n");
        printf("=========================\n");
        printf("1.- Modulo Consultorios\n");
        printf("2.- Modulo del Recepcionista\n");
        printf("3.- Modulo Administracion\n");
        printf("4.- Cerrar la aplicacion.\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                moduloConsultorios();
                break;
            case 2:
                moduloRecepcionista();
                break;
            case 3:
                moduloAdministracion();
                break;
            case 4:
                printf("\nCerrando la aplicacion...\n");
                return 0;
            default:
                printf("\nOpcion invalida. Intenta de nuevo.\n");
        }
    }
}
