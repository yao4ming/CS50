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
int hash(const char key) {
    int index = tolower(key) - 'a';
    return index % ALPHA_LENGTH;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word) {
    node* curr = root;

    int letterpos = 0;
    int index;

    //traverse trie node foreach letter
    while(letterpos < strlen(word)) {
        index = hash(word[letterpos++]);
        curr = curr->children[index];
        if(curr == NULL) return 0;
    }
    return curr->is_word ? 1 : 0;

}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
node* allocateBlock(node* trie) {
    
    //allocate memory for trie node
    trie = malloc(sizeof(node));
    assert(trie != NULL);
    
    //init trie node
    trie->is_word = false;
    for(int i = 0; i < ALPHA_LENGTH; i++)
        trie->children[i] = NULL;
        
    //return allocated and initialized trie node   
    return trie;
}
bool load(const char* dictionary) {
    FILE* file = fopen(dictionary, "r");
    assert(file != NULL);

    root = allocateBlock(root);

    int index, letterPos;

    //read word from file
    while(fscanf(file, "%s", temp) == 1) {

        //reset for new word
        letterPos = 0;
        trie = root;

        while(letterPos < strlen(temp)) {
            index = hash(temp[letterPos++]); //letter

            //allocate new node if element points to null
            if(trie->children[index] == NULL) {
                trie->children[index] = allocateBlock(trie->children[index]);
            }
            trie = trie->children[index];
        }
        wordNum++;
        trie->is_word = true;
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
    // TODO
    return true;
}
