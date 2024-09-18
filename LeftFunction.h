#include "Function.h"
#include <utility>


class LeftFunction : public Function{
public:
    explicit LeftFunction(std::string text) :
            Function(std::move(text), std::vector<std::string> {"str"}, 3) {}
    std::variant <Date, int, float, std::string> call(std::vector <Row>& data, const std::vector <std::string>& table_datatypes) override;
};
