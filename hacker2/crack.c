#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

void dictionaryAttack(const char* cipherText, char salt[]) {
    
    printf("Crack using dictionary attack!!\n");
    
    //dictionary words
    char buff[256];
    FILE* dictFile = fopen("/usr/share/dict/words", "r");
    
    //loop through dictionary
    bool match = false;
    do {
        //End of dictionary
        if (fscanf(dictFile, "%s", buff) == EOF) {
            printf("Password is not in dictionary ):\n");
            break;
        }
        
        //match each crypt dict word with cipherText
        if (strcmp(crypt(buff, salt), cipherText) == 0) {
            printf("%s\n", buff);
            match = true;
        }
        
    } while (!match);
    
    
    fclose(dictFile);
}

void bruteForceAttack(const char* cipherText, char salt[]) {
    
    char password[9];
    int start = 32, end = 126;
    
    for (int ascii = start; ascii < end; ascii++) {
        password[0] = ascii;
        
        for (int ascii = start; ascii <= end; ascii++) {
            password[1] = ascii;
            
            for (int ascii = start; ascii <= end; ascii++) {
                password[2] = ascii;
                
                for (int ascii = start; ascii <= end; ascii++) {
                    password[3] = ascii;
                    
                    for (int ascii = start; ascii <= end; ascii++) {
                        password[4] = ascii;
                        
                        for (int ascii = start; ascii <= end; ascii++) {
                            password[5] = ascii;
                            
                            for (int ascii = start; ascii <= end; ascii++) {
                                password[6] = ascii;
                                
                                for (int ascii = start; ascii <= end; ascii++) {
                                    password[7] = ascii;
                                    
                                    if (strcmp(crypt(password, salt), cipherText) == 0) {
                                        printf("%s -> %s\n", password, cipherText);
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    
    if (argc != 2) {
        return -1;
    }
    
    //salt and cipherText
    const char* cipherText = argv[1];
    char salt[3];
    strncpy(salt, cipherText, 2);
    
    //dictionaryAttack(cipherText, salt);
    
    bruteForceAttack(cipherText, salt);
    
}