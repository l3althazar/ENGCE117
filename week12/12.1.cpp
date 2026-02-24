#include <stdio.h>

int *Dijkstra( int *L, int n )
{
    int *d = new int[ n - 1 ];
    int visited[ 5 ];
    int i = 0, j = 0;

    for ( i = 0; i < n; i++ )
        visited[ i ] = 0;

    for ( i = 1; i < n; i++ )
        d[ i - 1 ] = L[ 0 * n + i ];

    visited[ 0 ] = 1;

    for ( i = 1; i < n; i++ )
    {
        int min = -1;
        int u = -1;

        for ( j = 1; j < n; j++ )
        {
            if ( visited[ j ] == 0 && d[ j - 1 ] != -1 )
            {
                if ( min == -1 || d[ j - 1 ] < min )
                {
                    min = d[ j - 1 ];
                    u = j;
                }
            }
        }

        if ( u == -1 )
            break;

        visited[ u ] = 1;

        for ( j = 1; j < n; j++ )
        {
            if ( visited[ j ] == 0 && L[ u * n + j ] != -1 )
            {
                int newDist = min + L[ u * n + j ];

                if ( d[ j - 1 ] == -1 || newDist < d[ j - 1 ] )
                    d[ j - 1 ] = newDist;
            }
        }
    }

    return d;
}

int main()
{
    int n = 5, i = 0, j = 0, *d, *g;

    g = new int[ n * n ];

    for ( i = 0; i < n; i++ )
        for ( j = 0; j < n; j++ )
            g[ i * n + j ] = -1;

    g[ 0 * n + 1 ] = 100;  g[ 0 * n + 2 ] = 80;
    g[ 0 * n + 3 ] = 30;   g[ 0 * n + 4 ] = 10;
    g[ 1 * n + 2 ] = 20;   g[ 3 * n + 1 ] = 20;
    g[ 3 * n + 2 ] = 20;   g[ 4 * n + 3 ] = 10;

    d = Dijkstra( g, n );

    for ( i = 0; i < n - 1; i++ )
        printf( "%d ", d[ i ] );

    return 0;
}