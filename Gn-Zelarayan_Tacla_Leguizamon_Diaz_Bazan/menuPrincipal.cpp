#include <conio.h>
#include <stdio.h>
#include <cctype>
#include <cstring>
#include <string.h>

struct Fecha
{
    int dia;
    int mes;
    int ano;
};

struct Usuarios
{
    char Usuario[11];
    char Contrasena[33];
    char ApellidoNombre[60];
};

struct Profesionales
{
    char ApellidoNombre[60];
    int IdProfesional;
    int Dni;
    char Telefono[25];
};

struct Pacientes
{
    char ApellidoNombre[60];
    char Domicilio[60];
    int DniPaciente;
    char Localidad[60];
    Fecha FechadeNacimiento;
    char Telefono[25];
};

struct Turnos
{
    int IdProfesional;
    Fecha fecha;
    int DniPaciente;
    char DetalledeAtencion[380];
};

bool esNombreUsuarioValido(const char *nombreUsuario)
{
    int longitud = strlen(nombreUsuario);
    if (longitud < 6 || longitud > 10)
    {
        return false;
    }
    if (!islower(nombreUsuario[0]))
    {
        return false;
    }
    int contadorMayusculas = 0;
    int contadorDigitos = 0;
    for (int i = 0; i < longitud; ++i)
    {
        if (isupper(nombreUsuario[i]))
        {
            ++contadorMayusculas;
        }
        else if (isdigit(nombreUsuario[i]))
        {
            ++contadorDigitos;
        }
        else if (!islower(nombreUsuario[i]) && strchr("+-/*?¿!¡", nombreUsuario[i]) == NULL)
        {
            return false;
        }
    }
    if (contadorMayusculas < 2 || contadorDigitos > 3)
    {
        return false;
    }
    return true;
}

bool esContrasenaValida(const char *contrasena)
{
    int longitud = strlen(contrasena);
    if (longitud < 6 || longitud > 32)
    {
        return false;
    }
    bool tieneMayuscula = false;
    bool tieneMinuscula = false;
    bool tieneDigito = false;
    for (int i = 0; i < longitud; ++i)
    {
        if (isupper(contrasena[i]))
        {
            tieneMayuscula = true;
        }
        else if (islower(contrasena[i]))
        {
            tieneMinuscula = true;
        }
        else if (isdigit(contrasena[i]))
        {
            tieneDigito = true;
        }
        else
        {
            return false;
        }
        if (i >= 2 && isdigit(contrasena[i]) && isdigit(contrasena[i - 1]) && isdigit(contrasena[i - 2]))
        {
            return false;
        }
        if (i >= 1 && ((islower(contrasena[i]) && islower(contrasena[i - 1]) && contrasena[i] == contrasena[i - 1] + 1) ||
                       (isupper(contrasena[i]) && isupper(contrasena[i - 1]) && contrasena[i] == contrasena[i - 1] + 1)))
        {
            return false;
        }
    }
    return tieneMayuscula && tieneMinuscula && tieneDigito;
}

void crearNuevoRecepcionista()
{
    Usuarios nuevoRecepcionista;
    char opcion;

    do
    {
        printf("Introduce el Usuario (máximo 11 caracteres): ");
        scanf("%11s", nuevoRecepcionista.Usuario);

        printf("Introduce la Contraseña (máximo 33 caracteres): ");
        scanf("%33s", nuevoRecepcionista.Contrasena);

        if (esNombreUsuarioValido(nuevoRecepcionista.Usuario) && esContrasenaValida(nuevoRecepcionista.Contrasena))
        {
            printf("Introduce el NombreApellido (máximo 60 caracteres): ");
            scanf("%60s", nuevoRecepcionista.ApellidoNombre);
            printf("\nUsuario creado con exito.\n");
            FILE *file = fopen("Recepcionistas.dat", "ab");
            if (file == NULL)
            {
                printf("No se pudo abrir el archivo.\n");
                return;
            }

            fwrite(&nuevoRecepcionista, sizeof(Usuarios), 1, file);
            fclose(file);
            return; // Termina la función una vez que se crea el usuario
        }
        else
        {
            printf("\nNombre de usuario o contrasena invalidos.\n");
            printf("¿Deseas intentarlo de nuevo? (s/n): ");
            scanf(" %c", &opcion); // El espacio antes de %c ignora los espacios en blanco
        }
    } while (opcion == 's' || opcion == 'S');
}



void crearUsuarioProvisorio()
{

    Usuarios usuario;
    FILE *archivo;

    // Copia los datos en la estructura de usuario
    snprintf(usuario.Usuario, sizeof(usuario.Usuario), "sebazelarayan12");
    snprintf(usuario.Contrasena, sizeof(usuario.Contrasena), "12345678");
    snprintf(usuario.ApellidoNombre, sizeof(usuario.ApellidoNombre), "Zelarayan Sebastian");

    // Abre el archivo para escritura
    archivo = fopen("Recepcionistas.dat", "wb");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo para escritura\n");
    }

    // Escribe la estructura de usuario en el archivo
    fwrite(&usuario, sizeof(Usuarios), 1, archivo);

    // Cierra el archivo
    fclose(archivo);

    printf("Usuario guardado exitosamente\n");
}

