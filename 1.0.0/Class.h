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
#define this(_class_type) _class_type* this = malloc(sizeof(_class_type)); if (this == NULL) exit(1);

#define link_1(_class_type, _1) this->_1 = _class_type##_##_1
#define link_2(_class_type, _1, _2) this->_1 = _class_type##_##_1;\
    this->_2 = _class_type##_##_2
#define link_3(_class_type, _1, _2, _3) this->_1 = _class_type##_##_1;\
    this->_2 = _class_type##_##_2;\
    this->_3 = _class_type##_##_3
#define link_4(_class_type, _1, _2, _3, _4) this->_1 = _class_type##_##_1;\
    this->_2 = _class_type##_##_2;\
    this->_3 = _class_type##_##_3;\
    this->_4 = _class_type##_##_4
#define link_5(_class_type, _1, _2, _3, _4, _5, _6) this->_1 = _class_type##_##_1;\
    this->_2 = _class_type##_##_2;\
    this->_3 = _class_type##_##_3;\
    this->_4 = _class_type##_##_4;\
    this->_5 = _class_type##_##_5
#define link_6(_class_type, _1, _2, _3, _4, _5, _6, _7) this->_1 = _class_type##_##_1;\
    this->_2 = _class_type##_##_2;\
    this->_3 = _class_type##_##_3;\
    this->_4 = _class_type##_##_4;\
    this->_5 = _class_type##_##_5;\
    this->_6 = _class_type##_##_6
#define link_7(_class_type, _1, _2, _3, _4, _5, _6, _7) this->_1 = _class_type##_##_1;\
    this->_2 = _class_type##_##_2;\
    this->_3 = _class_type##_##_3;\
    this->_4 = _class_type##_##_4;\
    this->_5 = _class_type##_##_5;\
    this->_6 = _class_type##_##_6;\
    this->_7 = _class_type##_##_7
#define link_8(_class_type, _1, _2, _3, _4, _5, _6, _7, _8) this->_1 = _class_type##_##_1;\
    this->_2 = _class_type##_##_2;\
    this->_3 = _class_type##_##_3;\
    this->_4 = _class_type##_##_4;\
    this->_5 = _class_type##_##_5;\
    this->_6 = _class_type##_##_6;\
    this->_7 = _class_type##_##_7;\
    this->_8 = _class_type##_##_8
#define link_9(_class_type, _1, _2, _3, _4, _5, _6, _7) this->_1 = _class_type##_##_1;\
    this->_2 = _class_type##_##_2;\
    this->_3 = _class_type##_##_3;\
    this->_4 = _class_type##_##_4;\
    this->_5 = _class_type##_##_5;\
    this->_6 = _class_type##_##_6;\
    this->_7 = _class_type##_##_7;\
    this->_8 = _class_type##_##_8
#define link_10(_class_type, _1, _2, _3, _4, _5, _6, _7) this->_1 = _class_type##_##_1;\
    this->_2 = _class_type##_##_2;\
    this->_3 = _class_type##_##_3;\
    this->_4 = _class_type##_##_4;\
    this->_5 = _class_type##_##_5;\
    this->_6 = _class_type##_##_6;\
    this->_7 = _class_type##_##_7;\
    this->_8 = _class_type##_##_8

// definition new operator

#define new(_class_type, ...) init_##_class_type(__VA_ARGS__)

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#endif
