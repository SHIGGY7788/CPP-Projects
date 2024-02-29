#include <iostream>
#include <chrono>
#include <thread>
#include <bits/stdc++.h>


//i love gambling!
int chance = rand() % 100;

int beg() {
    srand((unsigned int)time(NULL));
    std::cout << "How do you want to beg?\n";
    std::cout << "1. On a street corner\n";
    std::cout << "2. Grandparents\n";
    std::cout << "3. Parents\n";
    std::cout << "4. Friends\n";
    std::cout << "5. Russian Roulette\n";
    int choice;

    std::cin >> choice;

    switch (choice) {
        case 1:
            if (chance > 75 && chance < 90)
            {
                std::cout << "Woohoo! We got $10!\n";
                return 10;
            } else if (chance > 90) {
                std::cout << "You got hit by a car D:\n";
                std::cout << "Your in the hospital\n";
                std::cout << "You need a loan to pay the medical bills\n";
                std::cout << "Except your poor\n";
                std::cout << "Do you take out a loan? (y/n)\n";
                std::string choice3;
                std::cin >> choice3;
                if (choice3 == "y") {
                    std::cout << "You took out a loan of $1000\n";
                    std::cout << "Do you gamble the loan? (y/n)\n";
                    std::string choice4;
                    std::cin >> choice4;
                    if (choice4 == "y") {
                        return 1000;
                    } else {
                        std::cout << "99% of gamblers quit before hitting big, were not stopasdping yet\n";
                        return 1000;
                    }
                } else {
                    std::cout << "You died in the hospital, RIP\n";
                    std::terminate();
                }
            } else {
                std::cout << "No one gave us money :(\n";
            }
        case 2:
            if (rand() % 100 > 70) {
                std::cout << "You got $20 from your grandparents!\n";
                return 20;
            } else {
                std::cout << "No money from your grandparents :(\n";
            }

        case 3:
            if (rand() % 100 > 80) {
                std::cout << "You got $15 from your parents!\n";
                return 15;
            } else {
                std::cout << "No money from your parents :(\n";
            }
        case 4:
            if (rand() % 100 > 50) {
                std::cout << "no friend lol!\n";
            } else {
                std::cout << "your friends are poor, no moeny\n";
            }
        case 5:
            std::cout << "you go literally all in\n";
            //sleep to simulate gambling
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << "you meet with the russian mob\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            if (rand() % 100 < 50) {
                std::cout << "you died lol\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                std::terminate();
            } else {
                std::cout << "holy moly your a gazillionair +10000000000";
                return 1000000000;
            }

        default:
            std::cout << "Do you want to beg again? (y/n)\n";
            std::string choice2;
            std::cin >> choice2;
            if (choice2 == "y") {
                return beg();
            } else {
                return 0;
            }
    }
}