#include <cs50.h>
#include <stdio.h>
#include <string.h>

int multipleDigitsByTwo(int oddDigit) {
    return oddDigit * 2;
}

void getAlternateDigits(int* oddDigits, int* evenDigits, string cardNum) {
    
    for (int i = 0; i < strlen(cardNum) / 2; i++) {
        
        if (strlen(cardNum) % 2 == 0) {
            
            evenDigits[i] = multipleDigitsByTwo(cardNum[i*2] - '0');
            oddDigits[i] = cardNum[i*2+1] - '0';
            // printf("%i %i- even \n", evenDigits[i], i);
            // printf("%i %i- odd \n", oddDigits[i], i);
        }
        else {

            oddDigits[i] = multipleDigitsByTwo(cardNum[i*2+1] - '0'); 
            evenDigits[i] = cardNum[i*2] - '0';
            // printf("%i %i- odd \n", oddDigits[i], i);
            // printf("%i %i- even \n", evenDigits[i], i);
        }
    }
}

int addAlternateDigits(int* oddDigits, int* evenDigits, int numOfDigits) {
    
    int sum = 0;

    for (int i = 0; i < numOfDigits; i++) {
        
        //add digits of two digit number
        if (oddDigits[i] > 9) {
            
            int onesPlace = oddDigits[i] % 10;
            int tensPlace = oddDigits[i] / 10;
            sum = sum + onesPlace + tensPlace;
            // printf("%i %i %i- two digit\n", onesPlace, tensPlace, i);
            // printf("sum = %i\n", sum);
            
        }
        else {
            sum += oddDigits[i];
            // printf("%i %i- one digit\n", oddDigits[i], i);
            // printf("sum = %i\n", sum);
        }
        
        if (evenDigits[i] > 9) {
            int onesPlace = evenDigits[i] % 10;
            int tensPlace = evenDigits[i] / 10;
            sum = sum + onesPlace + tensPlace;
            // printf("%i %i %i- two digit\n", onesPlace, tensPlace, i);
            // printf("sum = %i\n", sum);
        }
        else {
            sum += evenDigits[i];
            // printf("%i %i - even\n", evenDigits[i], i);
            // printf("sum = %i\n", sum);
        }
        
    }
    
    return sum;
}

int main(void) {
    
    printf("Enter your credit card number: ");
    string cardNum = GetString();
        
    while(strtol(cardNum, NULL, strlen(cardNum)) == 0) {
        printf("Retry: ");
        cardNum = GetString();
    }
    
    int halfCardLen = strlen(cardNum) / 2;
    //printf("%i - halfcardLen\n", halfCardLen);
    
    int oddDigits[halfCardLen];
    int evenDigits[halfCardLen];
    
    getAlternateDigits(&oddDigits[0], &evenDigits[0], cardNum);
    
    int sum = addAlternateDigits(&oddDigits[0], &evenDigits[0], halfCardLen);
    
    if (strlen(cardNum) % 2 == 1) {
        sum += atoi(&cardNum[strlen(cardNum)-1]);
    }
    
    //printf("%i\n", sum);
    
    if(sum % 10 == 0) {
        
        if(cardNum[0] == '3' && (cardNum[1] == '4' || cardNum[1] == '7')) 
            printf("AMEX\n");
        else if(cardNum[0] == '5' && (cardNum[1] == '1' || cardNum[1] == '2' || cardNum[1] == '3' || cardNum[1] == '4' || cardNum[1] == '5'))
            printf("MASTERCARD\n");
        else if(cardNum[0] == '4')
            printf("VISA\n");
    }
    else
        printf("INVALID\n");

}