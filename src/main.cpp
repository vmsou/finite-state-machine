/* Trabalho 1 - Máquinas de Estados Finitos
Aluno: Vinícius Marques da Silva de Oliveira
Data: 10/08/2022
*/

#include <fstream>
#include <iostream>

#include "reading.hpp"

int main() {
    std::cout << "> Start" << '\n';
    std::ifstream ifs{"text.txt"};
    if (!ifs) throw std::runtime_error{"Não foi possivel abrir o arquivo."};
    
    TextData td{};
    ifs >> td;
    std::cout << td << '\n';
    std::cout << "> End" << '\n';
}
