#include <stdio.h>

int *KnapsackGreedy( int *w, int *v, int n, int wx )
{
    int *selected = new int[ n ];
    int index, j;

    for ( index = 0; index < n; index++ )
        selected[ index ] = 0;

    for ( index = 0; index < n - 1; index++ )
    {
        for ( j = index + 1; j < n; j++ )
        {
            double r1 = (double)v[ index ] / w[ index ];
            double r2 = (double)v[ j ] / w[ j ];

            if ( r2 > r1 )
            {
                int temp;

                temp = w[ index ];
                w[ index ] = w[ j ];
                w[ j ] = temp;

                temp = v[ index ];
                v[ index ] = v[ j ];
                v[ j ] = temp;
            }
        }
    }

    int currentWeight = 0;

    for ( index = 0; index < n; index++ )
    {
        if ( currentWeight + w[ index ] <= wx )
        {
            selected[ index ] = 1;
            currentWeight += w[ index ];
        }
    }

    return selected;
}

int main()
{
    int n = 5, wx = 11;
    int w[ 5 ] = { 1, 2, 5, 6, 7 };
    int v[ 5 ] = { 1, 6, 18, 22, 28 };

    int *x = KnapsackGreedy( w, v, n, wx );

    for ( int i = 0; i < n; i++ )
        printf( "%d ", x[ i ] );

    return 0;
}