#include <iostream>
using namespace std;

// Templates, macros genericas, se declaran con la palabra reservada template, pueden ser funciones o clases

template <typename T, typename U>
T GreaterNumber(T number1, U number2)
{
    return (number1 > number2) ? number1 : number2;
}

int main()
{
    int x = 0, y = 0;
    cin >> x >> y;
    cout << GreaterNumber(x, y) << endl;
    cout << GreaterNumber(7, 3.1) << endl;
    //cout << GreaterNumber("Hola", 8) << endl;
    cout << GreaterNumber('c', '+') << endl;
    cout << GreaterNumber("Hola", "Hello") << endl;
}