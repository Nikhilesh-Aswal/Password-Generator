#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

std::string generate_password(int length, std::string complexity) {
    std::string characters;

    if (complexity == "easy") {
        characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    } else if (complexity == "medium") {
        characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    } else if (complexity == "hard") {
        characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{}|;:'\",.<>/?";
    } else {
        std::cout << "Invalid complexity level. Please choose 'easy', 'medium', or 'hard'.\n";
        return "";
    }

    std::string password;
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < length; ++i) {
        password += characters[rand() % characters.length()];
    }

    return password;
}

int main() {
    std::cout << "Random Password Generator\n";

    try {
        int length;
        std::string complexity;

        std::cout << "Enter the desired password length: ";
        std::cin >> length;

        std::cout << "Enter the desired complexity level ('easy', 'medium', or 'hard'): ";
        std::cin >> complexity;

        std::string password = generate_password(length, complexity);

        if (!password.empty()) {
            std::cout << "Generated Password: " << password << "\n";
        }
    } catch (...) {
        std::cout << "Invalid input. Please enter a valid number for password length.\n";
    }

    return 0;
}