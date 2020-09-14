// Hash table with linked list

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORDLENGTH 20
#define HASHTABLELENGTH 10
#define SAMPLEARRAYLENGTH 10

// Represents a node in a hash table
typedef struct node
{
    char word[WORDLENGTH];
    struct node *next;
}
node;

// Hash table
node *table[HASHTABLELENGTH];

// Hashes the word to a number using modulo operator to get a location in the hash table.
unsigned int hash(const char *word)
{
    unsigned long i = 0;
    for (int j = 0; word[j]; j++)
    {
        i += tolower(word[j]);
    }

    return i % HASHTABLELENGTH;
}

// Free memory
bool unload(void)
{
    for (int i = 0; i < HASHTABLELENGTH; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;
        }
    }

    return true;
}

int main ()
{
    char word[WORDLENGTH];
    unsigned int index;
    node *swap = malloc(sizeof(node));

    char words[SAMPLEARRAYLENGTH][WORDLENGTH] = { "cat", "dog", "snake", "lion", "rabbit", "deer", "mice", "human", "monkey", "elephant" };

    for (int i = 0; i < SAMPLEARRAYLENGTH; i++)
    {
        index = hash(words[i]);

        // if there is no head node
        if (table[index] == NULL)
        {
            node *n = malloc(sizeof(node));
            if (n == NULL)
            {
                return false;
            }

            strcpy(n->word, words[i]);
            n->next = NULL;
            table[index] = n;
        }
        // if there is a head node, put the node before the head node
        else
        {
            node *n = malloc(sizeof(node));
            if (n == NULL)
            {
                return false;
            }

            strcpy(n->word, words[i]);
            n->next = NULL;

            swap = table[index];
            n->next = swap;
            table[index] = n;
        }
    }

    for (int i = 0; i < HASHTABLELENGTH; i++)
    {
        for (node *tmp = table[i]; tmp != NULL; tmp = tmp->next)
        {
            printf("%s is at loaction %i in hash table \n", tmp->word, i);
        }
    }

    free(swap);
    unload();
}
