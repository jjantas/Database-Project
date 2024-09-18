#include "Function.h"
#include <utility>


class RightFunction : public Function{
public:
    explicit RightFunction(std::string text) :
            Function(std::move(text), std::vector<std::string> {"str"}, 3) {}
    std::variant <Date, int, float, std::string> call(std::vector <Row>& data, const std::vector <std::string>& table_datatypes) override;
};
