#include "Class.h"
class (Bank) {
    int money;
    void f(balance);
    void f(deposit);
};
void Bank_balance(Bank* this) {
    printf("bank's balance: %d\n", this->money);
}
void Bank_deposit(Bank* this, int money) {
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
int BankExtend_withdraw(BankExtend* this, int money) {
    if (this->money - money < 0) return 0;
    else {
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
    printf("***** Bank *****\n\n");
    Bank* mybank = new (Bank);
    mybank->balance(mybank);
    mybank->deposit(mybank, 100);
    mybank->balance(mybank);

    printf("\n***** BankExtend : Bank *****\n\n");
    BankExtend* newbank = new (BankExtend);
    newbank->balance(newbank);
    newbank->deposit(newbank, 100);
    newbank->balance(newbank);
    newbank->withdraw(newbank, 50) ? printf("\nwithdraw from newbank to 50$\n\n") : printf("\ncannot withdraw 50$\n\n");
    newbank->balance(newbank);
    newbank->withdraw(newbank, 100) ? printf("\nwithdraw from newbank to 100$\n\n") : printf("\ncannot withdraw 100$\n\n");
    newbank->balance(newbank);

    printf("\n***** all class example was ended *****\n");
    free(mybank);
    free(newbank);
    return 0;
}