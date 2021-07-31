#include <iostream>
#include <string>
#include <istream>  // Input stream, Read from files
#include <ostream>  // Output stream, Write in files
#include <fstream>  // File stream, Read and Write from files
#include <direct.h> // To make directories(carpetas)
using namespace std;

int main()
{
    // Para crear una carpeta
    _mkdir("Test");
    ofstream fout; // Instanciando como objetos para acceder a sus metodo
    ifstream fin;  // Instanciando como objetos para acceder a sus metodo
    fstream file;  // Instanciando como objetos para acceder a sus metodo
    string line;
#pragma region Write into Files
    int contador_de_lineas = 0;
    // La ruta inicia donde se encuentre el exe, para irte más arriba en los dirs sería asi file.open("../Test.txt") podemos irnos hasta donde nos deje
    // ios::app es para append, osea al final del texto va a comenzar a escribir cada vez que se vuelva a ejecutar el programa
    file.open("Test.txt", ios::app);
    while (file)
    {
        getline(cin, line);
        ++contador_de_lineas;
        if (line == "-1")
        {
            break;
        }
        file << "La linea [" << contador_de_lineas << "] es: " << line << endl;
    }
    // Siempre cierra el archivo al terminar tu programa o pueden volverse corrruptos
    file.close();
#pragma endregion

    // Read from file
#pragma region Read from Files
    // Open a file for read only with in(openmode)
    file.open("Test.txt", ios::in);
    while (file)
    {
        getline(file, line);
        cout << line << endl;
    }
    file.close();
#pragma endregion
}
// Hay archivos como .xlsx que no pueden ser interpretados como texto, por lo cual si los abres te sale pura basuraaaaa