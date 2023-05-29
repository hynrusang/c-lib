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

// definition class, method, class::method

#define class(_class_type) typedef struct _class_type _class_type; struct _class_type
#define f(_method) (*_method)()
#define def(_method, _class_type, ...) void _class_type##_##_method(_class_type* this, __VA_ARGS__)

// definition class's constructor, this, and so on

#define constructor(_class_type, ...) _class_type* init_##_class_type(__VA_ARGS__)
#define init macro()* this = malloc(sizeof(macro())); if (this == NULL) exit(1)
#define link(_method) this->_method = macro()##_##_method

// definition new operator

#define new(_class_type, ...) init_##_class_type(__VA_ARGS__)

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#endif
