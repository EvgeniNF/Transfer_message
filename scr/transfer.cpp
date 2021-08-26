
#include "transfer.hpp"


Transfer::Transfer(const std::vector<std::string> &c, const std::string path, const int &a, const int &delay) {
    // Считывание данных для генератора
    if (!read_data_from_time(path)){
        std::cout << "Problem with data file!" << std::endl;
        delete this;
    }
    // Установка категорий
    for (auto &i : c) {
        this->data[i];
        this->add_category(i);
    }
    // Запись ключей
    this->keys = c;
    this->end_transfer = this->stop.get_future();
    // Запись количества операций
    this->num_transfers = a;
    this->time_delay_ms = delay;
}

void Transfer::write_data() {
    // Запись данных в буфер
    for (int i = 0; i < this->num_transfers; i++) {
        this->send_data();
        std::this_thread::sleep_for(std::chrono::milliseconds (this->time_delay_ms));
    }
    // Остановка операций чтения
    this->stop.set_value(true);
}

void Transfer::read_data(const std::string &c) {
    while (true){
        // Поиск данных
        int id = this->find_data(c);
        // Заполнение
        if (id != -1) {
            Person np = this->get_pers(id);
            this->delete_data(id);
            std::lock_guard<std::recursive_mutex> lg(this->io_mt);
            this->data.at(c).push_back(Humans_data(np.get_name(), np.get_surname(), np.get_age()));
            this->show_data(c);
        }
        else if (this->end_transfer.wait_for(std::chrono::seconds(0)) == std::future_status::ready){
            break;
        }
    }
}

void Transfer::show_data(const std::string &c) const {
    // Блокировка для вывода данных
    std::lock_guard<std::recursive_mutex> lg(this->io_mt);
    // Вывод данных
    auto el = static_cast<unsigned long int>(this->data.at(c).size()) - 1;
    std::cout << "-- This thread id: " << std::this_thread::get_id();
    std::cout << " | " << "Category: " << c;
    std::cout << " | " << "Name: " << this->data.at(c).at(el).name;
    std::cout << " | " << "Surname: " << this->data.at(c).at(el).surname;
    std::cout << " | " << "Age: " << this->data.at(c).at(el).age;
    std::cout << " | " << "Number operation: " << el + 1 << std::endl;
}

void Transfer::run() {
    // Генерация потоков
    std::thread th_wr([this] () { this->write_data(); });
    std::thread th_rd_1([this] () { this->read_data(this->keys.at(0)); });
    std::thread th_rd_2([this] () { this->read_data(this->keys.at(1)); });
    th_wr.join();
    th_rd_1.join();
    th_rd_2.join();
}

[[maybe_unused]] std::map<std::string, std::vector<Humans_data>> Transfer::get_data() const {
    // Блокируем для чтения
    std::lock_guard<std::recursive_mutex> lg(this->io_mt);
    return this->data;
}
