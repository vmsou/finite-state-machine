#include "parser.hpp"

Parser::Parser(Tokenizer* tokenizer): tokenizer{ tokenizer } {}

ParseResult Parser::parse(const std::string expr) {
    std::vector<Token> tokens = this->tokenizer->tokenize(expr);

    bool valid = true;
    bool counting = false;
    int  b_count = 0;
    for (const Token& t : tokens) {
        if (t.kind == "LETTER") {
            if (t.letter == 'a' && !counting) { counting = true; b_count = 0; valid = false; }
            else if (counting && b_count == 1 && t.letter == 'b') { counting = false; b_count = 0; valid = true; }
            else if (counting && t.letter == 'b') ++b_count;
            else if (counting && b_count < 2 && t.letter != 'b') return ParseResult{ "INVALID", "'a' precisa ser seguido de 'bb'" };
        }
        else if (t.kind == "INVALID") return ParseResult{ "INVALID", "caractere invalido" };
    }
    if (valid) return ParseResult{"VALID"};
    return ParseResult{"INVALID"};
}