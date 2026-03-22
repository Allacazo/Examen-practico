// L.P. Examen Practico #0.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

using namespace std;

const int MAX = 20;
const int MAT = 6;

void registrar(string nombre[], double prom[], int cant);
double sacarPromedio(double prom[], int cant);
double notaAlta(double prom[], int cant);
double notaBaja(double prom[], int cant);
void aprobados(string nombre[], double prom[], int cant);

int main()
{
    string nombre[MAX];
    double prom[MAX];
    int cant = 0;
    int op = 0;
    bool datos = false;

    do
    {
        cout << "\nMENU\n";
        cout << "1. Registrar estudiantes y calificaciones\n";
        cout << "2. Mostrar promedio\n";
        cout << "3. Mostrar nota mas alta\n";
        cout << "4. Mostrar nota mas baja\n";
        cout << "5. Mostrar estudiantes aprobados\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "Cantidad de estudiantes: ";
            cin >> cant;

            while (cant < 1 || cant > MAX)
            {
                cout << "Ingrese una cantidad valida (1-20): ";
                cin >> cant;
            }

            cin.ignore();
            registrar(nombre, prom, cant);
            datos = true;
            break;

        case 2:
            if (datos)
            {
                cout << "Promedio general: " << sacarPromedio(prom, cant) << endl;
            }
            else
            {
                cout << "Primero registre los datos.\n";
            }
            break;

        case 3:
            if (datos)
            {
                cout << "Nota mas alta: " << notaAlta(prom, cant) << endl;
            }
            else
            {
                cout << "Primero registre los datos.\n";
            }
            break;

        case 4:
            if (datos)
            {
                cout << "Nota mas baja: " << notaBaja(prom, cant) << endl;
            }
            else
            {
                cout << "Primero registre los datos.\n";
            }
            break;

        case 5:
            if (datos)
            {
                aprobados(nombre, prom, cant);
            }
            else
            {
                cout << "Primero registre los datos.\n";
            }
            break;

        case 6:
            cout << "Fin del programa.\n";
            break;

        default:
            cout << "Opcion no valida.\n";
            break;
        }

    } while (op != 6);

    return 0;
}

void registrar(string nombre[], double prom[], int cant)
{
    double nota[MAT];
    double suma;

    for (int i = 0; i < cant; i++)
    {
        cout << "\nNombre del estudiante " << i + 1 << ": ";
        getline(cin, nombre[i]);

        suma = 0;

        for (int j = 0; j < MAT; j++)
        {
            cout << "Nota " << j + 1 << ": ";
            cin >> nota[j];

            while (nota[j] < 0 || nota[j] > 100)
            {
                cout << "Ingrese una nota valida: ";
                cin >> nota[j];
            }

            suma = suma + nota[j];
        }

        prom[i] = suma / MAT;
        cout << "Promedio final: " << prom[i] << endl;
        cin.ignore();
    }
}

double sacarPromedio(double prom[], int cant)
{
    double suma = 0;

    for (int i = 0; i < cant; i++)
    {
        suma = suma + prom[i];
    }

    return suma / cant;
}

double notaAlta(double prom[], int cant)
{
    double alta = prom[0];

    for (int i = 1; i < cant; i++)
    {
        if (prom[i] > alta)
        {
            alta = prom[i];
        }
    }

    return alta;
}

double notaBaja(double prom[], int cant)
{
    double baja = prom[0];

    for (int i = 1; i < cant; i++)
    {
        if (prom[i] < baja)
        {
            baja = prom[i];
        }
    }

    return baja;
}

void aprobados(string nombre[], double prom[], int cant)
{
    bool hay = false;

    cout << "\nEstudiantes aprobados:\n";

    for (int i = 0; i < cant; i++)
    {
        if (prom[i] >= 70)
        {
            cout << nombre[i] << " - " << prom[i] << endl;
            hay = true;
        }
    }

    if (hay == false)
    {
        cout << "No hay aprobados.\n";
    }
}

