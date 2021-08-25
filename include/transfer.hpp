//
// Created by User on 25.08.2021.
//

#ifndef MASSAGE_TRANSFER_INCLUDE_TRANSFER_HPP_
#define MASSAGE_TRANSFER_INCLUDE_TRANSFER_HPP_

#include "buff.hpp"
#include "reader.hpp"
#include <chrono>
#include <map>
#include <thread>
#include <iostream>
#include <mutex>
#include <vector>

class Transfer : Buffer {
public:
    Transfer(const std::vector<std::string> &c);
    //Transfer(Transfer &transfer);
    //Transfer(Transfer &&transfer);
    ~Transfer() = default;
    void read_data(const std::string &c) override;
    void write_data();
    void run();

private:
    void show_data(const std::string &c) const;
    std::map<std::string, std::vector<Humans_data>> data;
    mutable std::recursive_mutex io_mt;
};



#endif //MASSAGE_TRANSFER_INCLUDE_TRANSFER_HPP_
