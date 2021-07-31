#include <iostream>
#include <cstdlib>
#include <vector>
#include <unistd.h>
#include <ctime>

using namespace std;

class Mapa
{
public:
    int fil;
    int col;
    int vecinos;
    vector<vector<int>> mapa;

    Mapa(int f, int c);
    void dibujar();
    int analizarVecinos(int posf, int posc);
    void ciclo();
};

Mapa::Mapa(int f, int c)
{
    srand(time(NULL));
    fil = f;
    col = c;
    mapa.resize(fil);
    for (auto &fila : mapa)
    {
        fila.resize(col);
    }

    for (auto &fila : mapa)
    {
        for (auto &columna : fila)
        {
            int valor = rand() % 2;
            columna = valor;
        }
    }
}

void Mapa::dibujar()
{
    for (const auto &fila : mapa)
    {
        for (auto columna : fila)
        {
            if (columna == 1)
                cout << "* ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

int Mapa::analizarVecinos(int posf, int posc)
{
    vecinos = 0;
    if (posf - 1 >= 0 and posc - 1 >= 0)
        if (mapa[posf - 1][posc - 1] == 1)
            vecinos++;
    if (posf - 1 >= 0)
        if (mapa[posf - 1][posc] == 1)
            vecinos++;
    if (posf - 1 >= 0 and posc + 1 <= col - 1)
        if (mapa[posf - 1][posc + 1] == 1)
            vecinos++;
    if (posc - 1 >= 0)
        if (mapa[posf][posc - 1] == 1)
            vecinos++;
    if (posc + 1 <= col - 1)
        if (mapa[posf][posc + 1] == 1)
            vecinos++;
    if (posf + 1 <= fil - 1 and posc - 1 >= 0)
        if (mapa[posf + 1][posc - 1] == 1)
            vecinos++;
    if (posf + 1 <= fil - 1)
        if (mapa[posf + 1][posc] == 1)
            vecinos++;
    if (posf + 1 <= fil - 1 and posc + 1 <= col - 1)
        if (mapa[posf + 1][posc + 1] == 1)
            vecinos++;
    return vecinos;
}

void Mapa::ciclo()
{
    vector<vector<int>> nueva_conf = mapa;

    for (int f = 0; f < fil; f++)
    {
        for (int c = 0; c < col; c++)
        {
            int n_vecinos = analizarVecinos(f, c);
            if (mapa[f][c] == 0)
            {
                if (vecinos == 3)
                {
                    nueva_conf[f][c] = 1;
                    //cout << "Cambio la posicion: " << f << ' ' << c << endl;
                }
                else
                    nueva_conf[f][c] = 0;
            }
            if (mapa[f][c] == 1)
            {
                if (vecinos == 2 || vecinos == 3)
                    nueva_conf[f][c] = 1;
                else
                {
                    nueva_conf[f][c] = 0;
                    //cout << "Cambio la posicion: " << f << ' ' << c << endl;
                }
            }
        }
    }
    mapa = nueva_conf;
}

int main()
{
    srand(time(NULL));
    int fila = 0, columna = 0;
    cin >> fila >> columna;
    Mapa mapa(fila, columna);
    while (1)
    {
        mapa.dibujar();
        usleep(1000000);
        system("CLS");
        mapa.ciclo();
    }
}