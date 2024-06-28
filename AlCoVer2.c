#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define anlf 26
void alpha ( char *sitr )
{
    for ( int i = 0; i < anlf; ++i )
    {
        char *p = strchr ( sitr, 'a' + i ), *q = strchr ( sitr, 'A' + i );
        int j= 0;
        while ( p ){
            j++;
            p++;
            p = strchr ( p, 'a' + i );
        }
        while ( q ){
            j++;
            q++;
            q = strchr ( q, 'A' + i );
        }
        if (j)
            printf(" %c is repeated %d times \n", 'a' + i, j);
    }
}

int main()
{
    short h; char *ster = (char *) malloc ( anlf * 4 ), l[] = " ";
    if ( ster == NULL ) {
        puts(" buy a brand new RAM for god's sake ");
        exit (EXIT_FAILURE);
    }
    printf(" enter a string: ", h);
    gets ( ster );
    alpha ( ster );
    puts(l);
    free( ster );
    ster = NULL;
    return 0;
}
