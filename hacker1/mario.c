#include <stdio.h>
#include <cs50.h>

void printLine(int spaces, int line) {
    
    //first half 
    for (int i = 1; i <= spaces; i++) printf(" ");
    for(int i = 1; i <= line; i++) printf("#");
    
    printf("  ");
    
    //second half
    for(int i = 1; i <= line; i++) printf("#");
    for (int i = 1; i <= spaces; i++) printf(" ");
    
    printf("\n");
}

int main(void) {
    
    int height;
    do{
        printf("Enter height of pyramid between 0 and 23: ");
        height = GetInt();
        
    }while(height < 0 || height > 23);
    
    for (int line = 1; line <= height; line++) {
        int spaces = height - line;
        printLine(spaces, line);
    }
}