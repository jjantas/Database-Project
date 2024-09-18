#include "Function.h"
#include <utility>


class SortFunction : public Function {
public:
    explicit SortFunction(std::string text) :
            Function(std::move(text), std::vector<std::string> {"int", "float", "str", "date"}, 1) {}
    std::variant <Date, int, float, std::string> call(std::vector <Row>& data, const std::vector <std::string>& table_datatypes);
};
