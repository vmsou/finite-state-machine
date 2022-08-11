/* Trabalho 1 - Máquinas de Estados Finitos
Aluno: Vinícius Marques da Silva de Oliveira
Data: 10/08/2022

# Enunciado
Para  obter  os  pontos  relativos  a  este  trabalho,  você  deverá  criar  um  programa,  utilizando  a 
linguagem  Python, C, ou C++.  Este  programa,  quando  executado,  irá  determinar  se  uma  string de 
entrada  faz  parte  da  linguagem  𝐿    definida  por  
𝐿 = {𝑥 | 𝑥 ∈ {𝑎,𝑏}∗ 𝑒 𝑐𝑎𝑑𝑎 𝑎 𝑒𝑚 𝑥 é 𝑠𝑒𝑔𝑢𝑖𝑑𝑜 𝑝𝑜𝑟 𝑝𝑒𝑙𝑜 𝑚𝑒𝑛𝑜𝑠 𝑑𝑜𝑖𝑠 𝑏} segundo o alfabeto  Σ={𝑎,𝑏,𝑐}.

O  programa  que  você  desenvolverá  irá  receber  como  entrada um arquivo de texto  (.txt) 
contendo várias strings. A primeira linha do arquivo indica quantas strings estão no arquivo de texto de 
entrada. As linhas subsequentes contém uma string por linha.  A seguir está um exemplo das linhas que 
podem existir em um arquivo de testes para o programa que você irá desenvolver: 

        3 
        abbaba 
        abababb 
        bbabbaaab 

Neste  exemplo  temos  3  strings  de  entrada.  O  número  de  strings em  cada  arquivo  será 
representado  por  um  número  inteiro  positivo.  A  resposta  do  seu  programa  deverá  conter  uma, e 
somente uma linha de saída para cada string. Estas linhas conterão a string de entrada e o resultado 
da validação conforme o formato indicado a seguir: 

    abbaba: não pertence.  

A  saída  poderá  ser  enviada  para  um  arquivo  de  textos,  ou  para  o  terminal  padrão  e  será 
composta de uma linha de saída por string de entrada. No caso do exemplo, teremos 3 linhas de saída. 
Para que seu programa possa ser testado você deve criar, no mínimo, três arquivos de entrada 
contendo um número diferente de strings diferentes. Os arquivos de entrada criados para os seus testes 
devem estar disponíveis tanto no ambiente repl.it quanto no ambiente Github. Observe que o professor 
irá  testar  seu  programa  com  os  arquivos  de  testes  que  você  criar  e  com,  no  mínimo  um  arquivo  de 
testes criado pelo próprio professor.  

Regras:
alfabeto = {a ,b, c}
linguagem = {x | x ∈ {a, b}*} e cada a seguido por bb
*/

#include "main.hpp"

int main() {
    std::cout << "> Inicio: Maquina de Estados Finitos" << '\n';
    std::cout << "Arquivos: 'data/text.txt', 'data/valido.txt', 'data/invalido.txt'\n";
    std::cout << "Pressione ENTER (nome do arquivo vazio) para finalizar programa.\n\n";

    LanguageMap_T language_map{
        {"LETRA", {"a", "b", "c"}}
    };

    Tokenizer tokenizer{ &language_map };
    Parser parser{ &tokenizer };
    TextData td{};
    
    bool is_running = true;
    while (is_running) {
        std::cout << "Arquivo: ";
        std::string filename;
        std::getline(std::cin, filename);
        
        if (filename.empty()) { is_running = false; continue; }
        
        try {
            td = TextData::load(filename);
        } catch (const std::runtime_error &err) {
            std::cout << err.what() << "\n\n";
            continue;
        }
    
        for (const std::string& text : td.texts) {
            bool result = parser.valid(text);
            std::cout << text << ": ";
            if (result) std::cout << "pertence";
            else std::cout << "nao pertence";
            std::cout << '\n';
        }
        std::cout << '\n';
    }
    std::cout << "> Fim: Maquina de Estados Finitos" << '\n';
}
