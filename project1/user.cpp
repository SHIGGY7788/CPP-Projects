#include <iostream>
#include <string>
#include <utility>


class User {
    std::string username;
    int balance;
public:
    User(std::string username, int balance) {
        this->username = std::move(username);
        this->balance = balance;
    }
    std::string getUsername() {
        return username;
    }
    void setUsername(std::string newUsername) {
        username = std::move(newUsername);
    }
    int getBalance() {
        return balance;
    }
    void setBalance(int newBalance) {
        balance = newBalance;
    }
    void addBalance(int newBal) {
        balance += newBal;
    }

};

