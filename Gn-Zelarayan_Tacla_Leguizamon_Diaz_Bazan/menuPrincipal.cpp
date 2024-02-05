#include <conio.h>
#include <stdio.h>
#include <cctype>
#include <cstring>
#include <string.h>
#include <stdlib.h>

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
    char Usuario[11];
    char Contrasena[33];
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
    bool Pendiente;
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

void registrarPacientes()
{
    struct Pacientes nuevoPaciente;
    FILE *file;

    printf("\nIntroduce el Apellido y Nombre: ");
    fgets(nuevoPaciente.ApellidoNombre, 60, stdin);
    nuevoPaciente.ApellidoNombre[strcspn(nuevoPaciente.ApellidoNombre, "\n")] = 0;  // Eliminar el salto de línea al final

    printf("\nIntroduce el Domicilio: ");
    fgets(nuevoPaciente.Domicilio, 60, stdin);
    nuevoPaciente.Domicilio[strcspn(nuevoPaciente.Domicilio, "\n")] = 0;  // Eliminar el salto de línea al final

    printf("\nIntroduce el DNI: ");
    scanf("%d", &nuevoPaciente.DniPaciente);
    getchar();  // Consumir el carácter de nueva línea

    printf("\nIntroduce la Localidad: ");
    fgets(nuevoPaciente.Localidad, 60, stdin);
    nuevoPaciente.Localidad[strcspn(nuevoPaciente.Localidad, "\n")] = 0;  // Eliminar el salto de línea al final

    printf("\nIntroduce la Fecha de nacimiento: ");
    printf("\nDia: ");
    scanf("%d", &nuevoPaciente.FechadeNacimiento.dia);
    printf("\nMes: ");
    scanf("%d", &nuevoPaciente.FechadeNacimiento.mes);
    printf("\nAnio: ");
    scanf("%d", &nuevoPaciente.FechadeNacimiento.ano);
    getchar();  // Consumir el carácter de nueva línea

    printf("\nIntroduce el Telefono: ");
    fgets(nuevoPaciente.Telefono, 25, stdin);
    nuevoPaciente.Telefono[strcspn(nuevoPaciente.Telefono, "\n")] = 0;  // Eliminar el salto de línea al final

    file = fopen("Pacientes.dat", "ab");
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    fwrite(&nuevoPaciente, sizeof(Pacientes), 1, file);
    fclose(file);

    printf("\nPaciente creado con exito.\n");
}


