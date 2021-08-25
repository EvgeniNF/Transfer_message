//
// Created by User on 25.08.2021.
//

#ifndef MASSAGE_TRANSFER_INCLUDE_TRANSFER_HPP_
#define MASSAGE_TRANSFER_INCLUDE_TRANSFER_HPP_

#include <thread>
#include "buff.hpp"
#include "reader.hpp"
#include "writer.hpp"

namespace transfer {
void write_data(Writer &w, Buffer &b, bool &stop);
void read_data(Reader &r, Buffer &b, bool &stop);
void run();
}

#endif //MASSAGE_TRANSFER_INCLUDE_TRANSFER_HPP_
