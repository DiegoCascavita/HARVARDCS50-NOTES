#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


unsigned int Count_size = 0;

#include "dictionary.h"

typedef struct element
{
    char word[LENGTH + 1];
    struct element *next;
}
element;

// numero de buckets en el hashtable
const unsigned int N = 1000;

element *table[N];

// el programa devuelve V/F si la palabra esta en el diccionario
bool check(const char *word)
{
    int index = hash(word);

    element *cursor = table[index];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor -> word, word) == 0)
        {
            return true;
        }
        cursor = cursor -> next;
    }
    return false;
}

// cada palabra asociada a un hash
unsigned int hash(const char *word)
{
    unsigned int data = 0;
    unsigned int key_len = strlen(word);
    for (int k = 0; k < key_len; k++)
    {
        data = data + 37 * tolower(word[k]);
    }
    data = data % N;
    return data;
}

//  carga el diccionario en memoria devolviendo true si es exitoso
bool load(const char *dictionary)
{
    FILE *open_dictionary = fopen(dictionary, "r");
    if (open_dictionary == NULL)
    {
        return false;
    }
    char Dword[LENGTH + 1];
    while (fscanf(open_dictionary, "%s", Dword) != EOF)
    {
        element *newNode = malloc(sizeof(element));
        if (newNode == NULL)
        {
            return false;
        }
        strcpy(newNode -> word, Dword);
        newNode -> next = NULL;
        int index = hash(Dword);

        if (table[index] == NULL)
        {
            table[index] = newNode;
        }
        else
        {
            newNode -> next = table[index];
            table[index] = newNode;
        }
        Count_size++;
    }
    fclose(open_dictionary);
    return true;
}

// devuelve el numero de palabras en el diccionario.
unsigned int size(void)
{
    return Count_size;
}
// libera espacio en memoria
bool unload(void)
{
    for (int j = 0; j < N; j++)
        while (table[j] != NULL)
        {
        element *tmp = table[j] ->next;
            free(table[j]);
            table[j] = tmp;
        }
    return true;
}