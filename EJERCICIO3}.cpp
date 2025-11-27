/* Escribe un programa en C++ que determine cuántos elementos de la 
serie de Fibonacci se encuentran en el rango entre 1000 y 2000. 
El programa debe usar funciones recursivas para: 
• Generar los números de la serie de Fibonacci. 
• Contar cuántos de esos números están dentro del rango solicitado. */


#include <iostream>
using namespace std;

//función recursiva para generar números de Fibonacci
int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

//función recursiva para contar elementos en el rango [1000, 2000]
int contar_enRango(int n, int contador)
{
    int fib = fibonacci(n);
    
    // Si el número de Fibonacci supera 2000, detener la recursión
    if (fib > 2000)
    {
        return contador;
    }
    
    // Si el número está en el rango [1000, 2000], incrementar el contador
    if (fib >= 1000 && fib <= 2000)
    {
        cout << "Fibonacci(" << n << ") = " << fib << endl;
        return contar_enRango(n + 1, contador + 1);
    }
    else
    {
        return contar_enRango(n + 1, contador);
    }
}

int main()
{
    cout << "Números de Fibonacci en el rango [1000, 2000]:" << endl;
    int total = contar_enRango(0, 0);
    cout << "\nTotal de elementos en el rango: " << total << endl;
    return 0;
}