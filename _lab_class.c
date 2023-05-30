#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#define classes(_class_type) typedef struct _class_type _class_type; struct _class_type
#define f(_class_type, _method, ...) _class_type##$##_method(_class_type* this, __VA_ARGS__) 

#define constructor(_class_type, ...) _class_type* new(_class_type, __VA_ARGS__)
#define bind(_class_type) _class_type* this = malloc(sizeof(_class_type)); if (this == NULL) exit(1);
#define destroyer(_class_type) void delete_##_class_type(_class_type* this)
#define unbind free(this)

#define new(_class_type, ...) new_##_class_type(__VA_ARGS__)
#define delete(_class_type, _object) delete_##_class_type(_object)

classes (Bank) {
	int money;
};

int f(Bank, balance) {
	return this->money;
}
int f(Bank, deposit, int money) {
	this->money += money;
	printf("\n%d원이 입금되었습니다.\n", money);
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
	return this->money;
}
void f(Bank, display) {
	printf("\n현재 잔고: %d\n", Bank$balance(this));
}

constructor(Bank, int money) {
	bind(Bank);
	this->money = money;
}
destroyer(Bank) {
	unbind;
}

main() {
	printf("c 객체 테스트 프로그램:\n");
	Bank* mybank = new (Bank, 2000);

	Bank$display(mybank);
	Bank$deposit(mybank, 3000);
	Bank$display(mybank);
	Bank$withdraw(mybank, 2000);
	Bank$display(mybank);
	Bank$withdraw(mybank, 2000);
	Bank$display(mybank);
	Bank$withdraw(mybank, 2000);
	Bank$display(mybank);

	delete (Bank, mybank);
}