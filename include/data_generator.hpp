//
// Created by User on 24.08.2021.
//

#ifndef CMAKE_TEST_INCLUDE_SEND_DATA_HPP_
#define CMAKE_TEST_INCLUDE_SEND_DATA_HPP_

#include "data.hpp"
#include <vector>
#include <string>

class Data_gen : Person{
public:
    /*
     * Конструктор по умолчанию
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
    /* Генерация новой персоны
     * @return - Person
     */
    Person get_person() override;
    /* Метод add
     * Добовляет новое имя, если его нет еще в списке,
     * если имя уже существует, возвращает false, иначе true
     * @name - новое имя
     * @return - bool
     */
    bool add_names(const std::string &name);
    /* Метод add
     * Добовляет новую фамилию, если её нет еще в списке,
     * если фамилия уже существует, возвращает false, иначе true
     * @surname - новая фамилия
     * @return - bool
     */
    bool add_surnames(const std::string &surname);
    /* Метод del
     * Удаляет имя из списка имен, если такого имени нет
     * возвращает false, иначе true
     * @name - удаляемое имя
     * @return - bool
     */
    bool del_name(const std::string &name);
    /* Метод del
     * Удаляет фамилию из списка имен, если такой фамилии нет
     * возвращает false, иначе true
     * @name - удаляемое имя
     * @return - bool
     */
    bool del_surname(const std::string &surname);

private:
    std::vector<std::string> names = { "Rodriges", "Rodslav", "Roso", "Olivia", "Ava", "Emeli", "Poppy", "Mia", "Isla",
        "Jessica" };
    std::vector<std::string> surnames = { "Adamson", "Evans", "Jonson", "Davies", "Wilson", "Parson", "Elington",
        "Gilbert", "Flatcher" };
    int num_names {};
    int num_surnames {};
    int max_age {};
};

#endif //CMAKE_TEST_INCLUDE_SEND_DATA_HPP_
