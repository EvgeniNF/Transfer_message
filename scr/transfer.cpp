//
// Created by User on 25.08.2021.
//

#include "transfer.hpp"


Transfer::Transfer(const std::vector<std::string> &c) {
    for (auto &i : c) {
        this->data.extract(i);
    }
}

void Transfer::write_data() {
    for (int i = 0; i <= 10; i++) {
        Buffer::send_data();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Transfer::read_data(const std::string &c) {
    // Поиск данных
    int id = find_data(c);
    // Заполнение
    if (id != -1) {
        Person np = get_pers(id);
        std::lock_guard<std::recursive_mutex> lg(this->io_mt);
        this->data.at(c).push_back(Humans_data(np.get_name(), np.get_surname(), np.get_age()));
        this->show_data(c);
    }
}

void Transfer::show_data(const std::string &c) const {
    // Блокировка для вывода данных
    std::lock_guard<std::recursive_mutex> lg(this->io_mt);
    // Вывод данных
    auto el = static_cast<unsigned long int>(this->data.at(c).size()) - 1;
    std::cout << "This thread id: " << std::this_thread::get_id();
    std::cout << " | " << "Category: " << c;
    std::cout << " | " << "Name: " << this->data.at(c).at(el).name;
    std::cout << " | " << "Surname: " << this->data.at(c).at(el).surname;
    std::cout << " | " << "Age: " << this->data.at(c).at(el).age;
    std::cout << " | " << "Number operation: " << el + 1 << std::endl;
}

void Transfer::run() {
    std::thread th_wr([this]() { write_data(); });
    std::thread th_rd_1;
    std::thread th_rd_2;
    th_wr.join();
    th_rd_1.join();
    th_rd_2.join();
}