void moduloConsultorios()
{
    int opcion;
    bool continuar = true;
    bool sesion_iniciada = false;
    while (continuar)
    {
        printf("\nModulo Consultorios\n");
        printf("=========================\n");
        printf("1.- Iniciar Sesion\n");
        printf("2.- Visualizar Lista de Espera de Turnos (informe)\n");
        printf("3.- Registrar Historia Clinica\n");
        printf("4.- Volver al menu principal\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            if (sesion_iniciada)
            {
                // Aqui va el codigo para iniciar sesion
            }
            else
            {
                printf("\nDebes iniciar sesion primero.\n");
            }
            break;
        case 2:
            if (sesion_iniciada)
            {
                // Aqui va el codigo para mostrar la lista de espera de turnos
            }
            else
            {
                printf("\nDebes iniciar sesion primero.\n");
            }
            break;
        case 3:
            if (sesion_iniciada)
            {
                // Aqui va el codigo para registrar la historia clinica
            }
            else
            {
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

void moduloRecepcionista()
{
    int opcion;
    bool continuar = true;
    bool sesion_iniciada = false;
    while (continuar)
    {
        printf("\nModulo del recepcionista\n");
        printf("=========================\n");
        printf("1.- Iniciar Sesion\n");
        printf("2.- Registrar Pacientes\n");
        printf("3.- Registrar Turno\n");
        printf("4.- Listado de Atenciones por Profesional y Fecha\n");
        printf("5.- Volver al menu principal\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            if (sesion_iniciada)
            {
                // Aqui va el codigo para iniciar sesion
            }
            else
            {
                printf("\nDebes iniciar sesion primero.\n");
            }
            break;
        case 2:
            if (sesion_iniciada)
            {
                // Aqui va el codigo para registrar pacientes
            }
            else
            {
                printf("\nDebes iniciar sesion primero.\n");
            }
            break;
        case 3:
            if (sesion_iniciada)
            {
                // Aqui va el codigo para registrar turno
            }
            else
            {
                printf("\nDebes iniciar sesion primero.\n");
            }
            break;
        case 4:
            if (sesion_iniciada)
            {
                // Aqui va el codigo para mostrar el listado de atenciones
            }
            else
            {
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

void moduloAdministracion()
{
    int opcion;
    bool continuar = true;
    // bool sesion_iniciada = false;
    bool sesion_iniciada_admin = false;
    while (continuar)
    {
        printf("\nModulo Administracion\n");
        printf("=========================\n");
        printf("1.- Registrar Profesionales\n");
        printf("2.- Registrar Usuario Recepcionista\n");
        printf("3.- Atenciones por Profesional\n");
        printf("4.- Ranking de Profesionales por Atenciones\n");
        printf("5.- Iniciar sesion como administrador\n\n");
        printf("6.- Volver al menu principal\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            // sesion_iniciada_admin = true;
            if (sesion_iniciada_admin)
            {
                // Aqui va el codigo para registrar profesionales
                // crearUsuarioProvisorio();
            }
            else
            {
                printf("\nDebes iniciar sesion primero.\n");
            }
            break;
        case 2:
            if (sesion_iniciada_admin)
            {
                crearNuevoRecepcionista();
            }
            else
            {
                printf("\nDebes iniciar sesion primero.\n");
            }
            break;
        case 3:
            if (sesion_iniciada_admin)
            {
                // Aqui va el codigo para mostrar las atenciones por profesional
            }
            else
            {
                printf("\nDebes iniciar sesion primero.\n");
            }
            break;
        case 4:
            if (sesion_iniciada_admin)
            {
                // Aqui va el codigo para mostrar el ranking de profesionales por atenciones
            }
            else
            {
                printf("\nDebes iniciar sesion primero.\n");
            }
            break;

        case 5:
            struct Usuarios usuario;
            FILE *archivo;
            char Usuario[11];
            char Contrasena[32];
            printf("Ingrese el nombre de usuario: ");
            scanf("%s", Usuario);
            printf("Ingrese la contrasena: ");
            scanf("%s", Contrasena);

            // Abre el archivo para lectura
            archivo = fopen("Recepcionistas.dat", "rb");
            if (archivo == NULL)
            {
                printf("No se pudo abrir el archivo para lectura\n");
            }

            // Lee la estructura de usuario del archivo
            while (fread(&usuario, sizeof(Usuarios), 1, archivo))
            {
                if (strcmp(usuario.Usuario, Usuario) == 0 && strcmp(usuario.Contrasena, Contrasena) == 0)
                {
                    printf("Inicio de sesion exitoso.\n");
                    fclose(archivo);
                    sesion_iniciada_admin = true;
                }
                else
                {
                    printf("Nombre de usuario o contrasena incorrectos.\n");
                }
            }

            // Cierra el archivo
            fclose(archivo);

            break;
        case 6:
            printf("\nVolviendo al menu principal...\n");
            continuar = false;
            break;
        default:
            printf("\nOpcion invalida. Intenta de nuevo.\n");
        }
    }
}

int main()
{
    int opcion;

    while (true)
    {
        printf("\nMenu Principal\n");
        printf("=========================\n");
        printf("1.- Modulo Consultorios\n");
        printf("2.- Modulo del Recepcionista\n");
        printf("3.- Modulo Administracion\n");
        printf("4.- Cerrar la aplicacion.\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
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
