#include "Class.h"
class (Bank) {
    int money;
    method(balance);
    method(deposit);
};
void define(Bank, balance)(Bank* this) {
    printf("bank's balance: %d\n", this->money);
}
void define(Bank, deposit)(Bank* this, int money) {
    printf("***** deposit complate!***** \n");
    this->money += money;
}
constructor(Bank)
    link(Bank, balance);
    link(Bank, deposit);
    this->money = 0;
}

class(BankExtend) {
    int money;
    method(balance);
    method(deposit);
    method(withdraw);
};
int define(BankExtend, withdraw)(BankExtend* this, int money) {
    if (this->money - money < 0) {
        printf("The balance is insufficient.\n");
        exit(1);
    } else {
        this->money -= money;
        return money;
    }
}
constructor(BankExtend)
    link(Bank, balance);
    link(Bank, deposit);
    link(BankExtend, withdraw);
    this->money = 0;
}

int main() {
    printf("*****Bank*****\n\n");
    Bank* mybank = new (Bank);
    mybank->balance(mybank);
    mybank->deposit(mybank, 100);
    mybank->balance(mybank);
    free(mybank);
    printf("\n*****BankExtend : Bank*****\n");
    BankExtend* newbank = new (BankExtend);
    newbank->balance(newbank);
    newbank->deposit(newbank, 100);
    newbank->balance(newbank);
    return 0;
}