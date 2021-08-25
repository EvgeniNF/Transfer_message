//
// Created by User on 25.08.2021.
//

#ifndef MASSAGE_TRANSFER_INCLUDE_READER_HPP_
#define MASSAGE_TRANSFER_INCLUDE_READER_HPP_

#include "data.hpp"
#include <string>
#include <vector>


class Reader {
public:
    explicit Reader(std::string c) : category(c) {}
    Reader(Reader &reader) = default;
    Reader(Reader &&reader) = default;
    ~Reader() = default;
    std::string get_category() const;
    void set_category(const std::string &c);
    void add_human(Person p);

private:
    std::string category {};
    std::vector<std::string> names {};
    std::vector<std::string> surnames {};
    std::vector<unsigned short int> age {};
};

#endif //MASSAGE_TRANSFER_INCLUDE_READER_HPP_
