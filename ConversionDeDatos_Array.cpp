#include <iostream>
#include <string>

//Determina si una cadena es entero o no
bool esEntero(std::string cadena){
    return cadena.find_first_not_of("0123456789-") == std::string::npos;
}

//Convierte un string a int
int stringToInt(std::string cadena){
    return std::stoi(cadena);
}

int main () {
    std::string entrada;
    getline(std::cin, entrada);
    int entero = 0;
    if(esEntero(entrada)){
        entero = stringToInt(entrada);
    }
    std::cout << entero << "\n";
    std::cout << entero + 1 << "\n";
}
