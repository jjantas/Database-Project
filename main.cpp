#include "Database.h"


int main() {
    Database ex;
    ex.load("test.txt");
    ex.print();
    ex.launch();
    return 0;
}
