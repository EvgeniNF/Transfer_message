
#include "data.hpp"

Person::Person(std::string n, std::string s, std::string c, unsigned short a) {
    this->name = n;
    this->surname = s;
    this->category = c;
    this->age = a;
}
Person &Person::operator=(const Person &person) {
    this->name = person.name;
    this->surname = person.surname;
    this->category = person.category;
    this->age = person.age;
    return *this;
}
