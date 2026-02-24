#include <stdio.h>
#include <stdlib.h>

int *KnapsackGreedy( int *w, int *v, int n, int wx );

int main()
{
    int n = 5;
    int wx = 11;

    int w[ 5 ] = { 1, 2, 5, 6, 7 };
    int v[ 5 ] = { 1, 6, 18, 22, 28 };

    int *x = KnapsackGreedy( w, v, n, wx );

    int index;

    for ( index = 0; index < n; index++ )
    {
        printf( "%d ", x[ index ] );
    }

    free( x );

    return 0;
}

int *KnapsackGreedy( int *w, int *v, int n, int wx )
{
    int *selectedItems;
    int *used;
    int itemIndex;
    int bestIndex;
    int remainingWeight;
    double bestRatio;
    double currentRatio;

    selectedItems = (int *)malloc( n * sizeof( int ) );
    used = (int *)malloc( n * sizeof( int ) );

    for ( itemIndex = 0; itemIndex < n; itemIndex++ )
    {
        selectedItems[ itemIndex ] = 0;
        used[ itemIndex ] = 0;
    }

    remainingWeight = wx;

    while ( 1 )
    {
        bestRatio = -1.0;
        bestIndex = -1;

        for ( itemIndex = 0; itemIndex < n; itemIndex++ )
        {
            if ( used[ itemIndex ] == 0 )
            {
                if ( w[ itemIndex ] <= remainingWeight )
                {
                    currentRatio =
                        (double)v[ itemIndex ] /
                        (double)w[ itemIndex ];

                    if ( currentRatio > bestRatio )
                    {
                        bestRatio = currentRatio;
                        bestIndex = itemIndex;
                    }
                }
            }
        }

        if ( bestIndex == -1 )
        {
            break;
        }

        selectedItems[ bestIndex ] = 1;
        used[ bestIndex ] = 1;
        remainingWeight =
            remainingWeight - w[ bestIndex ];
    }

    free( used );

    return selectedItems;
}