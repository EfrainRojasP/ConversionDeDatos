#include <iostream>
#include <string>
#include <bitset>

//Cantidad de bits que usaremos
const int TAM_BITS = 24;

//Determina si una cadena es entero o no
bool esEntero(std::string cadena){
    return cadena.find_first_not_of("0123456789-") == std::string::npos;
}

//Convierte un string a int
int stringToInt(std::string cadena){
    return std::stoi(cadena);
}

//Inicializa el array en 0's
void llenarBits_24(char bits[]){
    for(int i = 0; i < TAM_BITS; ++i){
        bits[i] = '0';
    }
}

void imprime(char arr[]){
    for(int i = 0; i < TAM_BITS; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

//Convierte el entero a binario
void convierteToBinario(int entero, char bits[]){
    int i = TAM_BITS - 1;
    while(entero != 0){
        char c = entero % 2 == 0 ? '0': '1';
        bits[i--] = c;
        entero /= 2;
    }
}



int main () {
    char bits_24[TAM_BITS];
    llenarBits_24(bits_24);
    std::string entrada;
    getline(std::cin, entrada);
    imprime(bits_24);
    convierteToBinario(2022, bits_24);
    imprime(bits_24);
}