void crearNuevoRecepcionista()
{
    Usuarios nuevoRecepcionista;
    Usuarios usuarioExistente;
    char opcion;
    FILE *file;
    bool usuarioCreado = false;

    do
    {
        printf("\nIntroduce el Nuevo Usuario (minimo 6 y maximo 10 caracteres) \nDebe comenzar con una letra minuscula\nDebe tener 2 letras mayusculas\nTener maximo 3 digitos\n\n--> ");
        scanf("%11s", nuevoRecepcionista.Usuario);

        file = fopen("Recepcionistas.dat", "rb");
        if (file != NULL)
        {
            while (fread(&usuarioExistente, sizeof(Usuarios), 1, file))
            {
                if (strcmp(usuarioExistente.Usuario, nuevoRecepcionista.Usuario) == 0)
                {
                    printf("El usuario ya existe.\n");
                    fclose(file);
                    return;
                }
            }
            fclose(file);
        }

        printf("\nIntroduce la Contrasena del nuevo usuario (minimo 6 y maximo 32 caracteres) \nDebera contener al menos una letra mayuscula, una letra minuscula y un numero\nNo debe tener mas de 3 caracteres numericos consecutivos\nNo debe tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas (ascendentemente)\n\n--> ");
        scanf("%33s", nuevoRecepcionista.Contrasena);

        if (esNombreUsuarioValido(nuevoRecepcionista.Usuario) && esContrasenaValida(nuevoRecepcionista.Contrasena))
        {
            printf("Introduce el Nombre y Apellido (maximo 60 caracteres): ");
            scanf("%60s", nuevoRecepcionista.ApellidoNombre);
            printf("\nUsuario creado con exito.\n");
            getch();
            file = fopen("Recepcionistas.dat", "ab");
            if (file == NULL)
            {
                printf("No se pudo abrir el archivo.\n");
                return;
            }

            fwrite(&nuevoRecepcionista, sizeof(Usuarios), 1, file);
            fclose(file);
            usuarioCreado = true; // Indica que se ha creado un nuevo usuario
        }
        else
        {
            printf("\nNombre de usuario o contrasena invalidos.\n");
            printf("¿Deseas intentarlo de nuevo? (s/n): ");
            scanf(" %c", &opcion); // El espacio antes de %c ignora los espacios en blanco
            getchar();             // consume el carácter de nueva línea
            system("CLS");
        }
    } while ((opcion == 's' || opcion == 'S') && !usuarioCreado); // Solo repite si el usuario quiere intentarlo de nuevo y no se ha creado un nuevo usuario
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

void profesionalProvisorio()
{
    struct Profesionales nuevoProfesional;

    strcpy(nuevoProfesional.ApellidoNombre, "sebastian zelarayan");
    nuevoProfesional.IdProfesional = 123;
    nuevoProfesional.Dni = 429999;
    strcpy(nuevoProfesional.Telefono, "123123123");
    strcpy(nuevoProfesional.Usuario, "sebazelara");
    strcpy(nuevoProfesional.Contrasena, "12345678");

    FILE *file = fopen("Profesionales.dat", "ab");
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo Profesionales.dat.\n");
        return;
    }

    fwrite(&nuevoProfesional, sizeof(Profesionales), 1, file);

    fclose(file);

    printf("\n\nProfesional provisorio creado");
}

void pacienteProvisorio()
{
    struct Pacientes nuevoPaciente;

    strcpy(nuevoPaciente.ApellidoNombre, "zelarayan sebastian");
    strcpy(nuevoPaciente.Domicilio, "san miguel");
    nuevoPaciente.DniPaciente = 4238641;
    strcpy(nuevoPaciente.Localidad, "Tucuman");
    nuevoPaciente.FechadeNacimiento.dia = 23;
    nuevoPaciente.FechadeNacimiento.mes = 11;
    nuevoPaciente.FechadeNacimiento.ano = 2000;
    strcpy(nuevoPaciente.Telefono, "3814400000");

    FILE *file = fopen("Pacientes.dat", "ab");
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo para escritura. Asegúrate de que el archivo 'Pacientes.dat' exista en el directorio correcto.\n");
        return;
    }

    fwrite(&nuevoPaciente, sizeof(Pacientes), 1, file);

    fclose(file);

    printf("\n\nPaciente provisorio creado");
}

