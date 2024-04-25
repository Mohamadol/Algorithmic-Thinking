#ifndef SNOWFLAKE_H
#define SNOWFLAKE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"

#define MAX_LENGTH 10000000
#define arms 6

typedef struct
{
    int id;
    ulong arms_len[arms];
} Snowflake;

void print_snow(const Snowflake *flake)
{
    printf("----------\n");
    printf("snow flake id is %d\n", flake->id);
    printf("arms: ");
    for (int i = 0; i < arms; i++)
    {
        printf("%lu ", flake->arms_len[i]);
    }
    printf("\n----------\n");
}

#endif