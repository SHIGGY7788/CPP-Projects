#include <iostream>
#include "user.cpp"
#include "main.h"

//i love gambling!

//global variable for the user
constexpr int startbal = 100;
std::string regname;
std::string regpass;
User user(regname, regpass, startbal);

int choice;

void options(int choice) {
    switch (choice) {
        case 1:
            std::cout << "Bye!";
        std::terminate();
        case 2:
            int gamechoice;
        std::cout << "What game would you like to play?\n";
        std::cout << "1. Slots\n";
        std::cout << "2. Roulette\n";
        std::cout << "3. Blackjack\n";
        std::cin >> gamechoice;

        switch (gamechoice) {
            case 1:
                std::cout << "You have chosen slots!\n";
                play_slots(user.getBalance());
                break;
            case 2:
                std::cout << "You have chosen roulette!\n";
                play_roulette(user.getBalance());
                break;
            case 3:
                std::cout << "You have chosen blackjack!\n";
                play_blackjack(user.getBalance());
                break;
            default:
                std::cout << "Invalid choice!";
                options(choice);
        }
        case 3:
            std::cout << "You have " << user.getBalance() << " dollars.\n";
        default:
            std::cout << "Invalid choice!";

    }
}

int main() {
    std::cout << "Endter your username: ";
    std::cin >> regname;
    std::cout << "Enter your password: ";
    std::cin >> regpass;

    User user(regname, regpass, startbal);

    std::cout << "\n";
    std::cout << "Welcome to the casino, " << user.getUsername() << "\n";
    std::cout << "You have " << user.getBalance() << " dollars.\n";

    std::cout << "What would you like to do?\n";
    std::cout << "1. Exit\n";
    std::cout << "2. Play a game\n";
    std::cout << "3. Check balance\n";
    int choice;

    std::cin >> choice;

    options(choice);
};

