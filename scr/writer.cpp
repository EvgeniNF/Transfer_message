
#include "writer.hpp"

Writer::Writer() {
    // Подсчет количества имен
    this->num_names = static_cast<int> (this->names.size());
    // Подсчет количества фамилий
    this->num_surnames = static_cast<int> (this->surnames.size());
    // Подсчет количества категорий
    this->num_categories = static_cast<int> (this->categories.size());
}

[[maybe_unused]] bool Writer::add_category(const std::string &category) {
    // Проверка на наличие категории в списке
    for (auto i = this->categories.begin(); i != this->categories.end(); i++){
        if (*i == category) { return false; }
    }
    // Добовление категории
    this->categories.push_back(category);
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
    this->names.push_back(name);
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

bool Writer::read_data_from_time(const std::string &path) {
    std::ifstream in_str(path);
    std::string line;
    if (in_str.is_open()){
        int lines = 0;
        std::vector<std::string> pointers;
        while(std::getline(in_str, line)){
            if (lines == 0){
                // Поиск ключевых слов
                for (int i = 0; i < 2; i++){
                    auto pos = line.find(";");
                    if(pos == std::string::npos) {
                        in_str.close();
                        return false;
                    }
                    else{
                        pointers.push_back(line.substr(0, pos));
                        line.erase(0, pos + 1);
                    }
                }
            }
            else{
                // Заполнение данных
                auto dev = line.find(":");
                std::string c = line.substr(0, dev);
                std::string data = line.substr(dev + 1, line.length() - 1);
                if (c == pointers.at(0)){
                    this->add_names(data);
                }
                else if (c == pointers.at(1)){
                    this->add_surnames(data);
                }
                else {
                    in_str.close();
                    return false;
                }
            }
            lines++;
        }
    }
    else {
        return false;
    }
    in_str.close();
    return true;
}
