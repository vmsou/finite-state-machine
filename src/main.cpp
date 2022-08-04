/* Trabalho 1 - Máquinas de Estados Finitos
Aluno: Vinícius Marques da Silva de Oliveira
Data: 10/08/2022
*/

#include <fstream>
#include <iostream>

#include "reading.hpp"
#include "tokenizer.hpp"

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vector);

int main() {
    std::cout << "> Start" << '\n';
    std::ifstream ifs{"text.txt"};
    if (!ifs) throw std::runtime_error{"Não foi possivel abrir o arquivo."};
    
    TextData td{};
    ifs >> td;
    
    std::unordered_set<char> alphabet{'a', 'b', 'c'};
    Tokenizer tokenizer{alphabet};

    // std::vector<Token> tokens = tokenizer.tokenize(td.texts[0]);
    for (const std::string& text : td.texts) { 
        std::vector<Token> tokens = tokenizer.tokenize(text);
        std::cout << text << '\n' << tokens << "\n\n";
    }

    std::cout << "> End" << '\n';
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vector) {
    os << "[";
    for (std::size_t i = 0; i < vector.size(); ++i) {
        os <<  vector[i];
        if (i < vector.size() - 1) os << ", ";
    }
    return os << "]";
}