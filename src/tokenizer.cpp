#include "tokenizer.hpp"

/* Token */
// Constructors
Token::Token(std::string kind, char letter): kind{ kind }, letter{ letter } {}

/* Tokenizer */
// Constructors
Tokenizer::Tokenizer(const std::unordered_set<char>& alphabet): alphabet{ alphabet } {}

// Methods
std::vector<Token> Tokenizer::tokenize(const std::string& text) {
    this->ss = std::stringstream(text);
    std::vector<Token> tokens;

    while (!this->is_empty()) {
        Token t = this->get();;
        tokens.push_back(t);
    }
    tokens.emplace_back("END", ' ');
    return tokens;
}

Token Tokenizer::get() {
    char ch;
    this->ss >> ch;

    if (this->alphabet.find(ch) != this->alphabet.end()) return Token("LETTER", ch);
    return Token("INVALID", ch);
}

const bool Tokenizer::is_empty() { return this->ss.rdbuf()->in_avail() == 0; }

// Functions
std::ostream& operator<<(std::ostream& os, const Token& t) {
    return os << "Token(" << "kind='" << t.kind << "', letter='" << t.letter << "')";
}