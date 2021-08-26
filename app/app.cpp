#include <iostream>
#include "transfer.hpp"
#include <vector>
#include <string>

void run(){
    std::vector<std::string> categories = { "Boss", "Worker" };
    std::string path = "data.txt";
    int num_operations {};
    int delay {};
    std::cout << "-- Please enter num of operation: ";
    std::cin >> num_operations;
    std::cout << "-- Enter delay of send message: ";
    std::cin >> delay;
    std::cout << "-- Result: " << std::endl;
    Transfer t(categories, path, num_operations, delay);
    t.run();
}

int main(){
    run();
    system("pause");
    return 0;
}
