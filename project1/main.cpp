#include <iostream>
#include "user.cpp"
#include "main.h"

//i love gambling!
int x;
int mainoption;

std::string regname;
int startBal = 100;
User user(regname, startBal);


void play_games() {
    std::cout << "What would you like to do?\n";
    std::cout << "1. Slots\n";
    std::cout << "2. Roulette\n";
    std::cout << "3. Blackjack\n";
    std::cout << "4. Horse Races\n";


    std::cin >> mainoption;

    options(mainoption);
}

int main() {
    std::cout << "Endter your username: ";
    std::cin >> regname;

    user.setUsername(regname);

    std::cout << "\n";
    std::cout << "Welcome to the casino, " << user.getUsername() << "\n";
    std::cout << "You have " << user.getBalance() << " dollars.\n";

    play_games();
};




void options(int choice) {
    switch(choice) {
        case 1:
            x = play_slots(user.getBalance());
            std::cout << "slots finished with " << x << "\n";
            user.setBalance(x);
            mainoption = 0;
            play_games();
            break;
        case 2:
            x = play_roulette(user.getBalance());
            std::cout << "roulette finished with " << x << "\n";
            user.setBalance(x);
            mainoption = 0;
            play_games();
            break;
        case 3:
            x = play_blackjack(user.getBalance());
            std::cout << "blackjack finished with " << x << "\n";
            user.setBalance(x);
            mainoption = 0;
            play_games();
            break;
        case 4:
            x = play_horsebetting(user.getBalance());
            std::cout << "horsebetting finished with " << x << "\n";
            user.setBalance(x);
            mainoption = 0;
            play_games();
            break;
        default:
            std::cout << "Invalid option\n";
            break;
    }
}

