#define key
#ifdef key

#include "Class.h"
#include <stdio.h>

classes (Bank) {
	int money;
};
classes (MinusBank) {
	int money;
	double debt_p;
};

int f(Bank, balance) {
	return this->money;
}
void f(Bank, display) {
	printf("\n현재 잔고: %d\n", Bank$balance(this));
}
int f(Bank, deposit, int money) {
	this->money += money;
	printf("\n%d원이 입금되었습니다.\n", money);
	Bank$display(this);
	return this->money;
}
int f(Bank, withdraw, int money) {
	if (this->money - money < 0) {
		printf("\n잔액이 모자랍니다.\n");
		return 0;
	} else {
		printf("\n%d원이 인출되었습니다.\n", money);
		this->money -= money;
	}
	Bank$display(this);
	return this->money;
}
constructor(Bank, int money) {
	bind(Bank);
	this->money = money;
}
destroyer(Bank) {
	unbind;
}

int f(MinusBank, withdraw, int money) {
	if (this->money - money < 0) {
		printf("\n%d원이 인출되었습니다. (가산된 빛: %d원)\n", money, (int)(money * this->debt_p / 100));
		this->money -= money * (1 + this->debt_p / 100);
	}
	else {
		printf("\n%d원이 인출되었습니다.\n", money);
		this->money -= money;
	}
	Bank$display(this);
	return this->money;
}
constructor(MinusBank, int money, double debt_p) {
	bind(MinusBank);
	this->money = money;
	this->debt_p = debt_p;
}
destroyer (MinusBank) {
	unbind;
}

main() {
	int testdata = 3000;
	printf("c 객체 테스트 프로그램\n");
	printf("\n시나리오: class Bank\n");

	Bank* mybank = new (Bank, testdata);
	Bank$display(mybank);

	Bank$deposit(mybank, testdata);
	Bank$withdraw(mybank, testdata);
	Bank$withdraw(mybank, testdata);
	Bank$withdraw(mybank, testdata);
	delete (Bank, mybank);

	printf("\n시나리오: class MinusBank extends Bank\n");

	MinusBank* myminusbank = new (MinusBank, testdata, 10);
	Bank$display(myminusbank);

	Bank$deposit(myminusbank, testdata);
	MinusBank$withdraw(myminusbank, testdata);
	MinusBank$withdraw(myminusbank, testdata);
	MinusBank$withdraw(myminusbank, testdata);
	delete (MinusBank, myminusbank);
}
#endif