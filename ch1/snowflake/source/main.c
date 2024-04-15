#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "snowflake.h"

#define MAX_N 100000

typedef unsigned int uint;

int main(void)
{

    //--------------------------------- read n: the number of snowflakes ---------------------------------
    uint n;
    printf("Please enter the number of snowflakes: ");
    int status = scanf("%u", &n);
    if (status != 1)
    {
        printf("Failed to read the number of snowflakes...\n");
        return EXIT_FAILURE;
    }
    if (n > MAX_N)
    {
        printf("The number of snowflakes cannot be that large...\n");
        return EXIT_FAILURE;
    }

    //--------------------------------- allocate snowflakes on the heap ---------------------------------
    Snowflake *sf = malloc(n * sizeof(Snowflake));
    if (sf == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    //--------------------------------- read the arms of each snowflakes ---------------------------------
    for (uint i = 0; i < n; i++)
    {
        printf("\nPlease enter 6 space-separated numbers for snowflake %u: ", i);
        Snowflake *flake = sf + i;
        flake->id = i;
        for (int j = 0; j < arms; j++)
        {
            status = scanf("%lu", flake->arms_len + j);
            if (status != 1)
            {
                printf("Failed to read the snowflake arms...\n");
                return EXIT_FAILURE;
            }
            if (flake->arms_len[j] > MAX_LENGTH)
            {
                printf("Snowflake arms cannot be that large...\n");
                return EXIT_FAILURE;
            }
        }
    }

    //--------------------------------- print the flakes ---------------------------------
    for (uint i = 0; i < n; i++)
    {
        print_snow(sf + i);
    }

    

    free(sf);
    return EXIT_SUCCESS;
}