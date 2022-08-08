/* Trabalho 1 - Máquinas de Estados Finitos
Aluno: Vinícius Marques da Silva de Oliveira
Data: 10/08/2022

Regras:
alfabeto = {a ,b, c}
linguagem = {x | x ∈ {a, b}*} e cada a seguido por bb
*/

#include <fstream>
#include <iostream>
#include <unordered_map>

#include "parser.hpp"
#include "reading.hpp"
#include "tokenizer.hpp"

int main() {
    std::cout << "> Inicio: Maquina de Estado Finito" << '\n';
    std::cout << "Arquivos: 'data/text.txt', 'data/valido.txt', 'data/invalido.txt'\n";
    std::cout << "Pressione ENTER (nome do arquivo vazio) para finalizar programa.\n\n";

    LanguageMap_T language_map{
        {"LETTER", {"a", "b", "c"}}
    };

    Tokenizer tokenizer{ language_map };
    Parser parser{ &tokenizer };
    TextData td{};
    
    bool is_running = true;
    while (is_running) {
        std::cout << "arquivo: ";
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
            bool result = parser.valid(text);
            std::cout << text << ": ";
            if (result) std::cout << "pertence";
            else std::cout << "nao pertence";
            std::cout << '\n';
        }
        std::cout << '\n';
    }
    std::cout << "> Fim: Maquina de Estado Finito" << '\n';
}
