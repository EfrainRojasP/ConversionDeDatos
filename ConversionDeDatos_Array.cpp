#include <iostream>
#include <string>
#include <bitset>
#include <unordered_map>


//Cantidad de bits que usaremos
const int TAM_BITS = 24;

struct {
    char bits_24[TAM_BITS];
    std::string hexadecimal;
} resultadoEntero;

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
        if(i % 4 == 0 && i != 0){
            std::cout << " ";
        }
        std::cout << arr[i];
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

//Crea una tabla hash, donde estan contenidos los valores de binario a hexadecimal
char creaUnorderMapHexadecimal(std::string cuartetoBits){
    std::unordered_map<std::string,char> hex;
    hex["0000"] = '0';
    hex["0001"] = '1';
    hex["0010"] = '2';
    hex["0011"] = '3';
    hex["0100"] = '4';
    hex["0101"] = '5';
    hex["0110"] = '6';
    hex["0111"] = '7';
    hex["1000"] = '8';
    hex["1001"] = '9';
    hex["1010"] = 'A';
    hex["1011"] = 'B';
    hex["1100"] = 'C';
    hex["1101"] = 'D';
    hex["1110"] = 'E';
    hex["1111"] = 'F';

    //std::cout << hex.find(cuartetoBits) << "\n";

    if(hex.find(cuartetoBits) == hex.end()){
        std::cout << "N E";
        return '!';
    } else {
        std::unordered_map<std::string,char>:: iterator it = hex.find(cuartetoBits);
        return it->second;
    }

}

//Convierte de binario a hexadecimal
std::string convierteToHexadecimal(char bits[]){
    std::string cuartetoBits = "";
    std::string hexadecimal;
    for(int i = 0; i < TAM_BITS + 1; ++i){
        if(i != 0 && i % 4 == 0){
            std::cout << cuartetoBits << "\n";
            char hex = creaUnorderMapHexadecimal(cuartetoBits);
            cuartetoBits = "";
            hexadecimal += hex;
        }
        cuartetoBits += bits[i];
    }
    return hexadecimal;
}

//Comprueba si es un entero positivo
bool esEnteroPositivo(int entero){
    return entero > 0;
}

//Valor absoluto del entero
int valorAbsoluto(int entero){
    return entero * -1;
}

void complementoA2(){

}

void formatoDatosEntero_SIC_XE(int entero, char bits[]){
    if(esEnteroPositivo(entero)){
        convierteToBinario(entero, bits);
        resultadoEntero.hexadecimal = convierteToHexadecimal(bits);
    } else {

    }
}

int main () {
    std::string entrada;
    getline(std::cin, entrada);
    if(esEntero(entrada)){
        int entero = stringToInt(entrada);
        llenarBits_24(resultadoEntero.bits_24);
        formatoDatosEntero_SIC_XE(entero,resultadoEntero.bits_24);
        imprime(resultadoEntero.bits_24);
        std::cout << resultadoEntero.hexadecimal << "\n";
    } else {
        std::cout << "ADIOS";
        return 0;
    }
    //std::string hexadecimal = convierteToHexadecimal(bits_24);
    //std::cout << hexadecimal << "\n";
}
