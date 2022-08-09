/* Analisador Sintático e Semântico */

#include <string>

#include "tokenizer.hpp"

class Parser {
    // Attributes
    private:
        Tokenizer* tokenizer;
    // Constructors
    public:
        Parser(Tokenizer* tokenizer);
    // Methods
    public:
        bool valid(const std::string expr);

        bool ST_START(std::deque<Token>& tokens);
        bool ST_0(std::deque<Token>& tokens);
        bool ST_1(std::deque<Token>& tokens);
};