int esIdProfesionalValido(int id)
{
    struct Profesionales profesional;
    FILE *file = fopen("Profesionales.dat", "rb");
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo Profesionales.dat.\n");
        return 0;
    }

    while (fread(&profesional, sizeof(Profesionales), 1, file))
    {
        if (id == profesional.IdProfesional)
        {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void crearTurno()
{
    struct Turnos nuevoTurno;
    FILE *file;

    printf("Introduce el ID del Profesional: ");
    scanf("%d", &nuevoTurno.IdProfesional);

    if (!esIdProfesionalValido(nuevoTurno.IdProfesional))
    {
        printf("El ID del Profesional no es valido.\n");
        return;
    }

    printf("Introduce el dia de la fecha: ");
    scanf("%d", &nuevoTurno.fecha.dia);

    printf("Introduce el mes de la fecha: ");
    scanf("%d", &nuevoTurno.fecha.mes);

    printf("Introduce el ano de la fecha: ");
    scanf("%d", &nuevoTurno.fecha.ano);

    printf("Introduce el DNI del Paciente: ");
    // Asigna true a Pendiente
    nuevoTurno.Pendiente = true;

    printf("Introduce el Detalle de Atencion (maximo 379 caracteres): ");
    scanf(" %[^\n]", nuevoTurno.DetalledeAtencion); // Lee hasta un salto de línea

    file = fopen("Turnos.dat", "ab"); // Abre el archivo en modo de añadir en binario
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    fwrite(&nuevoTurno, sizeof(Turnos), 1, file);
    fclose(file);
}


void visualizarTurno(int idRegistrado)
{
    struct Turnos turno;
    FILE *archivo;
    bool turnoEncontrado = false;

    // Abre el archivo para lectura
    archivo = fopen("Turnos.dat", "rb");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo para lectura. Asegurate de que el archivo 'Turnos.dat' exista en el directorio correcto.\n");
        return;
    }

    // Lee la estructura de turno del archivo
    while (fread(&turno, sizeof(Turnos), 1, archivo))
    {
        if (turno.IdProfesional == idRegistrado && turno.Pendiente)
        {
            printf("\n================================================================\n");
            printf("Fecha: %d/%d/%d\n", turno.fecha.dia, turno.fecha.mes, turno.fecha.ano); // Asume que Fecha es una estructura con dia, mes y ano
            printf("DniPaciente: %d\n", turno.DniPaciente);
            printf("DetalledeAtencion: %s\n", turno.DetalledeAtencion);
            turnoEncontrado = true;
        }
    }

    if (!turnoEncontrado)
    {
        printf("El profesional no cuenta con turnos pendientes.\n");
    }

    // Cierra el archivo
    fclose(archivo);
}

void registrarHistoriaClinica()
{
    struct Turnos turno;
    FILE *archivo;
    int dniIngresado;
    char nuevoDetalle[380];
    bool turnoEncontrado = false;

    printf("Ingrese el DNI del paciente: ");
    scanf("%d", &dniIngresado);

    // Abre el archivo para lectura y escritura
    archivo = fopen("Turnos.dat", "r+b");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo para lectura y escritura. Asegurate de que el archivo 'Turnos.dat' exista en el directorio correcto.\n");
        return;
    }

    // Lee la estructura de turno del archivo
    while (fread(&turno, sizeof(Turnos), 1, archivo))
    {
        if (turno.DniPaciente == dniIngresado)
        {
            printf("Ingrese el nuevo Detalle de Atencion (maximo 379 caracteres): ");
            scanf(" %[^\n]", nuevoDetalle); // Lee hasta un salto de linea

            // Copia el nuevo detalle en el registro de turno
            strcpy(turno.DetalledeAtencion, nuevoDetalle);

            // Cambia el estado de Pendiente a false
            turno.Pendiente = false;

            // Mueve el puntero de archivo al inicio del registro de turno
            fseek(archivo, -sizeof(Turnos), SEEK_CUR);

            // Escribe el registro de turno actualizado en el archivo
            fwrite(&turno, sizeof(Turnos), 1, archivo);

            turnoEncontrado = true;
            break;
        }
    }

    if (!turnoEncontrado)
    {
        printf("No se encontro un turno para el DNI del paciente ingresado.\n");
    }

    // Cierra el archivo
    fclose(archivo);
}

