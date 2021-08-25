//
// Created by User on 24.08.2021.
//

#include "writer.hpp"
#include "iostream"

Writer::Writer() {
    // Подсчет количества имен
    this->num_names = static_cast<int> (this->names.size());
    // Подсчет количества фамилий
    this->num_surnames = static_cast<int> (this->surnames.size());
    // Подсчет количества категорий
    this->num_categories = static_cast<int> (this->categories.size());
    // установка максимального количества лет
    this->max_age = 110;
}

[[maybe_unused]] bool Writer::add_category(const std::string &category) {
    // Проверка на наличие категории в списке
    for (auto i = this->categories.begin(); i != this->categories.end(); i++){
        if (*i == category) { return false; }
    }
    // Добовление категории
    this->surnames.push_back(category);
    this->num_categories++;
    return true;
}

[[maybe_unused]] bool Writer::del_category(const std::string &category) {
    // Поиск и удаление категории
    for (auto i = this->categories.begin(); i != this->categories.end(); i++){
        if (*i == category) {
            this->categories.erase(i);
            this->num_categories--;
            return true;
        }
    }
    return false;
}

[[maybe_unused]] bool Writer::add_names(const std::string &name) {
    // Проверка на наличие имени в списке
    for (auto i = this->names.begin(); i != this->names.end(); i++){
        if (*i == name) { return false; }
    }
    // Добовление имение
    this->surnames.push_back(name);
    this->num_names++;
    return true;
}

[[maybe_unused]] bool Writer::add_surnames(const std::string &surname) {
    // Проверка на наличие фамилии в списке
    for (auto i = this->surnames.begin(); i != this->surnames.end(); i++){
        if (*i == surname) { return false; }
    }
    // Добовление фамилии
    this->surnames.push_back(surname);
    this->num_surnames++;
    return true;
}

[[maybe_unused]] bool Writer::del_surname(const std::string &surname) {
    // Поиск и удаление фамилии
    for (auto i = this->surnames.begin(); i != this->surnames.end(); i++){
        if (*i == surname) {
            this->surnames.erase(i);
            this->num_surnames--;
            return true;
        }
    }
    return false;
}

[[maybe_unused]] bool Writer::del_name(const std::string &name) {
    // Поиск и удаление имени
    for (auto i = this->names.begin(); i != this->names.end(); i++){
        if (*i == name) {
            this->names.erase(i);
            this->num_names--;
            return true;
        }
    }
    return false;
}

Person Writer::get_person() {
    // Генерация имени
    std::string name = this->names.at(rand() % this->num_names);
    // Генерация фамилии
    std::string surname = this->surnames.at(rand() % this->num_surnames);
    // Генерация категории
    std::string category = this->categories.at(rand() % this->num_categories);
    // Генерация возраста
    auto age = static_cast<unsigned short int>(rand() % this->max_age);
    return Person(name, surname, category, age);
}







