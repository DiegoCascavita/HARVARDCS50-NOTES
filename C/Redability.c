#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float count_letters(string text, int str_length);
float count_words(string text, int str_length);
float count_sens(string text, int str_length);

int main(void)
{
    //pedir input del usuario
    string text = get_string("Text: ");

    int length = strlen(text);

    // encontrar el numero de letras en el arreglo
    float letter_count = count_letters(text, length);

    float word_count = count_words(text, length);

    // encontrar el numero de 
    int sen_count = count_sens(text, length);

    // calcular el numero de letras y sentencias cada 100 palabras
    int L = round((100 / word_count) * letter_count);
    int S = round((100 / word_count) * sen_count);

    float index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index);

    if (index < 1)
    {
      printf("Before Grade 1\n");
    }
    else if (index > 0 && index < 16)
    {
        printf("Grade %i\n", (int) index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

float count_letters(string text, int str_length)
{
     int letters = 0;

     // iterar cada caracter
     for (int i = 0; i < str_length; i++)
    {
        // verificar que no sea un numero
        if (isalpha(text[i]) != 0)
        {

            letters++;
        }
    }
    return letters;
}

float count_words(string text, int str_length)
{
    int words = 0;

    for (int i = 0; i < str_length; i++)
    {
        // verifica si el index es == 32
        if(text[i] == 32)
        {
            // si es verdad añade 1 
            words++;
        }
    }
    words++;

    // devuelve el numero de palabras
    return words;
}

float count_sens(string text, int str_length)
{
    int sentences = 0;

    // iterador
    for (int i = 0; i < str_length; i++)
    {
        // revisar el ultimo caracter de cada sentencia
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
        }
    }
    // devuelva el numero de sentencias
    return sentences;
}