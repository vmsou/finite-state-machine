/* Analisador Sintático e Semântico */

#include "parser.hpp"

Parser::Parser(Tokenizer* tokenizer): tokenizer{ tokenizer } {}

bool Parser::ST_START(std::deque<Token>& tokens) {
    if (tokens.empty()) return true;

    const Token& t = tokens.front(); tokens.pop_front();
    if (t.kind != "LETRA") return false;
    if (t.text == "b") return this->ST_START(tokens);
    else if (t.text == "a") return this->ST_0(tokens);
    else if (t.text == "c") return false;

    return true;
}

bool Parser::ST_0(std::deque<Token>& tokens) {
    if (tokens.empty()) return false;

    const Token& t = tokens.front(); tokens.pop_front();
    if (t.kind != "LETRA") return false;
    if (t.text == "b") return this->ST_1(tokens);
    
    return false;
}

bool Parser::ST_1(std::deque<Token>& tokens) {
    if (tokens.empty()) return false;

    const Token& t = tokens.front(); tokens.pop_front();
    if (t.kind != "LETRA") return false;
    if (t.text == "b") return this->ST_START(tokens);

    return false;
}

bool Parser::valid(const std::string& expr) {
    std::deque<Token> tokens = this->tokenizer->tokenize(expr);

    bool accepted = this->ST_START(tokens);
    return accepted;
}
