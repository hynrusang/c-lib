#include "Class.h"

// class Bank { ... } in c

#define class(name) typedef struct name name; struct name
#define def(_method, _class_type, ...) void _class_type##_##_method(_class_type* this, __VA_ARGS__)
#define f(_class_name) (*_class_name)()
#define this(_class_type) _class_type* this = malloc(sizeof(_class_type)); if (this == NULL) exit(1);

#define link_1(_class_type, _1) this->_1 = _class_type##_##_1
#define link_2(_class_type, _1, _2) this->_1 = _class_type##_##_1; this->_2 = _class_type##_##_2
#define link_3(_class_type, _1, _2, _3) this->_1 = _class_type##_##_1; this->_2 = _class_type##_##_2; this->_3 = _class_type##_##_3

#define constructor(_class_type, ...) _class_type* init_##_class_type(__VA_ARGS__)
#define new(_class_type, ...) init_##_class_type(__VA_ARGS__)

class (Bank) {
    int money;
    int f(balance);
    int f(withdraw);
    void f(deposit);
};

def (balance, Bank) {
    return this->money;
}

def (withdraw, Bank, int money) {
    if (this->money - money < 0) printf("\ncannnot withdraw %d$\n", money);
    else {
        printf("\n%d$ was withdraw\n", money);
        this->money -= money;
    }
}

def (deposit, Bank, int money) {
    this->money += money;
    printf("\n%d$ has been deposited.\n", money);
}

constructor(Bank, int money) {
    this(Bank);
    link_3(Bank, balance, withdraw, deposit);
    this->money = money;
}

// class BankExtend : Bank { ... } in c

int main() {
    printf("***** Bank *****\n");
    Bank* mybank = new (Bank, 20); // c++: Bank* mybank = new Bank(20);

    printf("\nbalance: %d$\n", mybank->balance(mybank));
    mybank->deposit(mybank, 30);
    printf("\nbalance: %d$\n", mybank->balance(mybank));
    mybank->withdraw(mybank, 40);
    printf("\nbalance: %d$\n", mybank->balance(mybank));
    mybank->withdraw(mybank, 40);
    printf("\nbalance: %d$\n", mybank->balance(mybank));
    return 0;
}
