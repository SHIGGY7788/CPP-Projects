#include <iostream>
#include <string>
#include <utility>

// Class to represent the user, which can have a username, password, balance
class User {
    std::string username;
    std::string password;
    int balance;
public:
    User(std::string username, std::string password, int balance) {
        this->username = std::move(username);
        this->password = std::move(password);
        this->balance = balance;
    }
    std::string getUsername() {
        return username;
    }
    std::string getPassword() {
        return password;
    }
    int getBalance() {
        return balance;
    }
    void setBalance(int newBalance) {
        balance = newBalance;
    }
};

