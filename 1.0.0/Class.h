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
#include <stdlib.h>

#define class(name) typedef struct name name; struct name
#define f(_class_name) (*_class_name)()
#define link(_class_type, _method) this->_method = _class_type##_##_method
#define constructor(_class_type, ...) _class_type* init_##_class_type(__VA_ARGS__) { _class_type* this = malloc(sizeof(_class_type)); if (this == NULL) exit(1);
#define new(_class_type, ...) init_##_class_type(__VA_ARGS__)
#endif
