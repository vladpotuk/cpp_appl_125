#include <iostream>
#include <string>

class OutOfRangeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Значення виходить за межі допустимого діапазону int";
    }
};

class InvalidArgumentException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Рядок містить недопустимі символи";
    }
};

int parseToInt(const std::string& str) {
    try {
        size_t pos;
        int result = std::stoi(str, &pos); 

        if (pos < str.size()) {
            throw InvalidArgumentException();
        }

        return result;
    }
    catch (const std::out_of_range& e) {
        throw OutOfRangeException();
    }
    catch (const std::invalid_argument& e) {
        throw InvalidArgumentException();
    }
}

int main() {
    system("chcp 1251");
    system("cls");
    std::string input;
    std::cout << "Введіть рядок для конвертації в int: ";
    std::cin >> input;

    try {
        int result = parseToInt(input);
        std::cout << "Результат конвертації: " << result << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}
