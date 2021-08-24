//
// Created by User on 24.08.2021.
//

#ifndef CMAKE_TEST_INCLUDE_SEND_DATA_HPP_
#define CMAKE_TEST_INCLUDE_SEND_DATA_HPP_

#include "data.hpp"
#include <vector>

class Data_gen{
public:
    /*
     * Конструктор
     */
    Data_gen();
    /*
     * Конструктор копирования
     * @data_gen - копируемые данные
     */
    Data_gen(Data_gen &data_gen) = default;
    /*
     * Конструктор перемещения
     * @data_gen - перемещаемые данные
     */
    Data_gen(Data_gen &&data_gen) = default;
    /*
     * Деструктор
     */
    ~Data_gen() = default;
    /*
     * Генерация данных
     */
    Person gen_data();
    /* Функция add
     * Добовляет новое имя в список
     */
    void add_num_names(const std::string &name);
    /* Функция add
     * Добовляет новую фамилию в список
     */
    void add_num_surnames(const std::string &surname);

private:
    std::vector<std::string> names = { "Rodriges", "Rodslav", "Roso", "Olivia", "Ava", "Emeli", "Poppy", "Mia", "Isla",
        "Jessica" };
    std::vector<std::string> surnames = { "Adamson", "Evans", "Jonson", "Davies", "Wilson", "Parson", "Elington",
        "Gilbert", "Flatcher" };
    int num_names {};
    int max_age {};
};

#endif //CMAKE_TEST_INCLUDE_SEND_DATA_HPP_
