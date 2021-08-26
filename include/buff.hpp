
#ifndef MASSAGE_TRANSFER_INCLUDE_BUFF_HPP_
#define MASSAGE_TRANSFER_INCLUDE_BUFF_HPP_

#include "data.hpp"
#include "writer.hpp"
#include <vector>
#include <shared_mutex>

/*
 * Класс Buffer,
 * является буфером обмена
 */
class Buffer : public Writer {
public:
    /*
     * Конструктор по умолчанию
     */
    Buffer() = default;
    /*
     * Конструктор копирования
     */
    [[maybe_unused]] Buffer(Buffer &buffer);
    /*
     * Конструктор перемещения
     */
    [[maybe_unused]] Buffer(Buffer &&buffer) noexcept;
    /*
     * Виртуальный деструктор
     */
    virtual ~Buffer() = default;
    /*
     * Метод send_data
     * Записывает данные в буфер
     */
    void send_data();
    /*
     * Метод find_data
     * Выполняет поиск по категории,
     * Если персона не найдена возвращает -1
     * @c - Категория
     */
    [[nodiscard]] int find_data(const std::string &c);
    /*
     * Метод delete_data
     * Выполняет удаление персоны из буфера
     * @id - Номер элемента в векторе
     */
    void delete_data(const int &id);
    /*
     * Метод get_pers
     * Возвращает персону из вектора
     * @id - Номер элемента в векторе
     */
    Person get_pers(const int &id);
    /*
     * Интерфейсный метод
     */
    virtual void read_data(const std::string &c) = 0;

private:
    std::vector<Person> persons{}; // Буфер
    std::shared_mutex rw_mt; // Барьер чтения записи в буфер
};

#endif //MASSAGE_TRANSFER_INCLUDE_BUFF_HPP_
