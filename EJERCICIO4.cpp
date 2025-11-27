#include <iostream>
#include <cmath>
using namespace std;

double potencia(double x, int n) 
{
    if (n == 0) return 1.0;            
    return x * potencia(x, n - 1);    
}

long long factorial(int n) 
{
    if (n <= 1) return 1;             
    return n * factorial(n - 1);     
}

double termino_seno(double x, int n)   // Calcula el término n-ésimo de la serie de Taylor del seno
{
    
    return (n % 2 == 0 ? -1 : 1) * potencia(x, 2 * n + 1) / factorial(2 * n + 1); 
}

double seno_Taylor(double x, int n, int terminoActual = 0)
{
    if (terminoActual > n) return 0;   // Condición de parada de la recursión

    // Suma recursiva de los términos de la serie de Taylor
    return termino_seno(x, terminoActual) + 
           seno_Taylor(x, n, terminoActual + 1);
}

double termino_coseno(double x, int n) // Calcula el término n-ésimo del coseno
{
    
    return (n % 2 == 0 ? 1 : -1) * potencia(x, 2 * n) / factorial(2 * n);
}

double coseno_Taylor(double x, int n, int terminoActual = 0)
{
    if (terminoActual > n) return 0;
    return termino_coseno(x, terminoActual) + coseno_Taylor(x, n, terminoActual + 1); 
}
int main() 
{
    double grados;
    cout << "Ingrese angulo en grados: ";
    cin >> grados;

    double radianes = grados * M_PI / 180.0;  

    cout << "sen(" << grados << "°) ≈ " 
         << seno_Taylor(radianes, 15) << endl;

    cout << "cos(" << grados << "°) ≈ " 
         << coseno_Taylor(radianes, 15) << endl;

    return 0;
}