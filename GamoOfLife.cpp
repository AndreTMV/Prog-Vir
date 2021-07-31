#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdlib.h>
#include <windows.h>

using namespace std;

void GenerarMatriz(vector<vector<int>> &matriz, int n) // Funcion para generar la matriz con 0 y 1 aleatorios
{
    srand(time(NULL));
    matriz.resize(n);
    for (auto &fila : matriz)
    {
        fila.resize(n);
    }

    for (auto &fila : matriz)
    {
        for (auto &columna : fila)
        {
            int valor = rand() % 2;
            columna = valor;
        }
    }
}

void DesplegarMatriz(vector<vector<int>> &matriz)
{
    for (const auto &fila : matriz)
    {
        for (auto columna : fila)
        {
            cout << columna << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int NumeroDeVecinos(int fila, int columna, int indice)
{
    int numero_de_vecinos = 0;
    if ((fila == 0 && columna == 0) || (columna == 0 && fila == indice) || (columna == indice && fila == 0) || (columna == indice && fila == indice))
    {
        return 2;
    }
    else if (fila == 0 || columna == 0 || fila == indice || columna == indice)
    {
        return 3;
    }
    else
    {
        return 4;
    }
}

void DespliegaVecinos(int indice)
{
    int vecinos = 0;
    for (int fila = 0; fila < indice; fila++)
    {
        for (int columna = 0; columna < indice; columna++)
        {
            cout << "Posicion: " << fila + 1 << ' ' << columna + 1 << endl;
            cout << "Vecinos: " << (vecinos = NumeroDeVecinos(fila, columna, indice)) << endl;
        }
    }
}

void Celula01(vector<vector<int>> &matriz, int indice)
{
    indice -= 1;
    int vecinos = 0, vecinos01 = 0;
    for (int fila = 0; fila < indice; fila++)
    {
        for (int columna = 0; columna < indice; columna++)
        {
            vecinos = NumeroDeVecinos(fila, columna, indice);
            switch (vecinos)
            {
            case 2:
                if (fila == 0 && columna == 0)
                {
                    if (matriz[fila][columna + 1] == 0 || matriz[fila + 1][columna] == 0)
                    {
                        matriz[fila][columna] = 0;
                        cout << "Cambio la posicion: " << fila << columna << endl;
                    }
                    else if (matriz[fila][columna + 1] == 1 && matriz[fila + 1][columna] == 1)
                    {
                        matriz[fila][columna] = 1;
                        cout << "Cambio la posicion: " << fila << columna << endl;
                    }
                }
                else if (fila == indice && columna == 0)
                {
                    if (matriz[fila][columna + 1] == 0 || matriz[fila - 1][columna] == 0)
                    {
                        matriz[fila][columna] = 0;
                        cout << "Cambio la posicion: " << fila << columna << endl;
                    }
                    else if (matriz[fila][columna + 1] == 1 && matriz[fila - 1][columna] == 1)
                    {
                        matriz[fila][columna] = 1;
                    }
                }
                else if (fila == 0 && columna == indice)
                {
                    if (matriz[fila][columna - 1] == 0 || matriz[fila + 1][columna] == 0)
                    {
                        matriz[fila][columna] = 0;
                        cout << "Cambio la posicion: " << fila << columna << endl;
                    }
                    else if (matriz[fila][columna - 1] == 1 && matriz[fila + 1][columna] == 1)
                    {
                        matriz[fila][columna] = 1;
                        cout << "Cambio la posicion: " << fila << columna << endl;
                    }
                }
                else if (fila == indice && columna == indice)
                {
                    if (matriz[fila][columna - 1] == 0 || matriz[fila - 1][columna] == 0)
                    {
                        matriz[fila][columna] = 0;
                        cout << "Cambio la posicion: " << fila << columna << endl;
                    }
                    else if (matriz[fila][columna - 1] == 1 && matriz[fila - 1][columna] == 1)
                    {
                        matriz[fila][columna] = 1;
                        cout << "Cambio la posicion: " << fila << columna << endl;
                    }
                }
                break;
            case 3:
                if (fila == 0)
                {
                    if (matriz[fila][columna] == 0 && (matriz[fila][columna + 1] == 1 && matriz[fila][columna - 1] == 1 && matriz[fila + 1][columna] == 1))
                    {
                        matriz[fila][columna] = 1;
                        cout << "Cambio la posicion: " << fila << columna << endl;
                    }
                    else if (matriz[fila][columna] == 1 && (matriz[fila][columna + 1] == 1 && matriz[fila][columna - 1] == 1 && matriz[fila + 1][columna] == 1))
                    {
                        matriz[fila][columna] = 0;
                        cout << "Cambio la posicion: " << fila << columna << endl;
                    }
                    else if (matriz[fila][columna] == 1)
                    {
                        if (matriz[fila][columna - 1] == 1)
                        {
                            vecinos01 += 1;
                        }
                        else if (matriz[fila][columna + 1] == 1)
                        {
                            vecinos01 += 1;
                        }
                        else if (matriz[fila + 1][columna] == 1)
                        {
                            vecinos += 1;
                        }
                        if (vecinos01 < 2)
                        {
                            matriz[fila][columna] = 0;
                            cout << "Cambio la posicion: " << fila << columna << endl;
                        }
                    }
                }
                else if (columna == 0)
                {
                    if (matriz[fila][columna] == 0 && (matriz[fila][columna + 1] == 1 && matriz[fila + 1][columna] == 1 && matriz[fila - 1][columna] == 1))
                    {
                        matriz[fila][columna] = 1;
                        cout << "Cambio la posicion: " << fila << columna << endl;
                    }
                    else if (matriz[fila][columna] == 1 && (matriz[fila][columna + 1] == 1 && matriz[fila + 1][columna] == 1 && matriz[fila - 1][columna] == 1))
                    {
                        matriz[fila][columna] = 0;
                        cout << "Cambio la posicion: " << fila << columna << endl;
                    }
                    else if (matriz[fila][columna] == 1)
                    {
                        if (matriz[fila + 1][columna] == 1)
                        {
                            vecinos01 += 1;
                        }
                        else if (matriz[fila][columna + 1] == 1)
                        {
                            vecinos01 += 1;
                        }
                        else if (matriz[fila + 1][columna] == 1)
                        {
                            vecinos += 1;
                        }
                        if (vecinos01 < 2)
                        {
                            matriz[fila][columna] = 0;
                            cout << "Cambio la posicion: " << fila << columna << endl;
                        }
                    }
                }
                else if (fila == indice)
                {
                    if (matriz[fila][columna] == 0 && (matriz[fila][columna + 1] == 1 && matriz[fila][columna - 1] == 1 && matriz[fila - 1][columna] == 1))
                    {
                        matriz[fila][columna] = 1;
                        cout << "Cambio la posicion: " << fila << columna << endl;
                    }
                    else if (matriz[fila][columna] == 1 && (matriz[fila][columna + 1] == 1 && matriz[fila][columna - 1] == 1 && matriz[fila - 1][columna] == 1))
                    {
                        matriz[fila][columna] = 0;
                        cout << "Cambio la posicion: " << fila << columna << endl;
                    }
                    else if (matriz[fila][columna] == 1)
                    {
                        if (matriz[fila][columna - 1] == 1)
                        {
                            vecinos01 += 1;
                        }
                        else if (matriz[fila][columna + 1] == 1)
                        {
                            vecinos01 += 1;
                        }
                        else if (matriz[fila - 1][columna] == 1)
                        {
                            vecinos += 1;
                        }
                        if (vecinos01 < 2)
                        {
                            matriz[fila][columna] = 0;
                            cout << "Cambio la posicion: " << fila << columna << endl;
                        }
                    }
                }
                else if (columna == indice)
                {

                    if (matriz[fila][columna] == 0 && (matriz[fila][columna - 1] == 1 && matriz[fila + 1][columna] == 1 && matriz[fila - 1][columna] == 1))
                    {
                        matriz[fila][columna] = 1;
                        cout << "Cambio la posicion: " << fila << columna << endl;
                    }
                    else if (matriz[fila][columna] == 1 && (matriz[fila][columna - 1] == 1 && matriz[fila + 1][columna] == 1 && matriz[fila - 1][columna] == 1))
                    {
                        matriz[fila][columna] = 0;
                        cout << "Cambio la posicion: " << fila << columna << endl;
                    }
                    else if (matriz[fila][columna] == 1)
                    {
                        if (matriz[fila + 1][columna] == 1)
                        {
                            vecinos01 += 1;
                        }
                        else if (matriz[fila][columna - 1] == 1)
                        {
                            vecinos01 += 1;
                        }
                        else if (matriz[fila + 1][columna] == 1)
                        {
                            vecinos += 1;
                        }
                        if (vecinos01 < 2)
                        {
                            matriz[fila][columna] = 0;
                            cout << "Cambio la posicion: " << fila << columna << endl;
                        }
                    }
                }
                vecinos01 = 0;
                break;
            case 4:
                if (matriz[fila + 1][columna] == 1)
                {
                    vecinos01++;
                }
                else if (matriz[fila - 1][columna] == 1)
                {
                    vecinos01++;
                }
                else if (matriz[fila][columna + 1] == 1)
                {
                    vecinos01++;
                }
                else if (matriz[fila][columna - 1] == 1)
                {
                    vecinos01++;
                }
                if (vecinos < 2 && matriz[fila][columna] == 1)
                {
                    matriz[fila][columna] = 0;
                    cout << "Cambio la posicion: " << fila << columna << endl;
                }
                else if (vecinos > 3 && matriz[fila][columna] == 0)
                {
                    matriz[fila][columna] = 1;
                    cout << "Cambio la posicion: " << fila << columna << endl;
                }
                else if (vecinos > 3 && matriz[fila][columna] == 1)
                {
                    matriz[fila][columna] = 0;
                    cout << "Cambio la posicion: " << fila << columna << endl;
                }
                break;
            default:
                break;
            }
            DesplegarMatriz(matriz);
            Sleep(1000);
            system("PAUSE");
        }
    }
}

int main()
{
    int indice = 0, vecinos = 0, count = 0;
    cout << "Medidas de tu matriz (ejemplo: 2 = matriz[2][2])" << endl;
    cin >> indice;
    vector<vector<int>> matriz;
    GenerarMatriz(matriz, indice);
    cout << "Matriz Inicial: " << endl;
    DesplegarMatriz(matriz);
    system("PAUSE");
    while (count < 100)
    {
        Celula01(matriz, indice);
        count++;
    }
}
