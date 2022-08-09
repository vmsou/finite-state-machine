/* Analisador Léxico */

#pragma once
#include <deque>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

using LanguageMap_T = std::unordered_map<std::string, std::unordered_set<std::string>>;

struct Token {
    // Attributes
    std::string kind;
    std::string text;

    // Constructors
    Token(std::string kind="NONE", std::string text="");
};

struct Tokenizer {
    // Attributes
    private:
        std::stringstream ss;
        LanguageMap_T* language_map;
        std::unordered_map<std::string, std::string> reverse_map;

    // Constructors
    public:
        Tokenizer(LanguageMap_T* language_map);

    // Methods
    public:
        std::string get_kind(const std::string& text) const;
        std::deque<Token> tokenize(const std::string& text);
        Token get();
        bool is_empty() const;
};

// Functions
std::ostream& operator<<(std::ostream& os, const Token& t);

#endif
