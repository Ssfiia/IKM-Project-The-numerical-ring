#include <string>
#include <iostream>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "Windows.h"

//Структура узла односвязного кольцевого списка
struct RingNode {
    char digit;
    RingNode* next;

    RingNode(char d) : digit(d), next(nullptr) {}
};

//Класс для работы с кольцевым списком цифр
class RingList {
private:
    RingNode* head;
    int size;

    void copyFrom(const RingList& other);

public:
    //Конструктор пустого списка
    RingList();
    //Конструктор из строки
    RingList(const std::string& digits);
    //Конструктор копирования
    RingList(const RingList& other);
    //Оператор присваивания
    RingList& operator=(const RingList& other);
    //Деструктор
    ~RingList();
    //Очистка список
    void clear();
    //Проверка на пустоту
    bool isEmpty() const;
    //Получение размера
    int getSize() const;
    //Добавление цифры
    void addDigit(char digit);
    //Получение цифры по индексу
    char getDigit(int index) const;
    //Преобразование в строку
    std::string toString() const;
    //Извлечение последовательность цифр из списка
    std::string extractSubring(int start, int length) const;
    //Проверка совпадения последовательностей
    bool isSameSequence(const std::string& seq, int startPos) const;
};

//Класс решения 
class RingSolver {
private:
    RingList ring;
    int n;
    //Проверка является ли строка числом
    bool isValidNumber(const std::string& num) const;
    //Сумма двух чисел
    std::string addStrings(const std::string& a, const std::string& b) const;

public:
    //Конструктор
    RingSolver(const RingList& ringList);
    //Деструктор
    ~RingSolver();
    //Поиск решения A + B = C в кольце
    std::string solve();
};

//Класс проверок 
class Check {
public:
    //Очистка после ввода
    static void clearInput();
    //Ввод числа в диапазоне
    static int checkNumberInRange(const std::string& prompt, int min_value, int max_value);
    //Ввод любого целого числа
    static int checkNumberSimple(const std::string& prompt);
    //Ввод строки
    static std::string getStringInput(const std::string& prompt);
    //Проверка корректности длины строки
    static bool isValidRingString(const std::string& str);
    //Ввод названия входного файла
    static std::string getFileName(const std::string& prompt);
};

// Структура для хранения результата ввода
struct InputResult {
    std::string ringDigits;
    bool success;
};

//Вывод главного меню
void printMainMenu();
//Вывод меню выбора способа ввода
void printInputMenu();
//Ввод кольца с клавиатуры
InputResult inputFromKeyboard();
//Ввод кольца из файла
InputResult inputFromFile();
//Выбор метода ввода
InputResult getRingData();
//Отображение полученных данных
void displayRingData(const std::string& ringDigits);
//Отображение результата
void displayResult(const std::string& result);
//Сохранение результата в файл
void saveResultToFile(const std::string& result);