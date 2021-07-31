#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Forma de crear tus propias variables
// Solo dentro de las estructuras las variables no deberian ser inicializadas
struct Alumno
{
	int registro;
	string Nombre;
	vector<int> calificacion;
	vector<string> ListOfSubjects = {"Mate", "Fisica", "Bio", "Progra", "Electronica"};
};	// StudentA, StudentB, StudentC; (Tienen que ir antes del ;)// Declaracion de los elementos de una estructura
	// Declaracion de los elementos fuera de la struct
	//StudentA.Nombre = "Andre";
	//StudentA.Registro = 19300104; // Para acceder a los metodos se usa el punto
	//Alumno Rocio; // Instanciar un nuevo objeto de la estructura
	//Rocio.ListOfSubjects.push_back({ 'M', 'a', 't','e' });

void LLenarNombres(vector<Alumno> &alumno)
{
	for (size_t i = 0; i < alumno.size(); i++)
	{
		cout << "Nombre del Alumno[" << i + 1 << "]" << endl;
		cin >> alumno[i].Nombre;
	}
}

void LLenarRegistros(vector<Alumno> &alumno)
{
	for (size_t i = 0; i < alumno.size(); i++)
	{
		cout << "Registro de: " << alumno[i].Nombre << endl;
		cin >> alumno[i].registro;
	}
}

/*void LLenarMaterias(vector<Alumno>& alumnos){
	for (size_t i = 0; i < alumnos.size(); i++)
	{
		int numero_de_materias = 0;
		cout << "Numero de materias del alumno: " << alumnos[i].Nombre << endl;
		cin >> numero_de_materias;
		for (size_t j = 0; j < numero_de_materias; j++)
		{
			string nombre_de_la_materia = "";
			cout << "Materia[" << j + 1 << "]" << endl;
			cin >> nombre_de_la_materia;
			alumnos[i].ListOfSubjects.push_back(nombre_de_la_materia);
		}
	}
}*/

void LLenarCalificaciones(vector<Alumno> &alumnos)
{
	for (size_t i = 0; i < alumnos.size(); i++)
	{
		cout << "Calificaciones de " << alumnos[i].Nombre << endl;
		for (size_t j = 0; j < alumnos[i].ListOfSubjects.size(); j++)
		{
			int calificacion = 0;
			cout << "Calificacion de " << alumnos[i].ListOfSubjects[j] << ": ";
			cin >> calificacion;
			alumnos[i].calificacion.push_back(calificacion);
		}
	}
}

void NombresAprobados(vector<Alumno> alumnos, string materia, int &aprobados)
{
	cout << "Alumnos que si pasaron la materia " << materia << endl;
	for (int i = 0; i < alumnos.size(); ++i)
	{
		for (int j = 0; j < alumnos.size(); ++j)
		{
			if (materia.compare(alumnos[i].ListOfSubjects[j]) == 0)
			{
				if (alumnos[i].calificacion[j] >= 7)
				{
					cout << alumnos[i].Nombre << endl;
					aprobados++;
				}
			}
		}
	}
}

void DesplegarDatos(vector<Alumno> alumno)
{
	for (size_t i = 0; i < alumno.size(); i++)
	{
		cout << alumno[i].registro << endl;
	}
}

void DesplegarDatos(vector<Alumno> alumnos, int n)
{
	for (size_t i = 0; i < alumnos.size(); i++)
	{
		cout << "Alumno: " << alumnos[i].Nombre << endl;
		for (size_t j = 0; j < alumnos[i].calificacion.size(); j++)
		{
			cout << alumnos[i].calificacion[j] << endl;
		}
	}
}

void IndiceDeReprobados(vector<Alumno> alumnos, int pasaron)
{
	int porcentaje = 100, total_alumnos = alumnos.size();
	float indice = 0;
	indice = (porcentaje * pasaron) / total_alumnos;
	cout << "Porcentaje de los alumnos que pasaron " << setprecision(4) << indice << "%" << endl;
}

/*int main()
{
	int apropados = 0;
	size_t n = 0;
	cout << "Numero de alumnos: ";
	cin >> n;
	vector<Alumno> alumnos(n);
	cout << "Porfavor Ingresa el nombre de los alumnos: " << endl;
	LLenarNombres(alumnos);
	LLenarRegistros(alumnos);
	LLenarCalificaciones(alumnos);
	NombresAprobados(alumnos, "Mate", apropados);
	IndiceDeReprobados(alumnos, apropados);
}*/
