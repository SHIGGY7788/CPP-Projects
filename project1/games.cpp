//Casino games
#include <iostream>
#include "main.h"
#include <chrono>
#include <random>
#include <thread>
#include <bits/stdc++.h>
#include <ctime>
#include <numeric>


int play_horsebetting(int balance) {
    srand(time(0));
    std::cout << "Welcome to the slots!\n";
    std::cout << "You have " << balance << " dollars.\n";

    if (balance == 0) {
        std::cout << "You're poor lol\n";
        std::cout << "Do you want to beg?(y/n)\n";
        std::string begChoice;
        std::cin >> begChoice;
        if (begChoice == "y") {
            balance += beg();
        }
    }
    std::cout << "How much would you like to bet?\n";
    int bet;
    std::cin >> bet;
    if (bet > balance) {
        std::cout << "You're too poor!\n";
        return balance;
    }

    balance -= bet;

    std::array<std::string, 21> horseNames = {
        "Thunderbolt",
        "Lightning Strike",
        "Midnight Shadow",
        "Golden Gallop",
        "Silver Streak",
        "Velvet Dreamer",
        "Firefly Blaze",
        "Moonbeam Rider",
        "Starry Night",
        "Whispering Wind",
        "Wildfire",
        "Shadow Dancer",
        "Dreamcatcher",
        "Sunburst Sprinter",
        "Mystic Mirage",
        "Rolling Thunder",
        "Aurora Borealis",
        "Meadow Majesty",
        "Swift Spirit",
        "Dream Weaver",
        "Tripod"
    };

    // Shuffle the horseNames array
    std::shuffle(horseNames.begin(), horseNames.end(), std::mt19937(std::random_device()()));

    // Get the first five random horses
    std::array<std::string, 5> selectedHorses;
    std::copy(horseNames.begin(), horseNames.begin() + 5, selectedHorses.begin());

    // Print the selected horses

    std::cout << "Horses racing today:\n";
    for (const auto& horse : selectedHorses) {
        std::cout << horse << std::endl;
    }

    // Get the user's horse choice
    std::string userHorse;
    std::cout << "Which horse would you like to bet on?\n";
    std::cin >> userHorse;

    // text to simulate horses racing
    std::cout << "The horses are off!\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "The horses are rounding the first turn!\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "The horses are rounding the final turn!\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "The horses are coming down the final stretch!\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "And the winner is...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    const std::string winner = selectedHorses[rand() % 5];
    std::cout << winner << "!\n";


    // if the user's horse wins
    if (userHorse == winner) {
        std::cout << "You win " << bet * 5 << " dollars!\n";
        balance += bet * 5;
    } else {
        std::cout << "You lose!\n";
    }




}



int play_slots(int balance) {
    srand(time(0));
    std::cout << "Welcome to the slots!\n";
    std::cout << "You have " << balance << " dollars.\n";

    if (balance == 0) {
        std::cout << "You're poor lol\n";
        std::cout << "Do you want to beg?(y/n)\n";
        std::string begChoice;
        std::cin >> begChoice;
        if (begChoice == "y") {
            balance += beg();
        }
    }
    std::cout << "How much would you like to bet?\n";
    int bet;
    std::cin >> bet;
    if (bet > balance) {
        std::cout << "You're too poor!\n";
        return balance;
    }

    balance -= bet;
    const int slot1 = rand() % 10;
    const int slot2 = rand() % 10;
    const int slot3 = rand() % 10;
    std::cout << "The slots are spinning...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << slot1 << " " << slot2 << " " << slot3 << "\n";
    if (slot1 == slot2 && slot2 == slot3) {
        std::cout << "jackpot! You win " << bet * 10 << " dollars!\n";
        balance += bet * 10;
    } else if (slot1 == slot2 || slot2 == slot3 || slot1 == slot3) {
        std::cout << "You win " << bet * 5 << " dollars!\n";
        balance += bet * 5;
    } else {
        std::cout << "You lose!\n";
    }
    std::string playAgain;
    std::cout << "Would you like to play again? (y/n)\n";
    std::cin >> playAgain;
    if (playAgain == "y") {
        if (balance == 0) {
            std::cout << "You're poor lol\n";
            std::cout << "Do you want to beg?(y/n)\n";
            std::string begChoice;
            std::cin >> begChoice;
            if (begChoice == "y") {
                balance += beg();
            }
        }
        return play_slots(balance);
    } else {
        return balance;
    }

}

