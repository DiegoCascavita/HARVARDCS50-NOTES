#include <stdio.h>
#include <cs50.h>

int main(void) // declaring type
{
    string name = get_string("What is your name? "); //users input
    printf("hello, %s!\n", name); // users answer concatenated
}