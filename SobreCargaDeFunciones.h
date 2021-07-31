#pragma once
#include <iostream>

int Sumar(int numero1, int numero2)
{
	return numero1 + numero2;
}

int Sumar(int numero1, int numero2, int numero3)
{
	return numero1 + numero2 + numero3;
}

void Sumar(char numero1, char numero2)
{

}

// Calculadora
// Pasar parametros por referencia
void PedirDatos(float& num1, float& num2)
{
	cout << "Dame el primer numero" << endl;
	cin >> num1;
	cout << "Dame el otro numero numero" << endl;
	cin >> num2;
}

// Le preguntamos al usuario que quiere hacer a traves de esta funcion
int opcion()
{
	int opcion_del_usuario = 0;
	cout << "[1] Suma" << endl;
	cout << "[2] Resta" << endl;
	cout << "[3] Multiplicion" << endl;
	cout << "[4] Division" << endl;
	cout << "Dame una opcion de las desplegadas: " << endl;
	cin >> opcion_del_usuario;
	return opcion_del_usuario; 
}


float suma() 
{
	float numero1 = 0, numero2 = 0;
	PedirDatos(numero1, numero2);
	return numero1 + numero2;
}

float resta()
{
	float numero1 = 0, numero2 = 0;
	PedirDatos(numero1, numero2);
	return numero1 - numero2;
}

float division()
{
	float numero1 = 0, numero2 = 0;
	PedirDatos(numero1, numero2);
	return numero1 / numero2;
}

float multiplicacion()
{
	float numero1 = 0, numero2 = 0;
	PedirDatos(numero1, numero2);
	return numero1 * numero2;
}
