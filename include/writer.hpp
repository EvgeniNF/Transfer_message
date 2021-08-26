
#ifndef CMAKE_TEST_INCLUDE_SEND_DATA_HPP_
#define CMAKE_TEST_INCLUDE_SEND_DATA_HPP_

#include "data.hpp"
#include <vector>
#include <string>
#include <fstream>

/* Класс Writer
 * Генератор данных,
 * создает объекты Person
 */
class Writer : public Person{
public:
    /*
     * Конструктор по умолчанию
     */
    Writer();
    /*
     * Конструктор копирования
     * @data_gen - копируемые данные
     */
    Writer(Writer &writer) = default;
    /*
     * Конструктор перемещения
     * @data_gen - перемещаемые данные
     */
    Writer(Writer &&writer) noexcept = default;
    /*
     * Виртуальный деструктор
     */
    virtual ~Writer() = default;
    /* Генерация новой персоны
     * @return - Person
     */
    Person get_person() override;
    /* Метод add_names
     * Добавляет новое имя, если его нет еще в списке,
     * если имя уже существует, возвращает false, иначе true
     * @name - новое имя
     * @return - bool
     */
    [[maybe_unused]] bool add_names(const std::string &name);
    /* Метод add_surnames
     * Добавляет новую фамилию, если её нет еще в списке,
     * если фамилия уже существует, возвращает false, иначе true
     * @surname - новая фамилия
     * @return - bool
     */
    [[maybe_unused]] bool add_surnames(const std::string &surname);
    /* Метод del_name
     * Удаляет имя из списка имен, если такого имени нет
     * возвращает false, иначе true
     * @name - удаляемое имя
     * @return - bool
     */
    [[maybe_unused]] bool del_name(const std::string &name);
    /* Метод del_surname
     * Удаляет фамилию из списка имен, если такой фамилии нет
     * возвращает false, иначе true
     * @name - удаляемое имя
     * @return - bool
     */
    [[maybe_unused]] bool del_surname(const std::string &surname);
    /* Метод add_surname
     * Добавляет категорию в список, если категория
     * существует, возвращает false, иначе true
     * @category - добавляемая категория
     * @return - bool
     */
    [[maybe_unused]] bool add_category(const std::string &category);
    /* Метод del_category
     * Удаляет категорию из списка категорий, если такой категории нет
     * возвращает false, иначе true
     * @category - удаляемая категория
     * @return - bool
     */
    [[maybe_unused]] bool del_category(const std::string &category);
    /*
     * Интерфейсный метод
     */
    virtual void send_data() = 0;
    /*
     * Чтение данных для генерации из файла.
     * Возвращает результат чтения, если данные
     * считаны то true, иначе false
     * @path - Путь к файлу
     */
    [[nodiscard]] bool read_data_from_time(const std::string &path);
    /*
     * Метод set_max_age
     * Устанавливает максимальный возраст
     * @m_a - Максимальный возраст
     */
    [[maybe_unused]] void set_max_age(const int &m_a) { this->max_age = m_a; };
    /*
     * Метод get_max_age
     * Возвращает максимальный возраст
     * @return - int
     */
    [[maybe_unused]] int get_max_age() const { return this->max_age; };

private:
    std::vector<std::string> names = {}; // Имена
    std::vector<std::string> surnames {}; // Фамилии
    std::vector<std::string> categories {}; // Категории
    int num_names {};   // Количество имен
    int num_surnames {}; // Количество фамилий
    int num_categories {}; // Количество категорий
    int max_age = 110;  // Максимальный возраст
};

#endif //CMAKE_TEST_INCLUDE_SEND_DATA_HPP_
