
#ifndef MASSAGE_TRANSFER_INCLUDE_TRANSFER_HPP_
#define MASSAGE_TRANSFER_INCLUDE_TRANSFER_HPP_

#include "buff.hpp"
#include "reader.hpp"
#include <chrono>
#include <map>
#include <thread>
#include <iostream>
#include <mutex>
#include <vector>
#include <future>

class Transfer : private Buffer {
public:
    /*
     * Конструктор
     * @c - Категории
     * @path - Путь к файлу данных
     * @a - Количество циклов
     */
    explicit Transfer(const std::vector<std::string> &c, const std::string path, const int &a, const int &delay);
    /*
     * Деструктор
     */
    ~Transfer() = default;
    /*
     * Метод run
     * Пуск операций чтения записи
     */
    void run();
    /*
     * Метод get_data()
     * Возвращает считанные данные
     * @return - std::map<std::string, std::vector<Humans_data>>
     */
    [[maybe_unused]] std::map<std::string, std::vector<Humans_data>> get_data() const;
    /*
     * Конструктор копирования
     */
    [[maybe_unused]] Transfer(Transfer &transfer);
    /*
     * Конструктор перемещения
     */
    [[maybe_unused]] Transfer(Transfer &&transfer);
private:
    /*
     * Функция read_data
     * Читает данные из буфера и выводит в консоль
     * @c - Категория
     */
    void read_data(const std::string &c) override;
    /*
     * Функция write_data
     * Генерирует и пишет данные в буфер
     */
    void write_data();
    /*
     * Функция show_data
     * Выводит данные в консоль
     */
    void show_data(const std::string &c) const;
    std::map<std::string, std::vector<Humans_data>> data; // Считанные данные
    std::vector<std::string> keys {}; // Ключи (категории)
    int num_transfers {}; // Количество отсылаемых данных
    int time_delay_ms {}; // Время задержки
    mutable std::recursive_mutex io_mt; // Барьер для записи и вывода прочитанных данных
    mutable std::promise<bool> stop; // Остановка чтения
    mutable std::future<bool> end_transfer; // Сигнал остановки чтения
};

#endif //MASSAGE_TRANSFER_INCLUDE_TRANSFER_HPP_
