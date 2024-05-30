#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype> 

int main() {
    std::string userName;
    std::cout << "Введите ваше имя: ";
    std::getline(std::cin, userName);
    std::cout << "Привет, " << userName << "!\n";
    std::cout << "Это программа для подсчета статистики символов в тексте.\n";

    int choice;
    std::string input;
    std::map<unsigned char, int> charCount;

    do {
        std::cout << "\nВыберите действие:\n";
        std::cout << "1) Ввести текст\n";
        std::cout << "2) Указать путь к файлу\n";
        std::cout << "3) Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        std::cin.ignore(); 

        switch (choice) {
            case 1:
                std::cout << "Введите текст: ";
                std::getline(std::cin, input);
                break;
            case 2:
                std::cout << "Укажите путь к файлу: ";
                std::getline(std::cin, input);
                break;
            case 3:
                std::cout << "Выход из программы.\n";
                return 0;
            default:
                std::cout << "Неверный выбор, попробуйте еще раз.\n";
                continue;
        }

        if (choice == 2 && input.find(".txt") == std::string::npos) {
            std::cout << "Неправильный формат файла. Поддерживается только .txt\n";
            continue;
        }

        if (choice == 2) {
            std::ifstream file(input, std::ios::binary);
            if (!file.is_open()) {
                std::cerr << "Не удалось открыть файл.\n";
                continue;
            }
            unsigned char ch;
            while (file >> std::noskipws >> ch) {
                charCount[ch]++;
            }
        } else {
            for_each(input.begin(), input.end(), [&](unsigned char c) { charCount[c]++; });
        }

        int letterCount = 0, wordCount = 0, spaceCount = 0, punctuationCount = 0, digitCount = 0;
        for (const auto& pair : charCount) {
            if (std::isalpha(pair.first)) {
                letterCount += pair.second;
            } else if (std::isspace(pair.first)) {
                spaceCount += pair.second;
            } else if (std::isdigit(pair.first)) {
                digitCount += pair.second;
            } else if (std::ispunct(pair.first)) {
                punctuationCount += pair.second;
            }
        }
        wordCount = std::count_if(input.begin(), input.end(), [](unsigned char c) { return std::isspace(c); }) + 1;
        int otherCount = input.size() - (letterCount + spaceCount + punctuationCount + digitCount);

        std::cout << "\nСтатистика символов:\n";
        std::cout << "1) Количество букв: " << letterCount << std::endl;
        std::cout << "2) Количество слов: " << wordCount << std::endl;
        std::cout << "3) Количество пробелов: " << spaceCount << std::endl;
        std::cout << "4) Количество знаков препинания: " << punctuationCount << std::endl;
        std::cout << "5) Количество цифр: " << digitCount << std::endl;
        std::cout << "6) Другие символы: " << otherCount << std::endl;
        std::cout << "7) Общее количество символов в тексте: " << input.size() << std::endl;

    } while (true);

    return 0;
}