#include "reading.hpp"

std::ostream& operator<<(std::ostream& os, const TextData& td) {
    os << td.size;
    for (std::size_t i = 0; i < td.texts.size(); ++i) {
        const std::string& text = td.texts[i];
        os << text;
        if (i < td.texts.size() - 1) os << '\n';
    }
    return os;
}

std::istream& operator>>(std::istream& is, TextData& td) {
    int size = 0;
    is >> size;
    td.size = size;
    
    
    std::string text;
    while (size >= 0 && std::getline(is, text)) { 
        td.texts.push_back(text); 
        --size;    
    }
    return is;
}