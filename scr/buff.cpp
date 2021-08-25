//
// Created by User on 25.08.2021.
//

#include "buff.hpp"

Buffer::Buffer(Buffer &buffer) {
    this->persons = buffer.persons;
}

Buffer::Buffer(Buffer &&buffer) noexcept {
    this->persons = buffer.persons;
}

void Buffer::send_data() {
    // Блокировка на запись
    std::unique_lock ul(this->rw_mt);
    // Добавление данных в буфер
    this->persons.push_back(this->get_person());
}

Person Buffer::get_pers(const int &id) {
    // Блокировка на чтение
    std::shared_lock sl(this->rw_mt);
    // Копирование данных
    Person a(this->persons.at(id));
    // Удаление считанных данных
    this->persons.erase(this->persons.begin() + id);
    return a;
}

int Buffer::find_data(const std::string &c) {
    // Блокировка на чтение
    std::shared_lock sl(this->rw_mt);
    // Определение размера буфера
    int size = this->persons.size();
    // Поиск данных
    for (int i = 0; i < size; i++) {
        if (this->persons.at(i).get_category() == c) {
            return i;
        }
    }
    return -1;
}


