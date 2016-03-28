/**
 * dictionary.h
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Declares a dictionary's functionality.
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// number of alphabets plus apostrophe
#define ALPHA_LENGTH 27

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define WORD_LENGTH 46

//Use trie as data structure for dictionary
typedef struct node {
    struct node* children[ALPHA_LENGTH];
    bool is_word;
}node;
node* trie;
node* root;

//temporary storage for word read-in
char temp[WORD_LENGTH];

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word);

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);

#endif // DICTIONARY_H
