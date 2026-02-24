#include <stdio.h>

int *KnapsackDP( int *w, int *v, int n, int wx )
{
    int i, j;

    int **table = new int*[ n + 1 ];
    for ( i = 0; i <= n; i++ )
        table[i] = new int[ wx + 1 ];

    for ( i = 0; i <= n; i++ )
    {
        for ( j = 0; j <= wx; j++ )
        {
            if ( i == 0 || j == 0 )
            {
                table[i][j] = 0;
            }
            else if ( w[i - 1] <= j )
            {
                int includeValue = v[i - 1] + table[i - 1][ j - w[i - 1] ];
                int excludeValue = table[i - 1][j];

                if ( includeValue > excludeValue )
                    table[i][j] = includeValue;
                else
                    table[i][j] = excludeValue;
            }
            else
            {
                table[i][j] = table[i - 1][j];
            }
        }
    }

    int *selected = new int[n];
    for ( i = 0; i < n; i++ )
        selected[i] = 0;

    int remainingWeight = wx;

    for ( i = n; i > 0; i-- )
    {
        if ( table[i][remainingWeight] != table[i - 1][remainingWeight] )
        {
            selected[i - 1] = 1;
            remainingWeight = remainingWeight - w[i - 1];
        }
    }

    return selected;
}

int main()
{
    int n = 5, wx = 11;
    int w[5] = { 1, 2, 5, 6, 7 };
    int v[5] = { 1, 6, 18, 22, 28 };

    int *x;
    x = KnapsackDP( w, v, n, wx );

    int i;
    for ( i = 0; i < n; i++ )
        printf( "%d ", x[i] );

    return 0;
}