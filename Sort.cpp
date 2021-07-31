#include <iostream>
#include <vector>

using namespace std;

void FillData(vector<int> &vector, int tamano_del_arreglo)
{
	for (size_t i = 0; i < tamano_del_arreglo; i++)
	{
		int elemento = 0;
		cout << "Elemento " << i + 1 << endl;
		cin >> elemento;
		vector.push_back(elemento);
	}
}

void ToSort(vector<int> &vector) 
{
	int aux = 0;
	for (size_t j = 0; j < vector.size(); j++)
	{
		for (size_t i = 0; i < vector.size() - 1; i++)
		{
			if (vector[i] < vector[i + 1])
			{
				aux = vector[i];
				vector[i] = vector[i + 1];
				vector[i + 1] = aux;
			}
		}
	}
}

void PrintVector(vector<int>& vector)
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		cout << vector[i] << endl;;
	}
}

int main() {
	int tamanio = 0;
	cout << "¿Cuantos elementos quieres ingresar?" << endl;
	cin >> tamanio;
	vector<int> vector;
	FillData(vector, tamanio);
	ToSort(vector);
	PrintVector(vector);
	return 0;
}

