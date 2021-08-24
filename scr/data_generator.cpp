//
// Created by User on 24.08.2021.
//

#include <data_generator.hpp>

Person Data_gen::gen_data() {
    Person new_person;
    // Генерация имени
    new_person.name = this->names.at(rand() % this->num_names);
    // Генерация фамилии
    new_person.surname = this->surnames.at(rand() % this->num_names);
    // Генерация возраста
    new_person.age = rand() % this->max_age;
    return new_person;
}

Data_gen::Data_gen() {
    this->num_names = static_cast<int> (this->names.size());
    this->max_age = 100;
}

void Data_gen::add_num_names(const std::string &name) {
    this->names.push_back(name);
}

