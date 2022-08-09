/* Analisador Léxico */

#include "tokenizer.hpp"

/* Token */
// Constructors
Token::Token(std::string kind, std::string text): kind{ kind }, text{ text } {}

/* Tokenizer */
// Constructors
Tokenizer::Tokenizer(LanguageMap_T* language_map): language_map{ language_map } {
    for (const auto& item : *language_map) {
        const std::string& key = item.first;
        const std::unordered_set<std::string>& value = item.second;

        for (const std::string& text : value) this->reverse_map[text] = key;
    }
}

// Methods
std::string Tokenizer::get_kind(const std::string& text) {
    if (this->reverse_map.find(text) == this->reverse_map.end()) return "INVALID";
    return this->reverse_map[text];
}

std::deque<Token> Tokenizer::tokenize(const std::string& text) {
    this->ss = std::stringstream(text);
    std::deque<Token> tokens;

    while (!this->is_empty()) {
        Token t = this->get();;
        tokens.push_back(t);
    }
    return tokens;
}

Token Tokenizer::get() {
    std::string text;

    char ch;
    this->ss >> ch;

    text += ch;

    std::string kind = this->get_kind(text);
    return Token(kind, text);
}

const bool Tokenizer::is_empty() { return this->ss.rdbuf()->in_avail() == 0; }

// Functions
std::ostream& operator<<(std::ostream& os, const Token& t) {
    return os << "Token(" << "kind='" << t.kind << "', text='" << t.text << "')";
}