/*
this source code is a source code that implements C++ class as much as possible.
When you use it, this header file will include.

#include "Class.h href"

and, you can try it:

Bank: Class create

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

Bank: Class used

int main() {
    Bank* mybank = new (Bank);
    mybank->balance(mybank);
    mybank->deposit(mybank, 100);
    mybank->balance(mybank);
    free(mybank);
    return 0;
}

Author: Hynrusang
*/
#ifndef CLASSHEADER
#define CLASSHEADER
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#endif
