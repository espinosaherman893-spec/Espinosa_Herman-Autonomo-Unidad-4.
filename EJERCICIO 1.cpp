
/*Escribe una función recursiva que genere todas las permutaciones 
posibles de una cadena de texto.  
Por ejemplo:  
Entrada: "abc".  
Salida:  
abc    
acb    
bac    
bca    
cab    
cba    
La cadena puede ser de 2 caracteres en adelante sin restricciones de 
cantidad de caracteres. */



#include <iostream> 
#include <string>   
#include <algorithm> 
using namespace std;

void generar_Permutationes(string str, int start) {

    if (inicio == str.length() - 1) {
        cout << str << endl;
        return; 
    }
    
    // Para cada posición desde 'start' hasta el final de la cadena
    for (int i = inicio; i < str.length(); i++) {
       
        swap(str[inicio], str[i]);
        
        //  uso recursividad para la función con el siguiente índice
        generar_Permutationes(str, inicio + 1);
        
        // hago el intercambio  para probar otras opciones
        swap(str[inicio], str[i]);
    }
}

int main() {
    string input; 
    cout << "Ingresa una cadena de texto (al menos 2 caracteres): ";
    cin >> input;  
    
   
    generar_Permutationes(input, 0);
    
    return 0; 
}
