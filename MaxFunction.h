#include "Function.h"
#include <utility>


class MaxFunction : public Function{
public:
    explicit MaxFunction(std::string text) :
            Function(std::move(text), std::vector<std::string> {"int", "float", "str", "date"}, 3) {}
    std::variant <Date, int, float, std::string> call(std::vector <Row>& data, const std::vector <std::string>& table_datatypes) override;
};
