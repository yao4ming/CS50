/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include "dictionary.h"

/**
 * used to keep track of words in trie 
 */
int wordNum = 0;

/**
 * helper hash function
 */
int hash(const char* key) {
    int index = tolower(key[0]) - 'a';
    return index;
}
/**
 * prints content in hashtable
 */
void printHashTable() {
    for (int i = 0; i < ALPHA_LENGTH; i++) {
        while (hashTable[i] != NULL) {
            printf("%s ", hashTable[i]->word);
            hashTable[i] = hashTable[i]->next;
            wordNum++;
        }
        printf("\n");
    }
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* temp) {
    //strToLower
    char word[LENGTH+1];
    strncpy(word, temp, LENGTH+1);
    for (int i = 0; i < word[i]; i++) word[i] = (char) tolower(word[i]);
    
    //search
    int index = hash(word);
    currPos[index] = hashTable[index];
    while (currPos[index] != NULL && strcmp(currPos[index]->word, word) != 0) {
        currPos[index] = currPos[index]->next;
    }

    return currPos[index] != NULL ? true : false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
node* allocateNode(node* currNode) {
    currNode = malloc(sizeof(node));
    assert(currNode != NULL);
    strcpy(currNode->word, temp);
    currNode->next = NULL;
    return currNode;
}
bool load(const char* dictionary) {
    FILE* file = fopen(dictionary, "r");
    assert(file != NULL);

    for(int i = 0; i < ALPHA_LENGTH; i++) {
        hashTable[i] = currPos[i] = NULL;
    }

    //allocate a node for every word read in and insert them into hashtable
    while((fscanf(file, "%s", temp) == 1)) {  //check for eof

        int index = hash(temp);

        //linked-list is empty
        if(hashTable[index] == NULL) {
            hashTable[index] = allocateNode(hashTable[index]);
            currPos[index] = hashTable[index];
        }
        //insert node into linked-list
        else {
            currPos[index]->next = allocateNode(currPos[index]->next);
            currPos[index] = currPos[index]->next;
        }
        wordNum++;
    }

    fclose(file);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void) {
    return wordNum;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void) {
    for (int i = 0; i < ALPHA_LENGTH; i++) {
        while (hashTable[i] != NULL) {
            node* temp = hashTable[i];
            hashTable[i] = hashTable[i]->next;
            free(temp);
        }
    }
    
    //double-check hashtable to empty
    for (int i = 0; i < ALPHA_LENGTH; i++) {
        if (hashTable[i] != NULL) return false;
    }
    return true;
}
