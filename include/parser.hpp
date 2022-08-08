#include <vector>
#include <string>

#include "tokenizer.hpp"

struct ParseResult {
    std::string kind = "NONE";
    std::string msg = "";
    int value = 0;
};

class Parser {
    // Attributes
    private:
        Tokenizer* tokenizer;
    // Constructors
    public:
        Parser(Tokenizer* tokenizer);
    // Methods
    public:
        ParseResult parse(const std::string expr);

        bool ST_START(std::deque<Token>& tokens);
        bool ST_0(std::deque<Token>& tokens);
        bool ST_1(std::deque<Token>& tokens);
};