#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "snowflake.h"

bool compare_flakes_right(Snowflake *flake1, Snowflake *flake2, uint offset)
{
    for (uint i = 0; i < arms; i++)
    {
        uint i2 = (i + offset) % arms;
        if (flake1->arms_len[i] != flake2->arms_len[i2])
            return false;
    }
    return true;
}

bool compare_flakes_left(Snowflake *flake1, Snowflake *flake2, uint offset)
{
    for (uint i = 0; i < arms; i++)
    {
        uint i2 = (offset >= i) ? offset - i : arms + offset - i;
        if (flake1->arms_len[i] != flake2->arms_len[i2])
            return false;
    }
    return true;
}

bool compare_flakes(Snowflake *flake1, Snowflake *flake2)
{
    for (uint offset = 0; offset < arms; offset++)
    {
        if (compare_flakes_right(flake1, flake2, offset) || compare_flakes_left(flake1, flake2, offset))
            return true;
    }
    return false;
}

bool mathcing_flakes(Snowflake *flakes, uint n)
{
    for (uint i = 0; i < n - 1; i++)
    {
        for (uint j = i + 1; j < n; j++)
        {
            Snowflake *flake1 = flakes + i;
            Snowflake *flake2 = flakes + j;
            if (compare_flakes(flake1, flake2))
            {
                return true;
            }
        }
    }
    return false;
}

#endif