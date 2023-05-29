#include "Class.h"
class (Bank) {
    int money;
    void f(balance);
    void f(deposit);
};
void define(Bank, balance)(Bank* this) {
    printf("bank's balance: %d\n", this->money);
}
void define(Bank, deposit)(Bank* this, int money) {
    this->money += money;
}
constructor(Bank)
    link(Bank, balance);
    link(Bank, deposit);
    this->money = 0;
}

class(BankExtend) {
    int money;
    void f(balance);
    void f(deposit);
    int f(withdraw);
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
    printf("withdraw from newbank to %d$\n", newbank->withdraw(newbank, 50));
    newbank->balance(newbank);
    free(newbank);

    printf("\n*****all class example was ended*****\n");
    return 0;
}