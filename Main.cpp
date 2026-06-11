#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Инициализация генератора случайных чисел
    srand((unsigned int)time(nullptr));

    std::cout << "\n||   ПРОГРАММА ДЛЯ ПОИСКА A + B = C В ЧИСЛОВОМ КОЛЬЦЕ   ||" << std::endl;
    bool running = true;

    while (running) {
        printMainMenu();
        int choice = Check::checkNumberInRange("Ваш выбор: ", 0, 1);

        if (choice == 0) {
            running = false;
            break;
        }

        // Получение данных кольца
        InputResult inputResult = getRingData();

        if (!inputResult.success || inputResult.ringDigits.empty()) {
            continue;
        }

        // Отображение информации о кольце
        displayRingData(inputResult.ringDigits);

        RingList ring(inputResult.ringDigits);
        RingSolver solver(ring);
        std::string result = solver.solve();

        // Вывод результата
        displayResult(result);

        saveResultToFile(result);

    }
    std::cout << "Программа завершена." << std::endl;
    std::cout << "\n  /\\_/\\  " << std::endl;
    std::cout << " ( o.o ) " << std::endl;
    std::cout << "  > ^ <  " << std::endl;
    std::cout << "   Мяу! " << std::endl;

    return 0;
}
