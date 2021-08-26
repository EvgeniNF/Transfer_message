
#ifndef CMAKE_TEST_INCLUDE_DATA_HPP_
#define CMAKE_TEST_INCLUDE_DATA_HPP_

#include <string>

/*
 * Класс Person,
 * хранит данные о человеке
 */
class Person {
public:
    /*
     * Конструктор по умолчанию
     */
    [[maybe_unused]] Person() = default;
    /*
     * Конструктор с параметрами.
     * Устанавливает имя, фамилию, категорию, возраст
     */
    explicit Person(std::string n, std::string s, std::string c, unsigned short int a);
    /*
     * Интерфейсный метод,
     * для получения объекта Person
     */
    [[maybe_unused]] virtual Person get_person() { return *this; };
    /*
     * Метод set_category
     * Устанавливает категорию
     * @c - Категория
     */
    [[maybe_unused]] void set_category(const std::string &c) { category = c; }
    /*
     * Метод set_name
     * Устанавливает имя
     * @n - Имя
     */
    [[maybe_unused]] void set_name(const std::string &n) { name = n; }
    /*
     * Метод set_surname
     * Устанавливает фамилию
     * @s - Фамилия
     */
    [[maybe_unused]] void set_surname(const std::string &s) { surname = s; }
    /*
     * Метод set_age
     * Устанавливает возраст
     * @a - Возраст
     */
    [[maybe_unused]] void set_age(const unsigned short int &a) { age = a; }
    /*
     * Метод get_category
     * Возвращает категорию
     * @return - std::string
     */
    [[nodiscard]] std::string get_category() const { return category; }
    /*
     * Метод get_name
     * Возвращает имя
     * @return - std::string
     */
    [[nodiscard]] std::string get_name() const { return name; }
    /*
     * Метод get_surname
     * Возвращает фамилию
     * @return - std::string
     */
    [[nodiscard]] std::string get_surname() const { return surname; }
    /*
     * Метод get_age
     * Возвращает возраст
     * @return - unsigned short int
     */
    [[nodiscard]] unsigned short int get_age() const { return age; }
    /*
     * Конструктор копирования
     * @person - Копируемый объект
     */
    Person (const Person &person) : name(person.name), surname(person.surname),
                                    category(person.category),age(person.age) {};
    /*
     * Конструктор перемещения
     * @person - Перемещаемый объект
     */
    Person(Person &&person) noexcept = default;
    /*
     * Оператор "="
     * Возвращает копию объекта
     * @person - Копируемый объект
     * @return - Person
     */
    [[maybe_unused]] Person& operator= (const Person &person);
    /*
     * Виртуальный деструктор.
     * Разрушает объект
     */
    virtual ~Person() = default;

private:
    std::string name {};  // Имя
    std::string surname {}; // Фамилия
    std::string category {}; // Категория
    unsigned short int age {}; // Возраст
};

#endif //CMAKE_TEST_INCLUDE_DATA_HPP_
