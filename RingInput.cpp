#include "Header.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
//Вывод главного меню
void printMainMenu() {
    std::cout << "\n|| ГЛАВНОЕ МЕНЮ ||" << std::endl;
    std::cout << "1. Ввести новое кольцо" << std::endl;
    std::cout << "0. Выйти из программы" << std::endl;
}
//Вывод меню для выбора способа ввода
void printInputMenu() {
    std::cout << "\n|| Выберите способ ввода данных ||" << std::endl;
    std::cout << "1. Загрузить кольцо из файла" << std::endl;
    std::cout << "2. Ввести кольцо с клавиатуры" << std::endl;
    std::cout << "0. Назад в главное меню" << std::endl;

}
//Ввод с клавиатуры
InputResult inputFromKeyboard() {
    InputResult result;
    std::string ringDigits;
    std::cout << "\n|| ВВОД С КЛАВИАТУРЫ ||" << std::endl;

    do {
        ringDigits = Check::getStringInput("Введите строку цифр: ");
    } while (!Check::isValidRingString(ringDigits));

    result.ringDigits = ringDigits;
    result.success = true;

    return result;
}
//Ввод из файла
InputResult inputFromFile() {
    InputResult result;
    std::string ringDigits;
    std::cout << "\n|| ЗАГРУЗКА ИЗ ФАЙЛА ||" << std::endl;

    std::string inputFilename = Check::getFileName("Введите имя входного файла: ");

    std::ifstream inFile(inputFilename);
    //Проверка на открытие файла
    if (!inFile.is_open()) {
        std::cerr << "Ошибка: не удалось открыть входной файл \"" << inputFilename << "\"" << std::endl;
        result.success = false;
        return result;
    }

    std::getline(inFile, ringDigits);
    inFile.close();

    // Вывод содержимого файла на экран
    std::cout << "\nСодержимое файла \"" << inputFilename << "\":" << std::endl;
    std::cout << ringDigits << std::endl;
    //Проверка на корректность данных в файле
    if (!Check::isValidRingString(ringDigits)) {
        std::cout << "Файл содержит некорректные данные." << std::endl;
        result.success = false;
        return result;
    }

    result.ringDigits = ringDigits;
    result.success = true;

    return result;
}
//Выбор метода ввода
InputResult getRingData() {
    InputResult result;
    int inputMethod = 0;

    do {
        printInputMenu();
        inputMethod = Check::checkNumberInRange("Ваш выбор: ", 0, 2);

        switch (inputMethod) {
            if (inputMethod == 0) {
                result.success = false;
                return result;
            }
        case 1:
            result = inputFromFile();
            break;
        case 2:
            result = inputFromKeyboard();
            break;
        }

        if (!result.success) {
            std::cout << "\nОшибка ввода. Попробуйте снова." << std::endl;
        }

    } while (!result.success);

    return result;
}
//Вывод информация о кольце(строке)
void displayRingData(const std::string& ringDigits) {
    std::cout << "\n|| ИНФОРМАЦИЯ О КОЛЬЦЕ ||" << std::endl;
    std::cout << "Кольцо: " << ringDigits << std::endl;
    std::cout << "Длина: " << ringDigits.length() << " цифр" << std::endl;
}
//Вывд результата
void displayResult(const std::string& result) {
    std::cout << "\n|| РЕЗУЛЬТАТ ||" << std::endl;
    std::cout << result << std::endl;
}
//Сохранение результата в выходной файл
void saveResultToFile(const std::string& result) {
    std::cout << std::endl;
    std::string outputFilename = Check::getFileName("Введите имя выходного файла для сохранения результата: ");

    std::ofstream outFile(outputFilename);
    //Проверка на открытие файла
    if (!outFile.is_open()) {
        std::cerr << "Ошибка: не удалось создать выходной файл \"" << outputFilename << "\"" << std::endl;
    }
    else {
        outFile << result << std::endl;
        outFile.close();
        std::cout << "\nРезультат успешно записан в файл: " << outputFilename << std::endl;
    }
}