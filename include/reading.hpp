#include <iostream>
#include <string>
#include <vector>

struct TextData {
    int size;
    std::vector<std::string> texts;
};

std::ostream& operator<<(std::ostream& os, const TextData& td);
std::istream& operator>>(std::istream& is, TextData& td);