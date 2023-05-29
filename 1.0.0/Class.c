#include "Class.h"

// class Bank { ... } in c

class (Bank) {
    int money;
    int f(balance);
    int f(withdraw);
    void f(deposit);
};

def (balance, Bank) {
    return this->money;
}

def (withdraw, Bank, int money) {
#define macro() money
    if (this->money - money < 0) printf("\ncannnot withdraw %d$\n", money);
    else {
        printf("\n%d$ was withdraw\n", money);
        this->money -= macro();
    }
}

def (deposit, Bank, int money) {
    this->money += money;
    printf("\n%d$ has been deposited.\n", money);
}
constructor (Bank, int money) {
#define macro() Bank
    init;
    link(balance);
    link(withdraw);
    link(deposit);
    this->money = money;
}

// class BankExtend : Bank { ... } in c

int main() {
    printf("***** Bank *****\n");
    Bank* mybank = new (Bank, 20); // c++: Bank* mybank = new Bank(20);

    printf("\nbalance: %d$\n", mybank->balance(mybank));
    mybank->deposit(mybank, 30);
    printf("\nbalance: %d$\n", mybank->balance(mybank));
    mybank->withdraw(mybank, 40);
    printf("\nbalance: %d$\n", mybank->balance(mybank));
    mybank->withdraw(mybank, 40);
    printf("\nbalance: %d$\n", mybank->balance(mybank));

    printf("***** Bank *****\n");
    return 0;
}
