#include "Header.h"
//Очистка ввода
void Check::clearInput() {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}
//Ввод числа в заданном диапазоне
int Check::checkNumberInRange(const std::string& prompt, int min_value, int max_value) {
    int value;
    bool valid_input = false;
    std::string input;

    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        //Ввод не пуст
        if (input.empty()) {
            std::cout << "Ошибка: ввод не может быть пустым" << std::endl;
            continue;
        }
        //Ввод только цифр
        bool is_valid = true;
        for (size_t i = 0; i < input.length(); i++) {
            char c = input[i];
            if (i == 0 && c == '-') continue;
            if (!std::isdigit(static_cast<unsigned char>(c))) {
                is_valid = false;
                break;
            }
        }

        if (!is_valid) {
            std::cout << "Ошибка: введите целое число" << std::endl;
            continue;
        }

        value = std::stoi(input);
        //Ввод чисел в заданном диапазоне
        if (value < min_value || value > max_value) {
            std::cout << "Ошибка: число должно быть от " << min_value << " до " << max_value << std::endl;
        }
        else {
            valid_input = true;
        }
    } while (!valid_input);

    return value;
}
//Ввод чисел
int Check::checkNumberSimple(const std::string& prompt) {
    int value;
    bool valid_input = false;
    std::string input;

    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        //Вввод не пуст
        if (input.empty()) {
            std::cout << "Ошибка: ввод не может быть пустым" << std::endl;
            continue;
        }
        //Ввод только цифр
        bool is_valid = true;
        for (size_t i = 0; i < input.length(); i++) {
            char c = input[i];
            if (i == 0 && c == '-') continue;
            if (!std::isdigit(static_cast<unsigned char>(c))) {
                is_valid = false;
                break;
            }
        }

        if (!is_valid) {
            std::cout << "Ошибка: введите целое число" << std::endl;
            continue;
        }

        value = std::stoi(input);
        valid_input = true;

    } while (!valid_input);

    return value;
}
//Ввод строки
std::string Check::getStringInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}
//Проверка вводимой строки
bool Check::isValidRingString(const std::string& str) {
    //Строка не пуста
    if (str.empty()) {
        std::cout << "Ошибка: строка не может быть пустой" << std::endl;
        return false;
    }
    //Длина строки не менее 3
    if (str.length() < 3) {
        std::cout << "Ошибка: длина кольца должна быть не менее 3 цифр" << std::endl;
        return false;
    }
    //Длина строки не более 1000
    if (str.length() > 1000) {
        std::cout << "Ошибка: длина строки не должна превышать 1000 символов" << std::endl;
        return false;
    }
    //Строка содержит только цифры
    for (char c : str) {
        if (!std::isdigit(static_cast<unsigned char>(c))) {
            std::cout << "Ошибка: строка должна содержать только цифры" << std::endl;
            return false;
        }
    }

    return true;
}
//Ввод названия входного файла
std::string Check::getFileName(const std::string& prompt) {
    std::string filename;
    do {
        filename = getStringInput(prompt);
        //Входной файл не может быть пустым
        if (filename.empty()) {
            std::cout << "Ошибка: имя файла не может быть пустым" << std::endl;
        }
    } while (filename.empty());
    return filename;
}