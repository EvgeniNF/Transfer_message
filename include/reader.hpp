//
// Created by User on 25.08.2021.
//

#ifndef MASSAGE_TRANSFER_INCLUDE_READER_HPP_
#define MASSAGE_TRANSFER_INCLUDE_READER_HPP_

#include "data.hpp"
#include <string>
#include <vector>

struct Humans_data{
    Humans_data(std::string n, std::string s, unsigned short int a) : name(n), surname(s), age(a) {}
    //Humans_data(Humans_data &Humans_data());
    //Humans_data(Humans_data &&Humans_data());
    //virtual ~Humans_data();
    //Humans_data operator= (Humans_data());
    std::string name {};
    std::string surname {};
    unsigned short int age {};
};

#endif //MASSAGE_TRANSFER_INCLUDE_READER_HPP_
