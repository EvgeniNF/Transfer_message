#include <iostream>
#include "transfer.hpp"
#include <vector>
#include <string>

void run(){
    std::vector<std::string> categories = { "Boss", "Worker" };
    std::string path = "d:\\C++\\Transfer_message\\build-debug\\app\\data.txt";
    int num_operations = 100;
    int delay = 100;
    Transfer t(categories, path, num_operations, delay);
    t.run();
}

int main(){
    run();
    system("pause");
    return 0;
}
