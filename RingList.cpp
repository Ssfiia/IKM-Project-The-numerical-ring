#include "Header.h"
#include <stdexcept>
//Конструктор пустого списка
RingList::RingList() : head(nullptr), size(0) {}
//Конструктор из строки
RingList::RingList(const std::string& digits) : head(nullptr), size(0) {
    for (char d : digits) {
        addDigit(d);
    }
}
//Конструктор копирования
RingList::RingList(const RingList& other) : head(nullptr), size(0) {
    copyFrom(other);
}
//Оператор присваивания
RingList& RingList::operator=(const RingList& other) {
    // проверка на самоприсваивание
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}
//Деконструктор
RingList::~RingList() {
    clear();
}
//Очистка списка
void RingList::clear() {
    if (head == nullptr) return;
    RingNode* current = head;
    RingNode* nextNode = nullptr;

    do {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != head);

    head = nullptr;
    size = 0;
}
//Проверка на пустоту
bool RingList::isEmpty() const {
    return size == 0;
}
//Получение размера
int RingList::getSize() const {
    return size;
}
//Добавить в конец
void RingList::addDigit(char digit) {
    RingNode* newNode = new RingNode(digit);

    if (head == nullptr) {
        head = newNode;
        head->next = head;
    }
    else {
        RingNode* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = head;
    }
    size++;
}
//Получение цифры индекса 
char RingList::getDigit(int index) const {
    RingNode* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->digit;
}
//Преобразование в строку
std::string RingList::toString() const {
    if (isEmpty()) return "";

    std::string result;
    RingNode* current = head;
    for (int i = 0; i < size; i++) {
        result += current->digit;
        current = current->next;
    }
    return result;
}
//Извлечение последовательностей цифр из списка
std::string RingList::extractSubring(int start, int length) const {
    if (length <= 0 || start < 0 || start >= size) {
        return "";
    }

    std::string result;
    for (int i = 0; i < length; i++) {
        int pos = (start + i) % size;
        result += getDigit(pos);
    }
    return result;
}
//Проверка  совпадает ли вся последовательность кольца с переданной строкой
bool RingList::isSameSequence(const std::string& seq, int startPos) const {
    if ((int)seq.length() != size) return false;

    for (int i = 0; i < size; i++) {
        int pos = (startPos + i) % size;
        if (getDigit(pos) != seq[i]) return false;
    }
    return true;
}
//Копирование списка
void RingList::copyFrom(const RingList& other) {
    if (other.isEmpty()) return;

    RingNode* current = other.head;
    for (int i = 0; i < other.size; i++) {
        addDigit(current->digit);
        current = current->next;
    }
}