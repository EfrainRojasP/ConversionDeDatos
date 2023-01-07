#include <iostream>
#include <string>

//Determina si una cadena es entero o no
bool esEntero(std::string cadena){
    return cadena.find_first_not_of("0123456789-") == std::string::npos;
}


int main () {
    std::string entrada;
    getline(std::cin, entrada);
    bool i = esEntero(entrada);
    std::cout << i << "\n";
}
