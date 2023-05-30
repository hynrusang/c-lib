#include "Class.h"

// class Bank { ... } in c

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
#define macro() Bank
    def_this;
    this(balance);
    this(withdraw);
    this(deposit);
    this->money = money;
}

// class BankExtend : Bank { ... } in c

class (MinusBank) {
    int money;
    float debtp;
    int f(balance);
    int f(withdraw);
    void f(deposit);
};

def (MinusBank, withdraw, int money) {
    if (this->money - money < 0) {
        printf("\n\t%d$ was withdraw (the dept has been added %d$)\n", money, (int)(money * this->debtp / 100));
        this->money -= money * (1 + this->debtp / 100);
    }
    else {
        printf("\n\t%d$ was withdraw\n", money);
        this->money -= money;
    }
}
constructor(MinusBank, double money, double debtp) {
#define macro() MinusBank
    def_this;

    super(Bank, balance);
    super(Bank, deposit);
    this(withdraw);

    this->money = money;
    this->debtp = debtp;
}

int main() {
    printf("*****\t    Bank\t*****\n");
    Bank* mybank = new (Bank, 20); // c++: Bank* mybank = new Bank(20);

    printf("\n\tbalance: %d$\n", mybank->balance(mybank));
    mybank->deposit(mybank, 30);
    printf("\n\tbalance: %d$\n", mybank->balance(mybank));
    mybank->withdraw(mybank, 40);
    printf("\n\tbalance: %d$\n", mybank->balance(mybank));
    mybank->withdraw(mybank, 40);
    printf("\n\tbalance: %d$\n", mybank->balance(mybank));

    printf("\n***** Bank scenario end *****\n\n");
    free(mybank);

    printf("\n\n*****\t  MinusBank\t*****\n");
    MinusBank* myminusbank = new (MinusBank, 20, 10); // c++: Bank* mybank = new Bank(20);

    printf("\n\tbalance: %d$\n", myminusbank->balance(myminusbank));
    myminusbank->deposit(myminusbank, 30);
    printf("\n\tbalance: %d$\n", myminusbank->balance(myminusbank));
    myminusbank->withdraw(myminusbank, 40);
    printf("\n\tbalance: %d$\n", myminusbank->balance(myminusbank));
    myminusbank->withdraw(myminusbank, 40);
    printf("\n\tbalance: %d$\n", myminusbank->balance(myminusbank));

    printf("\n***** MinusBank scenario end *****\n");
    return 0;
}
