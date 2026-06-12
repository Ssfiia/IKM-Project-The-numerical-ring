#include "Header.h"
#include <algorithm>
//Конструктор
RingSolver::RingSolver(const RingList& ringList) : ring(ringList) {
    n = ring.getSize();
}
//Деконструктор
RingSolver::~RingSolver() {}
//Проверка является ли строка числом
bool RingSolver::isValidNumber(const std::string& num) const {
    if (num.empty()) return false;
    if (num.length() == 1) return true;
    return num[0] != '0';
}
//Поиск суммы чисел, являющихся строками
std::string RingSolver::addStrings(const std::string& a, const std::string& b) const {
    std::string result;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }

    std::reverse(result.begin(), result.end());
    return result;
}
//Перебор всех возможных вариантов троек A+B=C
std::string RingSolver::solve() {
    int maxLen = n / 2;
    //Перебор всех возможных стартовых позиций

    for (int startPos = 0; startPos < n; startPos++) {
        //перебор возможных длин для А и В
        for (int lenA = 1; lenA <= (maxLen < n - 2 ? maxLen : n - 2); lenA++) {
            if (lenA > maxLen) continue;
            for (int lenB = 1; lenB <= (maxLen < n - lenA - 1 ? maxLen : n - lenA - 1); lenB++) {
                if (lenB > maxLen) continue;
                int lenC = n - lenA - lenB;
                if (lenC < 1) continue;
                if (lenC > maxLen + 1) continue;
                //Извлечение чисел из списка
                std::string a = ring.extractSubring(startPos, lenA);
                std::string b = ring.extractSubring(startPos + lenA, lenB);
                std::string c = ring.extractSubring(startPos + lenA + lenB, lenC);
                //Проверка на число
                if (!isValidNumber(a) || !isValidNumber(b) || !isValidNumber(c)) {
                    continue;
                }
                //Подсчёт суммы
                std::string sum = addStrings(a, b);
                //Если сумма совпала с третьим извлечённым числом, то это решения
                if (sum == c && ring.isSameSequence(a + b + c, startPos)) {
                    return a + "+" + b + "=" + c;
                }
            }
        }
    }
//Ни один из варриантов перебора не подошёл
    return "No";
}