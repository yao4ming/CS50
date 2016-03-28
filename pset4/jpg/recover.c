/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
 
bool found4thByte(char fourthByte) {
    return 
    (
    fourthByte == (char)0xe0 || fourthByte == (char)0xe1 || 
    fourthByte == (char)0xe2 || fourthByte == (char)0xe3 || 
    fourthByte == (char)0xe4 || fourthByte == (char)0xe5 ||  
    fourthByte == (char)0xe7 || fourthByte == (char)0xe8 ||
    fourthByte == (char)0xe9 || fourthByte == (char)0xea || 
    fourthByte == (char)0xeb || fourthByte == (char)0xec ||
    fourthByte == (char)0xed || fourthByte == (char)0xee ||
    fourthByte == (char)0xef || fourthByte == (char)0xe6
    ) ? true : false;
} 

bool foundJpg(char data[]) {
    return (data[0] == (char)0xff && data[1] == (char)0xd8 && data[2] == (char)0xff && 
        found4thByte(data[3])) ? true : false;
}

int main(int argc, char* argv[])
{
    //number of jpg
    int numOfJpg = 0;
    
    FILE* infile = fopen("card.raw", "r");
    FILE* outfile;
    
    //buffer to store 512 byte block
    int n = 512;
    char data[n];
    
    //variables to hold three-digit
    int first = 0, second = 0, third = -1;
    
    //repeat until EOF
    while (fread(data, sizeof(char)*n, 1, infile) == 1) {
        
        //found begin of new jpg
        if (foundJpg(data)) {
            numOfJpg++;
            
            //close prev output file
            if (numOfJpg > 1) fclose(outfile);
            
            //used for naming outfiles
            third++;
            if (third == 10) {
                second++;
                third = 0;
            }
            
            //create new output jpg
            char title[8];
            sprintf(title, "%i%i%i.jpg", first, second, third);
            outfile = fopen(title, "a");
            
        } 
        //found beginning of collection of jpg, start creating outfile
        if (numOfJpg >= 1) fwrite(data, sizeof(char)*n, 1, outfile);
        
    }
    fclose(infile);
    fclose(outfile);
}
