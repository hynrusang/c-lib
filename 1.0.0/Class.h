/*
this source code is a source code that implements C++ class as much as possible.
When you use it, this header file will include.

#include "Class.h href"

and, you can try it:

Bank: Class create

class (Bank) {
    int money;
    method(balance);
    method(deposit);
}
void define(Bank, balance)(Bank* this) {
    printf("bank's balance: %d\n", this->data);
}
void define(Bank, deposit)(Bank* this, int money) {
    this->data += money;
}
constructor(Bank)
    link(Bank, balance);
    link(Bank, deposit);
    this->data = 0;
end

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
#define new(_class_type) init_##_class_type()
#define constructor(_class_type) _class_type* init_##_class_type() { _class_type* this = malloc(sizeof(_class_type)); if (this == NULL) exit(1);
#define end }
#define method(_class_name) void (*_class_name)()
#define define(_class_type, _method) _class_type##_##_method
#define link(_class_type, _method) this->_method = define(_class_type, _method)
#endif