#include <iostream>
#include "FuncionesConParametros.h"
#include "SobreCargaDeFunciones.h"
#include "ClaseArray.h"
#include <ctime>
#include <array>
#include <iomanip>


void Fibonacci(int limite, int a, int b, int& suma) {
	if (limite)
	{
		suma = a + b;
		cout << suma << endl;;
		b = a;
		a = suma;
		Fibonacci(limite - 1, a, b, suma);
	}
}


float Suma_de_vectores()
{
	float suma = 0;
	// Declaracion de un arreglo atravez de la clase array
	array<float,  10> arreglo;
	for (size_t i = 0; i < arreglo.size(); i++)
	{
		cout << "Dame el elemento " << i + 1 << " : " << endl;
		cin >> arreglo[i];
	}

	for (size_t i = 0; i < arreglo.size(); i++)
	{
		suma += arreglo[i];
	}
	
	return suma;

}

void LlenarArrelgo(array<int, 100>& arreglo)
{
	srand((unsigned)time(0));

	for (size_t i = 0; i < arreglo.size(); i++)
		arreglo[i] = (int)((rand() % 100) + 1);
}

void GraficaRangos(array<int, 100> arreglo)
{
	cout << "Chart: " << endl;
	for (size_t i = 0; i <= 10; i++)
	{
		if (i == 0)
			cout << "0-9:";

		else if (i == 10)
			cout << "100:";

		else if (i >= 10)
			cout << endl;

		else
			cout << i * 10 << "-" << (i * 10) + 9 << ":";

		for (int stars = 0; stars < arreglo.size(); stars++)
		{
			if (i == 10 && arreglo[stars] == 100)
				cout << "*";
			else if (arreglo[stars] >= (i * 10) && arreglo[stars] <= ((i * 10) + 9))
				cout << "*";
		}
		cout << endl;
	}
}

//int main() {
//	//////cout << SumarDos(123, 12) << endl;
//	//////PedirDatos();
//	////Sumar('a', 'b');
//	////Sumar(100, 20);
//	////Sumar(100, 10, 30);
//	////return 0;
//	//// Opcion para que el usuario decida si quiere continuar
//	//char opcion_de_continuar = 's';
//	//// Si el usuario digita otra cosa que no sea s (que es la opcion de continuar) se sale del loop
//	//while (opcion_de_continuar == 's' || opcion_de_continuar == 'S')
//	//{
//	//	
//	//	switch (opcion())
//	//	{
//	//	case 3:
//	//		cout << multiplicacion() << endl;
//	//		break;
//	//	case 4:
//	//		cout << division() << endl;
//	//		break;
//	//	case 1:
//	//		cout << suma() << endl;
//	//		break;
//	//	case 2:
//	//		cout << resta() << endl;
//	//	default:
//	//		cout << "Esa no es una opcion valida" << endl;
//	//		break;
//	//	} // switch case
//	//	// Le preguntamos al usuario si quiere continuar
//	//	cout << "¿Quieres continuar?(S/N)" << endl;
//	//	cin >> opcion_de_continuar;
//	//} 
//	////cout << "¡¡Gracias por usar este programa!!" << endl;
//	////system("pause");
//	//int a = 1, b = 1, suma = 0, limite = 0;
//	//cout << "Limite: " << endl;
//	//cin >> limite;
//	//cout << "Esta es la serie de fibonacci hasta la posicion " << limite  << ": " << endl;
//	//Fibonacci(limite, a, b, suma);
//	array<int, 100>arreglo = { 0, };
//	LlenarArrelgo(arreglo);
//	GraficaRangos(arreglo);
//	return 0;
//}