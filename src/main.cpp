/* Trabalho 1 - Máquinas de Estados Finitos
Aluno: Vinícius Marques da Silva de Oliveira
Data: 10/08/2022

Regras:
alfabeto = {a ,b, c}
linguagem = {x | x ∈ {a, b}*} e cada a seguido por bb
*/

#include <fstream>
#include <iostream>

#include "parser.hpp"
#include "reading.hpp"
#include "tokenizer.hpp"

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vector);

int main() {
    std::cout << "> Inicio: Maquina de Estado Finito" << '\n';
    std::cout << "Arquivos: 'data/text.txt', 'data/valido.txt', 'data/invalido.txt'\n";
    std::cout << "Pressione ENTER (filename vazio) para finalizar programa.\n";

    std::unordered_set<char> alphabet{'a', 'b', 'c'};
    Tokenizer tokenizer{alphabet};
    Parser parser{&tokenizer};
    TextData td{};
    
    bool is_running = true;
    while (is_running) {
        std::cout << "filename: ";
        std::string filename;
        std::getline(std::cin, filename);
        
        if (filename.empty()) { is_running = false; continue; }
        
        try {
            td = TextData::load(filename);
        } catch (const std::runtime_error &err) {
            std::cout << err.what() << "\n\n";
            continue;
        }
    
        for (const std::string &text : td.texts) {
            ParseResult result = parser.parse(text);
            std::cout << text << ": ";
            if (result.kind == "VALID") std::cout << "pertence";
            else std::cout << "nao pertence";
            std::cout << '\n';
        }
        std::cout << '\n';
    }
    std::cout << "> Fim: Maquina de Estado Finito" << '\n';
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vector) {
  os << "[";
  for (std::size_t i = 0; i < vector.size(); ++i) {
    os << vector[i];
    if (i < vector.size() - 1)
      os << ", ";
  }
  return os << "]";
}