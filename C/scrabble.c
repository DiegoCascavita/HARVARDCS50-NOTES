#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//  Puntos asignados a cada letra del alfabeto 
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// ASCCI letras minusculas
int letras_Minusculas[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};

// Ascii letras mayusculas
int letras_Mayusculas[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
int temp_Points [] = {};


int compute_score(string word);

int main(void)
{
    // tomando el input de cada jugador
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // calcula el puntaje de cada jugador
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Imprime el ganador
    if (score1 > score2)
    {
        printf("Player 1 wins");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins");
    }
    else
    {
        printf("Tie");
    }
}

int compute_score(string word)
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        // rectificar si es mayuscula
        if (isupper(word[i]))
        {
            // toma el valor ASCII de la letra en su posicion y calcula el puntaje
            for (int f = 0; f < sizeof(letras_Mayusculas); f++)
            {
                if (word[i] == letras_Mayusculas[f])
                {
                    temp_Points[i] = POINTS[f];
                    score += temp_Points[i];
                }
            }
        }
        else if (islower(word[i]))
        {
             // toma el valor ASCII de la letra en su posicion y calcula el puntaje
            for (int f = 0; f < sizeof(letras_Minusculas); f++)
            {
                if (word[i] == letras_Minusculas[f])
                {
                    temp_Points[i] = POINTS[f];
                    score += temp_Points[i];
                }
            }
        }
        // ignora cualquier otro simbolo
        else
        {
            i += 1;
        }
    }
    return score;

}