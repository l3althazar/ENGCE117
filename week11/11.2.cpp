#include <stdio.h>

void mergesort( int t[], int k );
void merge( int *u, int m, int *v, int n, int *t );

int main()
{
    int data[ 7 ] = { 4, 6, 1, 2, 5, 1, 8 };
    int n = 7;
    int index;

    mergesort( data, n );

    for ( index = 0; index < n; index++ )
    {
        printf( "%d ", data[ index ] );
    }

    return 0;
}

void mergesort( int t[], int k )
{
    if ( k <= 1 )
    {
        return;
    }

    int middleIndex = k / 2;
    int leftCount = middleIndex;
    int rightCount = k - middleIndex;

    int leftArray[ 100 ];
    int rightArray[ 100 ];

    int leftIndex;
    int rightIndex;

    for ( leftIndex = 0; leftIndex < leftCount; leftIndex++ )
    {
        leftArray[ leftIndex ] = t[ leftIndex ];
    }

    for ( rightIndex = 0; rightIndex < rightCount; rightIndex++ )
    {
        rightArray[ rightIndex ] = t[ middleIndex + rightIndex ];
    }

    mergesort( leftArray, leftCount );
    mergesort( rightArray, rightCount );

    merge( leftArray, leftCount, rightArray, rightCount, t );
}

void merge( int *u, int m, int *v, int n, int *t )
{
    int leftPosition = 0;
    int rightPosition = 0;
    int mergePosition = 0;

    while ( leftPosition < m && rightPosition < n )
    {
        if ( u[ leftPosition ] <= v[ rightPosition ] )
        {
            t[ mergePosition ] = u[ leftPosition ];
            leftPosition++;
        }
        else
        {
            t[ mergePosition ] = v[ rightPosition ];
            rightPosition++;
        }

        mergePosition++;
    }

    while ( leftPosition < m )
    {
        t[ mergePosition ] = u[ leftPosition ];
        leftPosition++;
        mergePosition++;
    }

    while ( rightPosition < n )
    {
        t[ mergePosition ] = v[ rightPosition ];
        rightPosition++;
        mergePosition++;
    }
}