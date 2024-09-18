#include "Function.h"
#include <utility>



class MinFunction : public Function{
public:
    explicit MinFunction(std::string text) :
            Function(std::move(text), std::vector<std::string> {"int", "float", "str", "date"}, 3) {}
    std::variant <Date, int, float, std::string> call(std::vector <Row>& data, const std::vector <std::string>& table_datatypes) override;
};
