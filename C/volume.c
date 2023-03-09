// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t header[HEADER_SIZE];
    //Declara una variable de tipo uint8_t (enteros sin signo de 8 bits)
    //llamada "header" con un tamaño especificado por la constante "HEADER_SIZE".
    if (fread(header, sizeof(header), 1, input) != 1)
    {
        printf("Error reading header\n");
        return 1;
    }
    //Utiliza la función "fread" para leer los datos de la cabecera del archivo de
    // entrada y almacenarlos en la variable "header"
    if (fwrite(header, sizeof(header), 1, output) != 1)
    {
        printf("Error writing header\n");
        return 1;
    }
    //Si la función "fread" no devuelve un valor de 1 (indicando que se ha leído un solo
    //bloque de datos), significa que ha ocurrido un error al leer la cabecera y se imprime
    //un mensaje de error y se termina la ejecución del programa.
    int16_t buffer;
    while (fread(&buffer, sizeof(buffer), 1, input) == 1)
    {
        buffer *= factor;
        //Utiliza la función "fwrite" para escribir los datos de la cabecera en el archivo de salida.
        // Si la función "fwrite" no devuelve un valor de 1 (indicando que se ha escrito un solo bloque
        if (fwrite(&buffer, sizeof(buffer), 1, output) != 1)
        {
            printf("Error writing samples\n");
        return 1;
        }
    }
    // Close files
    fclose(input);
    fclose(output);
}
