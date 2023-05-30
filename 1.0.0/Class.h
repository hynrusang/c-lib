/*
this source code is a source code that implements C++ class as much as possible.
When you use it, this header file will include.

#include "Class.h href"

and, you can try it:

Bank: Class create

class (Bank) {
    int money;
    int f(balance);
    int f(withdraw);
    void f(deposit);
};

def (Bank, balance) {
    return this->money;
}

def (Bank, withdraw, int money) {
    if (this->money - money < 0) printf("\n\tcannnot withdraw %d$\n", money);
    else {
        printf("\n\t%d$ was withdraw\n", money);
        this->money -= money;
    }
}

def (Bank, deposit, int money) {
    this->money += money;
    printf("\n\t%d$ has been deposited.\n", money);
}

constructor (Bank, int money) {
#define bind() Bank
    def_this;
    this(balance);
    this(withdraw);
    this(deposit);
    this->money = money;
}

Bank: Class used

int main() {
    printf("*****\t    Bank\t*****\n");
    Bank* mybank = new (Bank, 20);

    printf("\n\tbalance: %d$\n", mybank->balance(mybank));
    mybank->deposit(mybank, 30);
    printf("\n\tbalance: %d$\n", mybank->balance(mybank));
    mybank->withdraw(mybank, 40);
    printf("\n\tbalance: %d$\n", mybank->balance(mybank));
    mybank->withdraw(mybank, 40);
    printf("\n\tbalance: %d$\n", mybank->balance(mybank));

    printf("\n***** Bank scenario end *****\n\n");
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
#define def(_class_type, _method, ...) void _class_type##_##_method(_class_type* this, __VA_ARGS__)

// definition class's constructor, this, and so on

#define constructor(_class_type, ...) _class_type* init_##_class_type(__VA_ARGS__)
#define def_this bind()* this = malloc(sizeof(bind())); if (this == NULL) exit(1)
#define this(_method) this->_method = bind()##_##_method
#define super(_class_type, _method) this->_method = _class_type##_##_method

// definition new operator

#define new(_class_type, ...) init_##_class_type(__VA_ARGS__)
#include <stdlib.h>

#endif
