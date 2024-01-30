#include <conio.h>
#include <stdio.h>
#include <cctype>
#include <cstring>

bool esNombreUsuarioValido(const char* nombreUsuario) {
    int longitud = strlen(nombreUsuario);
    if (longitud < 6 || longitud > 10) {
        return false;
    }
    if (!islower(nombreUsuario[0])) {
        return false;
    }
    int contadorMayusculas = 0;
    int contadorDigitos = 0;
    for (int i = 0; i < longitud; ++i) {
        if (isupper(nombreUsuario[i])) {
            ++contadorMayusculas;
        } else if (isdigit(nombreUsuario[i])) {
            ++contadorDigitos;
        } else if (!islower(nombreUsuario[i]) && strchr("+-/*?¿!¡", nombreUsuario[i]) == NULL) {
            return false;
        }
    }
    if (contadorMayusculas < 2 || contadorDigitos > 3) {
        return false;
    }
    return true;
}

bool esContrasenaValida(const char* contrasena) {
    int longitud = strlen(contrasena);
    if (longitud < 6 || longitud > 32) {
        return false;
    }
    bool tieneMayuscula = false;
    bool tieneMinuscula = false;
    bool tieneDigito = false;
    for (int i = 0; i < longitud; ++i) {
        if (isupper(contrasena[i])) {
            tieneMayuscula = true;
        } else if (islower(contrasena[i])) {
            tieneMinuscula = true;
        } else if (isdigit(contrasena[i])) {
            tieneDigito = true;
        } else {
            return false;
        }
        if (i >= 2 && isdigit(contrasena[i]) && isdigit(contrasena[i-1]) && isdigit(contrasena[i-2])) {
            return false;
        }
        if (i >= 1 && ((islower(contrasena[i]) && islower(contrasena[i-1]) && contrasena[i] == contrasena[i-1] + 1) ||
                       (isupper(contrasena[i]) && isupper(contrasena[i-1]) && contrasena[i] == contrasena[i-1] + 1))) {
            return false;
        }
    }
    return tieneMayuscula && tieneMinuscula && tieneDigito;
}

bool iniciarSesion(){

    char nombreUsuario[11];
    char contrasena[33];

    printf("\nIngresar nombre de usuario: ");
            scanf("%10s", nombreUsuario);
            printf("Ingresar contrasena: ");
            scanf("%32s", contrasena);
            if (esNombreUsuarioValido(nombreUsuario) && esContrasenaValida(contrasena)) {
                printf("\nInicio de sesion exitoso.\n");
                return true;
            } else {
                printf("\nNombre de usuario o contrasena invalidos.\n");
                return false;
            }
}

void moduloConsultorios() {
    int opcion;
    bool continuar = true;
    bool sesion_iniciada = false;
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
                iniciarSesion();
                break;
            case 2:
                if (sesion_iniciada) {
                    // Aqui va el codigo para mostrar la lista de espera de turnos
                } else {
                    printf("\nDebes iniciar sesion primero.\n");
                }
                break;
            case 3:
                if (sesion_iniciada) {
                    // Aqui va el codigo para registrar la historia clinica
                } else {
                    printf("\nDebes iniciar sesion primero.\n");
                }
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
    bool sesion_iniciada = false;
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
                iniciarSesion();
                sesion_iniciada = true;
                break;
            case 2:
                if (sesion_iniciada) {
                    // Aqui va el codigo para registrar pacientes
                } else {
                    printf("\nDebes iniciar sesion primero.\n");
                }
                break;
            case 3:
                if (sesion_iniciada) {
                    // Aqui va el codigo para registrar turno
                } else {
                    printf("\nDebes iniciar sesion primero.\n");
                }
                break;
            case 4:
                if (sesion_iniciada) {
                    // Aqui va el codigo para mostrar el listado de atenciones
                } else {
                    printf("\nDebes iniciar sesion primero.\n");
                }
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
    bool sesion_iniciada = false;
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
                if (sesion_iniciada) {
                    // Aqui va el codigo para registrar profesionales
                } else {
                    printf("\nDebes iniciar sesion primero.\n");
                }
                break;
            case 2:
                if (sesion_iniciada) {
                    // Aqui va el codigo para registrar usuario recepcionista
                } else {
                    printf("\nDebes iniciar sesion primero.\n");
                }
                break;
            case 3:
                if (sesion_iniciada) {
                    // Aqui va el codigo para mostrar las atenciones por profesional
                } else {
                    printf("\nDebes iniciar sesion primero.\n");
                }
                break;
            case 4:
                if (sesion_iniciada) {
                    // Aqui va el codigo para mostrar el ranking de profesionales por atenciones
                } else {
                    printf("\nDebes iniciar sesion primero.\n");
                }
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