void moduloConsultorios()
{
    int opcion;
    bool continuar = true;
    bool sesion_iniciada_prof = false;
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
        system("CLS");

        switch (opcion)
        {
        case 1:
            struct Profesionales profesional;
            FILE *archivo;
            char Usuario[11];
            char Contrasena[33];
            int idRegistrado;

            printf("Ingrese el nombre de usuario: ");
            scanf("%s", Usuario);
            printf("Ingrese la contrasena: ");
            scanf("%s", Contrasena);

            // Abre el archivo para lectura
            archivo = fopen("Profesionales.dat", "rb");
            if (archivo == NULL)
            {
                printf("No se pudo abrir el archivo para lectura\n");
                return;
            }

            // Lee la estructura de usuario del archivo
            while (fread(&profesional, sizeof(Profesionales), 1, archivo))
            {
                if (strcmp(profesional.Usuario, Usuario) == 0 && strcmp(profesional.Contrasena, Contrasena) == 0)
                {
                    printf("Inicio de sesion exitoso.\n");
                    printf("Bienvenido, %s!\n", profesional.ApellidoNombre);
                    sesion_iniciada_prof = true;
                    idRegistrado = profesional.IdProfesional;
                    break;
                }
            }

            if (!sesion_iniciada_prof)
            {
                printf("Nombre de usuario o contrasena incorrectos.\n");
            }

            // Cierra el archivo
            fclose(archivo);
            break;
        case 2:
            if (sesion_iniciada_prof)
            {
                visualizarTurno(idRegistrado);
            }
            else
            {
                printf("\nDebes iniciar sesion primero.\n");
            }
            break;
        case 3:
            if (sesion_iniciada_prof)
            {
                registrarHistoriaClinica();
            }
            else
            {
                printf("\nDebes iniciar sesion primero.\n");
            }
            break;
        case 4:
            printf("\nVolviendo al menu principal...\n");
            continuar = false;
            sesion_iniciada_prof = false;
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
    bool sesion_iniciada_recep = false;
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
        system("CLS");
        switch (opcion)
        {
        case 1:
            struct Usuarios usuario;
            FILE *archivo;
            char Usuario[11];
            char Contrasena[32];
            printf("Ingrese el nombre de usuario: ");
            scanf("%s", Usuario);
            printf("Ingrese la contrasena: ");
            scanf("%s", Contrasena);
            system("CLS");

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
                    printf("\nInicio de sesion exitoso.\n");
                    fclose(archivo);
                    sesion_iniciada_recep = true;
                }
                else
                {
                    printf("Nombre de usuario o contrasena incorrectos.\n");
                }
            }

            // Cierra el archivo
            fclose(archivo);
            break;
        case 2:
            if (sesion_iniciada_recep)
            {
                // pacienteProvisorio();
                registrarPacientes();
            }
            else
            {
                printf("\nDebes iniciar sesion primero.\n");
            }
            break;
        case 3:
            if (sesion_iniciada_recep)
            {
                crearTurno();
            }
            else
            {
                printf("\nDebes iniciar sesion primero.\n");
            }
            break;
        case 4:
            if (sesion_iniciada_recep)
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

//===================================================================

void moduloAdministracion()
{
    int opcion;
    bool continuar = true;
    // bool sesion_iniciada = false;
    bool sesion_iniciada_recep = false;
    while (continuar)
    {
        printf("\nModulo Administracion\n");
        printf("=========================\n");
        printf("1.- Registrar Profesionales\n");
        printf("2.- Registrar nuevo Usuario Recepcionista\n");
        printf("3.- Atenciones por Profesional\n");
        printf("4.- Ranking de Profesionales por Atenciones\n");
        printf("5.- Iniciar sesion como recepcionista\n\n");
        printf("6.- Volver al menu principal\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        system("CLS");
        switch (opcion)
        {
        case 1:
            // sesion_iniciada_recep = true;
            if (sesion_iniciada_recep)
            {
                // Aqui va el codigo para registrar profesionales
                // crearUsuarioProvisorio();
                // profesionalProvisorio();
            }
            else
            {
                printf("\nDebes iniciar sesion primero.\n");
            }
            break;
        case 2:
            if (sesion_iniciada_recep)
            {
                crearNuevoRecepcionista();
            }
            else
            {
                printf("\nDebes iniciar sesion primero.\n");
            }
            break;
        case 3:
            if (sesion_iniciada_recep)
            {
                // Aqui va el codigo para mostrar las atenciones por profesional
            }
            else
            {
                printf("\nDebes iniciar sesion primero.\n");
            }
            break;
        case 4:
            if (sesion_iniciada_recep)
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
                    sesion_iniciada_recep = true;
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
            sesion_iniciada_recep = false;
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
        system("CLS");

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