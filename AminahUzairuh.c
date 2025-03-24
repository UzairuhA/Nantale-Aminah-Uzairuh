#include <stdio.h>

int main() {
    int balance = 50000;
    int withdraw = 20000;

    if (withdraw > balance) {
        printf("insufficient balance!\n");
    } else {
        balance -= withdraw;
        printf("Transaction sussessful!\n");
        printf("remaining balancing: %d\n" , balance);
    }
    return 0;
}