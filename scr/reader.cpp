//
// Created by User on 25.08.2021.
//

#include <reader.hpp>

std::string Reader::get_category() const {
    return this->category;
}

void Reader::set_category(const std::string &c) {
    this->category = c;
}

void Reader::add_human(Person p) {
    this->names.push_back(p.get_name());
    this->surnames.push_back(p.get_surname());
    this->age.push_back(p.get_age());
}

