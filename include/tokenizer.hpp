#pragma once
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>

#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

struct Token {
    // Attributes
    std::string kind;
    char letter;

    // Constructors
    Token(std::string kind = "NONE", char letter = '\0');
};

struct Tokenizer {
    // Attributes
    private:
        std::stringstream ss;
        std::unordered_set<char> alphabet;

    // Constructors
    public:
        Tokenizer(const std::unordered_set<char>& alphabet);

    // Methods
    public:
        std::vector<Token> tokenize(const std::string& text);
        Token get();
        const bool is_empty();
};

// Functions
std::ostream& operator<<(std::ostream& os, const Token& t);

#endif