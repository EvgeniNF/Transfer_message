//
// Created by User on 24.08.2021.
//

#ifndef CMAKE_TEST_INCLUDE_DATA_HPP_
#define CMAKE_TEST_INCLUDE_DATA_HPP_

#include <string>

struct Person {
public:
    Person() = default;
    explicit Person(std::string n, std::string s, unsigned short int a) {
        name = n;
        surname = s;
        age = a;
    }
    virtual Person get_person() { return *this; };
    void set_name(std::string n) { name = n; }
    void set_surname(std::string s) { surname = s; }
    void set_age(unsigned short int a) { age = a; }
    std::string get_name() const { return name; }
    std::string get_surname() const { return surname; }
    unsigned short int get_age() const { return age; }
    Person (Person &person){
        name = person.get_name();
        surname = person.get_surname();
        age = person.get_age();
    }
    Person(Person &&person) = default;
    ~Person() = default;

private:
    std::string name {};
    std::string surname {};
    unsigned short int age {};
};


#endif //CMAKE_TEST_INCLUDE_DATA_HPP_
