# Character Statistics Program

## Overview

The Character Statistics Program is a C++ application designed to analyze and count different types of characters in a text input. Users can either enter text directly or specify a file path to analyze the contents of a text file. The program provides a detailed breakdown of letters, words, spaces, punctuation, digits, and other characters in the input.

## Features

- **User Greeting:** The program greets the user by their name.
- **Text Input Options:** Users can choose to input text directly or provide the path to a .txt file.
- **Character Analysis:** The program counts and displays the number of letters, words, spaces, punctuation marks, digits, and other characters.
- **Error Handling:** The program handles invalid file paths and unsupported file formats gracefully.

## Usage
- **Run the Program:** Start the program by executing the compiled binary.
- **Enter User Name:** Input your name when prompted.
- **Choose an Option:** Select whether to enter text directly or provide a file path.
- **View Statistics:** After inputting the text or file path, view the character statistics.

## Example
```
Введите ваше имя: Иван
Привет, Иван!
Это программа для подсчета статистики символов в тексте.

Выберите действие:
1) Ввести текст
2) Указать путь к файлу
3) Выход
Ваш выбор: 1
Введите текст: Привет, мир! 123

Статистика символов:
1) Количество букв: 10
2) Количество слов: 2
3) Количество пробелов: 2
4) Количество знаков препинания: 2
5) Количество цифр: 3
6) Другие символы: 0
7) Общее количество символов в тексте: 17
```

## Code Explanation

**Main Program Flow**
- **User Input and Greeting:** The program starts by asking the user for their name and greeting them.
- **Main Menu: **Users are presented with options to enter text directly, specify a file path, or exit the program.
- **Text Input:** Based on the user's choice, the program either reads text input directly from the user or reads the contents of a specified .txt file.
- **Character Counting:** The program counts occurrences of different character types (letters, spaces, punctuation, digits, and others).
- **Display Statistics:** The program displays a detailed breakdown of the character counts.

**Key Functions**
- **Character Counting: **The program uses a std::map<unsigned char, int> to count occurrences of each character.
- **Input Handling: **The program uses std::getline to handle user input and file reading.
- **Validation:** The program checks for valid file paths and formats before attempting to read file contents.
- **Statistics Calculation: **The program calculates various statistics, including letter count, word count, space count, punctuation count, digit count, and other characters.
