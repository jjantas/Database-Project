#include "Function.h"
#include <utility>


class MeanFunction : public Function {
public:
    explicit MeanFunction(std::string text) :
            Function(std::move(text), std::vector<std::string> {"int", "float"}, 3) {}
    std::variant <Date, int, float, std::string> call(std::vector <Row>& data, const std::vector <std::string>& table_datatypes) override;
};
