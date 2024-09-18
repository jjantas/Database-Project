#include "Decomposer.h"


std::string Decomposer::prefix(const std::string &text) {
    size_t pos = text.find('(');
    if (pos != std::string::npos) {
        return text.substr(0, pos);
    }
    return text;
}

std::vector<std::string> Decomposer::arguments(const std::string& text) {
    size_t startPos = text.find('(');
    if (startPos != std::string::npos) {
        size_t endPos = text.find(')', startPos);
        if (endPos != std::string::npos) {
            return splitter(text.substr(startPos + 1, endPos - startPos - 1));
        }
    }
    std::vector <std::string> empty_output;
    return empty_output;
}

std::vector<std::string> Decomposer::splitter(const std::string &row_from_text) {
    std::vector<std::string> result;
    size_t start = 0;
    size_t end = row_from_text.find(',');
    while (end != std::string::npos) {
        result.push_back(row_from_text.substr(start, end - start));
        start = end + 1;
        end = row_from_text.find(',', start);
    }
    result.push_back(row_from_text.substr(start));
    return result;
}

int Decomposer::column_to_int(const std::string &column) {
    int result = 0;
    for (char letter : column) {
        result = result * 26 + (letter - 'A' + 1);
    }
    return result - 1;

}
