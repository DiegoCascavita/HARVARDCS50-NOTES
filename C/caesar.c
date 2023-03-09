#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(int argc, string argv[])
{
    // verifica si solo hay 1 argumento y si es numero, de lo contrario reppita
    if (argc == 2 && isdigit(*argv[1]))

    {
        //convierte la llave a numero integral
        int key = atoi(argv[1]);
        //toma el texto
        string s = get_string("plaintext: ");
        //imprime el cypher
        printf("ciphertext: ");
        // itera  letra por letra
        for (int i = 0, n = strlen(s) ; i < n; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')// si el elemento en el index es +a -z
            {
            printf("%c", (((s[i] - 'a') + key) % 26) + 'a');// imprimalo en minuscula
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
            printf("%c", (((s[i] - 'A') + key) % 26) + 'A');// imprimalo en mayuscula
            }
            else
            {
                printf("%c", s[i]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;

    }
}