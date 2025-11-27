/* Ejercicio 5: Diseña tu propio ejercicio completo 
Objetivo: 
Proponer un ejercicio original que permita practicar todos los conceptos 
vistos hasta ahora en C++, incluyendo: 
• Funciones (pueden usar funciones normales, sobrecargadas o 
plantillas). 
• Estructuras condicionales  
• Estructuras de repetición 
• Recursión  */

#include <iostream>  
#include <vector>    

using namespace std;  

// Función recursiva para calcular la suma de números pares en la secuencia
int sumaRecursiva(const vector<int>& secuencia, int indice) {
    if (indice >= secuencia.size()) {
        return 0; 
    }
    int actual = secuencia[indice];
    if (actual % 2 == 0) {  
        return actual + sumaRecursiva(secuencia, indice + 1);
    } else { 
        return sumaRecursiva(secuencia, indice + 1);
    }
}

long long productoImpares(const vector<int>& secuencia) {
    long long producto = 1;  
    for (int numero : secuencia) {  
        if (numero % 2 != 0) { 
            producto *= numero;
        }
    }
    return producto;
}

// Función plantilla para verificar si todos los números son positivos
template <typename T>  
bool todosPositivos(const vector<T>& secuencia) {
    int i = 0;  
    while (i < secuencia.size()) {  
        if (secuencia[i] <= 0) { 
            return false;
        }
        i++;  
    }
    return true;  
}

// Versión para suma 
void mostrarResultado(int suma) {
    cout << "Suma de pares: " << suma << endl;
}
// Versión para producto long long
void mostrarResultado(long long producto) {
    cout << "Producto de impares: " << producto << endl;
}

int main() {
    vector<int> secuencia;  // Vector para guardar los números
    int numero;
    
    cout << "Ingresa una secuencia de numeros enteros (termina con 0):" << endl;
    while (true) { 
        cout << "Numero: ";
        cin >> numero;
        if (numero == 0) {  
            break;
        }
        secuencia.push_back(numero);  
    }
    
    
    int sumaPares = sumaRecursiva(secuencia, 0);
    long long productoImparesValor = productoImpares(secuencia);
    bool esMagica = todosPositivos(secuencia);
    
    
    mostrarResultado(sumaPares);
    mostrarResultado(productoImparesValor);
    
   
    if (esMagica) { 
        cout << "La secuencia es MAGICA (todos positivos)" << endl;
    } else { 
        cout << "La secuencia NO es magica (hay negativos o cero)" << endl;
    }
    
    return 0;
}
