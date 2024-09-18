#include "Function.h"
#include <utility>


class MonthFunction : public Function{
public:
    explicit MonthFunction(std::string text) :
            Function(std::move(text), std::vector<std::string> {"date"}, 2) {}
    std::variant <Date, int, float, std::string> call(std::vector <Row>& data, const std::vector <std::string>& table_datatypes) override;
};
