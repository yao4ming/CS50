#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("minutes: ");
    int minutes = GetInt();
    
    int bottles = minutes * 12;
    printf("%i\n", bottles);
    return 0;
}