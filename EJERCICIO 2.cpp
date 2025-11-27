/*Escribe un programa en C++ que reciba un número entero positivo n y 
muestre el número primo más grande que sea menor que n, usando 
funciones recursivas.*/


#include <iostream>
using namespace std;

bool n_primo(int num, int divisor) {
    
    if (divisor == num) {
        return true;
    }
  
    if (num % divisor == 0) {
        return false;
    }
   
    return n_primo(num, divisor + 1);
}

// Función para empezar a verificar si es primo 
bool check_Primo(int num) {
    if (num <= 1) return false; 
    return n_primo(num, 2);    
}

// Función recursiva para encontrar el primo más grande menor que n
int fin_Primo(int candidato) {
  
    if (candidato < 2) {
        return -1;
    }
  
    if (check_Primo(candidato)) {
        return candidato;
    }
    // Si no, pruebo con candidato - 1
    return fin_Primo(candidato - 1);
}
	// Función principal para encontrar el primo más grande menor que n
int encontrar_MayorPrimo_MenorQue_N(int n) {
    if (n <= 2) {
        return -1;  
    }
    return fin_Primo(n - 1);
}

int main() {
    int n;
    cout << "Ingresa un numero n mayor que 1: ";
    cin >> n;
    
    int result = encontrar_MayorPrimo_MenorQue_N(n);
    
    if (result == -1) {
        cout << "No hay primo menor que " << n << endl;
    } else {
        cout << "El primo mas grande menor que " << n << " es: " << result << endl;
    }
    
    return 0;
}
