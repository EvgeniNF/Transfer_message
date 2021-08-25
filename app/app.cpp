#include <iostream>
#include "transfer.hpp"
#include <vector>
#include <string>

int main(){

    std::vector<std::string> categories = {"Boss", "Worker"};
    Transfer t(categories);
    t.run();
    system("pause");
    return 0;
}
