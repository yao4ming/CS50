#include <stdio.h>
#include <cs50.h>
#include <math.h>

int calculateCoins(float money) {
    int amountLeft = 0;
    int roundedAmount = (int) round(money * 100);
    
    int numOfQuarters = roundedAmount / 25;
    amountLeft = roundedAmount % 25;
    
    int numOfDimes = amountLeft / 10;
    amountLeft = amountLeft % 10;
    
    int numOfNickels = amountLeft / 5;
    amountLeft = amountLeft % 5;
    
    return numOfQuarters + numOfDimes + numOfNickels + amountLeft;
}

bool validateInput(float input) {
    return input >= 0 ? true : false;
}

int main()
{
    float money;
    do {
        printf("How much money is owed?\n");
        money = GetFloat();

    } while(validateInput(money) == false);
    printf("%i\n", calculateCoins(money));

    return 0;
}