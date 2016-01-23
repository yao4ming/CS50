#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    
    //get name from user
    char* user_name = GetString();
    char initials[3];
    bool foundFirstLetter = false;
    
    for(int i = 0; i < strlen(user_name); i++) {
        
        //find first letter in name
        if (isalpha(user_name[i]) && !foundFirstLetter) {

            strncpy(initials, &user_name[i], 1);
            
            foundFirstLetter = true;
        }
        
        //after first letter, find space followed by a letter
        if (foundFirstLetter) {
            if (isspace(user_name[i]) && isalpha(user_name[i+1])) {
                
                strncat(initials, &user_name[i+1], 1);
            }
        }
    }
    
    //convert initials to uppercase
    for (int i = 0; i < 3; initials[i] = toupper(initials[i]), i++);
    
    printf("%s\n", initials);
    
    
}