int play_roulette(int balance) {
    srand(time(0));
    std::cout << "Welcome to the roulette table!\n";
    std::cout << "You have " << balance << " dollars.\n";

    if (balance == 0) {
        std::cout << "You're poor lol\n";
        std::cout << "Do you want to beg?(y/n)\n";
        std::string begChoice;
        std::cin >> begChoice;
        if (begChoice == "y") {
            balance += beg();
        }
    }
    int bet;


    std::vector<int> red{1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
    std::vector<int> black{2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};
    int green_nums[] = {0, 00};
    std::cout << "What would you like to bet on?\n";
    std::cout << "1. A number\n";
    std::cout << "2. Red\n";
    std::cout << "3. Black\n";
    std::cout << "4. Green\n";
    int choice;
    std::cin >> choice;
    std::cout << "How much would you like to bet?\n";
    std::cin >> bet;
    if (bet > balance) {
        std::cout << "You're too poor!\n";
        return balance;
    }
    balance -= bet;
    int spin = rand() % 37;

    switch (choice) {
        case 1:
            std::cout << "What number do you want to bet on?\n";
            int number;
            std::cin >> number;
            std::cout << "The wheel is spinning...\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << "The ball landed on " << spin << "!\n";
            if (spin == number) {
                std::cout << "You win " << bet * 35 << " dollars!\n";
                balance += bet * 35;
            } else {
                std::cout << "You lose!\n";
            }

        break;
        case 2:
            std::cout << "The wheel is spinning...\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << "The ball landed on " << spin << "!\n";

            if (std::find(red.begin(), red.end(), spin) != red.end()) {
                std::cout << "You win " << bet * 2 << " dollars!\n";
                balance += bet * 2;
            } else {
                std::cout << "You lose!\n";
            }
        break;
        case 3:
            std::cout << "The wheel is spinning...\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << "The ball landed on " << spin << "!\n";
            if (std::find(std::begin(black), std::end(black), spin) != std::end(black)) {
                std::cout << "You win " << bet * 2 << " dollars!\n";
                balance += bet * 2;
            } else {
                std::cout << "You lose!\n";
            }
        break;
        case 4:
            std::cout << "The wheel is spinning...\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << "The ball landed on " << spin << "!\n";
            if (spin == green_nums[0] || spin == green_nums[1]) {
                std::cout << "BIGGG WINNN !!!!!\n";
                std::cout << "You win " << bet * 17 << " dollars!\n";
                balance += bet * 35;
            } else {
                std::cout << "You lose!\n";
            }
    }
    std::string playAgain;
    std::cout << "Would you like to play again? (y/n)\n";
    std::cin >> playAgain;
    if (playAgain == "y") {
        if (balance == 0) {
            std::cout << "You're poor lol\n";
            std::cout << "Do you want to beg?(y/n)\n";
            std::string begChoice;
            std::cin >> begChoice;
            if (begChoice == "y") {
                balance += beg();
            }
        }
        return play_roulette(balance);
    } else {
        return balance;
    }
}


int play_blackjack(int balance) {
    srand(time(0));
    int dealerhand;
    int playerhand;
    std::cout << "Welcome to the blackjack table!\n";
    std::cout << "You have " << balance << " dollars.\n";

    if (balance == 0) {
        std::cout << "You're poor lol\n";
        std::cout << "Do you want to beg?(y/n)\n";
        std::string begChoice;
        std::cin >> begChoice;
        if (begChoice == "y") {
            balance += beg();
        }
    }
    std::cout << "How much would you like to bet?\n";
    int bet;
    std::cin >> bet;
    if (bet > balance) {
        std::cout << "You're too poor!\n";
        return balance;
    }

    balance -= bet;
    std::vector<int> num_cards{2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> face_cards{10, 10, 10, 10};
    int ace[] = {1, 11};

    //chance of pulling card types
    int face_card_chance = 23;
    int num_card_chance = 77;
    int ace_chance = 7;

    std::cout << "Dealing cards...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    int playercards[5]; //player cards
    int dealercards[5]; //dealer cards

    //player first card
    if (rand() % 100 < face_card_chance) {
        playercards[0] = face_cards[rand() % 4];
    } else if (rand() % 100 < num_card_chance) {
        playercards[0] = num_cards[rand() % 9];
    } else {
        playercards[0] = ace[rand() % 2];
    }

    //dealer first card
    if (rand() % 100 < face_card_chance) {
        dealercards[0] = face_cards[rand() % 4];
    } else if (rand() % 100 < num_card_chance) {
        dealercards[0] = num_cards[rand() % 9];
    } else {
        dealercards[0] = ace[rand() % 2];
    }

    //player second card
    if (rand() % 100 < face_card_chance) {
        playercards[1] = face_cards[rand() % 4];
    } else if (rand() % 100 < num_card_chance) {
        playercards[1] = num_cards[rand() % 9];
    } else {
        playercards[1] = ace[rand() % 2];
    }

    //Dealer second card
    if (rand() % 100 < face_card_chance) {
        dealercards[2] = face_cards[rand() % 4];
    } else if (rand() % 100 < num_card_chance) {
        dealercards[2] = num_cards[rand() % 9];
    } else {
        dealercards[2] = ace[rand() % 2];
    }

    playerhand = 0;
    for (auto& num : playercards)
        playerhand += num;
    dealerhand = 0;
    for (auto& num : dealercards)
        dealerhand += num;

    std::cout << "You have a " << playercards[0] << " and a " << playercards[1] << " for a total of " << playerhand << "\n";
    std::cout << "The dealer has a " << dealercards[0] << " showing, and a hidden card.\n";

    int play_choice = 0;
    bool busted = false;
    bool playing = true;


    while (playing) {
        play_choice = 0;
        std::cout << "Would you like to hit or stand? (1,2)\n";
        std::cin >> play_choice;
        switch(play_choice) {
            case 1:
                std::cout << "You chose to hit!\n";
            // Get random card and add to player hand
            if (rand() % 100 < face_card_chance) {
                playercards[2] = face_cards[rand() % 4];
            } else if (rand() % 100 < num_card_chance) {
                playercards[2] = num_cards[rand() % 9];
            } else {
                playercards[2] = ace[rand() % 2];
            }
            playerhand = 0;
            for (auto& num : playercards)
                playerhand += num;
            std::cout << "You drew a " << playercards[2] << " for a total of " << playerhand << "\n";
            if (playerhand > 21) {
                std::cout << "You busted! You lose.\n";
                playing = false;
                return balance;
            } else {
                break;
            }
            case 2:
                std::cout << "You chose to stand!\n";
            if (dealerhand < 17) {
                std::cout << "The dealer hits...\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                if (rand() % 100 < face_card_chance) {
                    dealercards[2] = face_cards[rand() % 4];
                } else if (rand() % 100 < num_card_chance) {
                    dealercards[2] = num_cards[rand() % 9];
                } else {
                    dealercards[2] = ace[rand() % 2];
                }
                dealerhand = 0;
                for (auto& num : dealercards)
                    dealerhand += num;
                std::cout << "The dealer drew a " << dealercards[2] << " for a total of " << dealerhand << "\n";
                if (dealerhand < 17) {
                    std::cout << "The dealer hits again...\n";
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    if (rand() % 100 < face_card_chance) {
                        dealercards[3] = face_cards[rand() % 4];
                    } else if (rand() % 100 < num_card_chance) {
                        dealercards[3] = num_cards[rand() % 9];
                    } else {
                        dealercards[3] = ace[rand() % 2];
                    }
                    dealerhand = 0;
                    for (auto& num : dealercards)
                        dealerhand += num;
                    std::cout << "The dealer drew a " << dealercards[3] << " for a total of " << dealerhand << "\n";
                }
                if (dealerhand > 21) {
                    std::cout << "The dealer busted! You win!\n";
                    balance += bet * 2;
                    playing = false;
                    return balance;
                }
                if (playerhand > dealerhand) {
                    std::cout << "You win!\n";
                    balance += bet * 2;
                    playing = false;
                    return balance;
                } else if (playerhand == dealerhand) {
                    std::cout << "You push.\n";
                    balance += bet;
                    playing = false;
                    return balance;
                } else {
                    std::cout << "You lose.\n";
                    playing = false;
                    return balance;
                }
            }
            break;
            default:
                std::cout << "invalid operatnino\n";
                break;

        }
        std::string playAgain;
        std::cout << "Would you like to play again? (y/n)\n";
        std::cin >> playAgain;
        if (playAgain == "y") {
            if (balance == 0) {
                std::cout << "You're poor lol\n";
                std::cout << "Do you want to beg?(y/n)\n";
                std::string begChoice;
                std::cin >> begChoice;
                if (begChoice == "y") {
                    balance += beg();
                }
            }
            return play_blackjack(balance);
        } else {
            return balance;
        }
    }
}





    /* game end
    std::string playAgain;
    std::cout << "Would you like to play again? (y/n)\n";
    std::cin >> playAgain;
    if (playAgain == "y") {
        if (balance == 0) {
            std::cout << "You're poor lol\n";
            std::cout << "Do you want to beg?(y/n)\n";
            std::string begChoice;
            std::cin >> begChoice;
            if (begChoice == "y") {
                balance += beg();
            }
        }
        return play_roulette(balance);
    } else {
        return balance;
    }
    */