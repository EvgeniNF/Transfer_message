//
// Created by User on 25.08.2021.
//

#include "transfer.hpp"

void transfer::write_data(Writer &w, Buffer &b, bool &stop) {
    for (int i = 0; i < 40; i++){
        b.write_buff(w.get_person());
    }
    stop = true;
}

void transfer::read_data(Reader &r, Buffer &b, bool &stop) {
    while (!stop){
        int id = b.find_data(r.get_category());
        if (id != -1){
            r.add_human(b.get_person(id));
        }
    }
}

void transfer::run() {
    bool stop = false;
    Buffer buff;
    Writer wrt;
    Reader r_1("Boss"), r_2("Worker");
    std::thread th_wr(write_data, std::ref(wrt), std::ref(buff), std::ref(stop));
    std::thread th_r1(read_data, std::ref(r_1), std::ref(buff), std::ref(stop));
    std::thread th_r2(read_data, std::ref(r_2), std::ref(buff), std::ref(stop));

    th_wr.join();
    th_r1.join();
    th_r2.join();
}