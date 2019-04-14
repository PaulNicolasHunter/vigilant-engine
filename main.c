#include <stdio.h>
#include <stdlib.h>
#define p printf

int len(char *stream)
{
    int co=0;
    while (*stream)
    {
        ++stream;
        co += 1;
    }
    return co; /*including null character*/
}

void key_seg(char *key)
{
    int i;
    for (i=0; i<len(key) - 1; i++)
    {
        if (48 <= key[i] <= 57)
        {
            key[i] = key[i] - 48;
        }
        else if (65 <= key[i] <= 90)
        {
            key[i] = key[i] - 65 + 10; /*'A' is 10*/
        }
        else /*not needed actually, put your remarks*/
        {
            key[i] = key[i] - 97 + 10; /*"a" is also treated as A*/
        }
    }
}

void binkey(char *key_in, int *f_key)
{
    int i, j, ind, co = 0;
    int temp[4];
    int mask;

    for (i =0; i<len(key_in)-1; i++)
    {
        mask = 4 << 1; /* 100 */
        j = 0;
        while (mask>0)
        {
            temp[j] = (((int)key_in[i] & mask) > 0 );
            mask = mask >> 1; /* move the bit down */
            j++;
        }
        for (j = 0; j < 4; j++)
        {
            f_key[co + j] = temp[j];
        }
        co += 4;
    }
}

int main()
{
    char key_in[17];
    int f_key[64], i;
    puts("put the key");
    fgets(key_in, 17, stdin);

    key_seg(key_in); /*convert alphabets to numbers*/
    binkey(key_in, f_key); /*convert them to binary*/

    for (i=0; i<64; i++)
    {
        p("%d", f_key[i]);   /*put and 16 numbers in the fgets() for 64 else, instead of 64 put = numbers entered * 4*/
    }

    return 0;
}
