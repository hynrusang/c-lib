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
    this->money += money;
}
constructor(Bank)
    link(Bank, balance);
    link(Bank, deposit);
    this->money = 0;
end

int main() {
    Bank* mybank = new (Bank);
    mybank->balance(mybank);
    mybank->deposit(mybank, 100);
    mybank->balance(mybank);
    free(mybank);
    return 0;
}