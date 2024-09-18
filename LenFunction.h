#include "Function.h"
#include <utility>


class LenFunction : public Function{
public:
    explicit LenFunction(std::string text) :
            Function(std::move(text), std::vector<std::string> {"str"}, 2) {}
    std::variant <Date, int, float, std::string> call(std::vector <Row>& data, const std::vector <std::string>& table_datatypes) override;
};
