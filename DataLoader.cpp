#include "DataLoader.h"



std::vector<std::string> DataLoader::load_datatypes(const std::string& path) {
    std::ifstream file(path);
    std::string firstLine;
    if (file.is_open()) {
        std::getline(file, firstLine);
        file.close();
    } else {
        std::cerr << "Unable to open file: " << path << std::endl;
    }
    std::vector<std::string> output;
    output = splitter(firstLine);
    return output;
}

std::vector<Row> DataLoader::load_data(const std::string& path, const std::vector<std::string>& datatypes) {
    std::ifstream file(path);
    std::vector<Row> output;
    std::string line;
    if (file.is_open()) {
        std::getline(file, line);
        while (std::getline(file, line)) {
            Row added_row;
            std::vector <std::string> line_split = splitter(line);
            added_row.load(line_split, datatypes);
            output.push_back(added_row);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << path << std::endl;
    }
    return output;
}

std::vector<std::string> DataLoader::splitter(const std::string& line) {
    std::vector<std::string> result;
    size_t start = 0;
    size_t end = line.find(',');
    while (end != std::string::npos) {
        result.push_back(line.substr(start, end - start));
        start = end + 1;
        end = line.find(',', start);
    }
    result.push_back(line.substr(start));
    return result;
}

std::vector<int> DataLoader::load_column_widths(const std::string &path) {
    std::ifstream file(path);
    std::vector<int> output;
    std::string line;
    if (file.is_open()) {
        std::getline(file, line);
        for (int i = 0; i < line.size(); i++){
            output.push_back(0);
        }
        while (std::getline(file, line)) {
            std::vector <std::string> line_split = splitter(line);
            for (int index = 0; index < line_split.size(); index++){
                if (line_split.size() > output[index]){
                    output[index] = static_cast<int>(line_split.size());
                }
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << path << std::endl;
    }
    return output;
}

