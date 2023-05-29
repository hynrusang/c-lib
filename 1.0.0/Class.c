
class (Bank) {
    int data;
    method(balance);
    method(deposit);
};

void define(Bank, balance)(Bank* this) {
    printf("ÀºÇà ÀÜ¾×: %d\n", this->data);
}

void define(Bank, deposit)(Bank* this, int money) {
    this->data += money;
}

constructor(Bank)
    link(Bank, balance);
    link(Bank, deposit);   
    this->data = 0;
end

int main() {
    Bank* test = new (Bank);
    call(test, balance);
    call(test, deposit, 100);
    call(test, balance);
    delete (test);

    return 0;
}