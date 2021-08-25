//
// Created by User on 25.08.2021.
//

#ifndef MASSAGE_TRANSFER_INCLUDE_BUFF_HPP_
#define MASSAGE_TRANSFER_INCLUDE_BUFF_HPP_

#include "data.hpp"
#include "writer.hpp"
#include <vector>
#include <shared_mutex>
#include "reader.hpp"

class Buffer : public Writer {
public:
    /*
     * Конструктор по умолчанию
     */
    Buffer() = default;
    /*
     * Конструктор копирования
     */
    Buffer(Buffer &buffer);
    /*
     * Конструктор перемещения
     */
    Buffer(Buffer &&buffer) noexcept;
    /*
     * Деструктор по умолчанию
     */
    ~Buffer() = default;
    /*
     * Запись данных
     */
    void send_data();
    /*
     * Поиск данных
     */
    int find_data(const std::string &c);
    /*
     * Получение данных
     */
    Person get_pers(const int &id);
    /*
     * Интерфейсный метод
     */
    virtual void read_data(const std::string &c) = 0;

private:
    std::vector<Person> persons{}; // Буфер
    std::shared_mutex rw_mt;
};

#endif //MASSAGE_TRANSFER_INCLUDE_BUFF_HPP_
