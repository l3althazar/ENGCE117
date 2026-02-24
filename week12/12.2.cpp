#include <stdio.h>

int *KnapsackGreedy( int *w, int *v, int n, int wx )
{
    int *select = new int[n];
    int i;

    for ( i = 0; i < n; i++ )
        select[i] = 0;

    int capacity = wx;

    while ( 1 )
    {
        int bestIndex = -1;
        double bestRatio = 0.0;

        for ( i = 0; i < n; i++ )
        {
            if ( select[i] == 0 && w[i] <= capacity )
            {
                double ratio = (double)v[i] / w[i];

                if ( ratio > bestRatio )
                {
                    bestRatio = ratio;
                    bestIndex = i;
                }
            }
        }

        if ( bestIndex == -1 )
            break;

        select[bestIndex] = 1;
        capacity = capacity - w[bestIndex];
    }

    return select;
}

int main()
{
    int n = 5, wx = 11;
    int w[5] = { 1, 2, 5, 6, 7 };
    int v[5] = { 1, 6, 18, 22, 28 };

    int *x = KnapsackGreedy( w, v, n, wx );

    int i;
    for ( i = 0; i < n; i++ )
        printf( "%d ", x[i] );

    return 0;
}