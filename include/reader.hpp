
#ifndef MASSAGE_TRANSFER_INCLUDE_READER_HPP_
#define MASSAGE_TRANSFER_INCLUDE_READER_HPP_

#include <string>
#include <vector>

/*
 * Структура Humans_data,
 * Хранит данные о человеке
 */
struct Humans_data{
    /*
     * Конструктор
     * Создает структуру и заносит данные в поля
     * @n - Имя
     * @s - Фамилия
     * @a - Возраст
     */
    explicit Humans_data(std::string n, std::string s, unsigned short int a) : name(n), surname(s), age(a) {}
    std::string name {}; // Имя
    std::string surname {}; // Фамилия
    unsigned short int age {}; // Возраст
};

#endif //MASSAGE_TRANSFER_INCLUDE_READER_HPP_
