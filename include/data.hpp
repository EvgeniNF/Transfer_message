//
// Created by User on 24.08.2021.
//

#ifndef CMAKE_TEST_INCLUDE_DATA_HPP_
#define CMAKE_TEST_INCLUDE_DATA_HPP_

#include <string>

class Person {
public:
    Person() = default;
    explicit Person(std::string n, std::string s,
                    std::string c, unsigned short int a) {
        name = n;
        surname = s;
        category = c;
        age = a;
    }
    [[maybe_unused]] virtual Person get_person() { return *this; };
    [[maybe_unused]] void set_category(const std::string &c) { category = c; }
    [[maybe_unused]] void set_name(const std::string &n) { name = n; }
    [[maybe_unused]] void set_surname(const std::string &s) { surname = s; }
    [[maybe_unused]] void set_age(const unsigned short int &a) { age = a; }
    std::string get_category() const { return category; }
    std::string get_name() const { return name; }
    std::string get_surname() const { return surname; }
    unsigned short int get_age() const { return age; }
    Person (const Person &person) : name(person.name), surname(person.surname),
                                    category(person.category),age(person.age) {};
    Person(Person &&person) noexcept = default;
    Person& operator= (const Person &person){
        this->name = person.name;
        this->surname = person.surname;
        this->category = person.category;
        this->age = person.age;
        return *this;
    }
    virtual ~Person() = default;

private:
    std::string name {};
    std::string surname {};
    std::string category {};
    unsigned short int age {};
};

#endif //CMAKE_TEST_INCLUDE_DATA_HPP_
