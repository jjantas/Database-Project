#include "vector"
#include "string"
#include <bits/stdc++.h>
#include "Row.h"


class DataLoader {
public:
    DataLoader()= default;
    static std::vector <std::string> load_datatypes(const std::string& path);
    static std::vector <Row> load_data(const std::string& path, const std::vector<std::string>& datatypes);
    static std::vector <std::string> splitter(const std::string& line);
    static std::vector <int> load_column_widths(const std::string& path);
};
