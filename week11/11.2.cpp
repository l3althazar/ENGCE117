#include <stdio.h>

void mergesort( int t[], int k );
void merge( int *u, int m, int *v, int n, int *t );

int main()
{
    int data[ 7 ] = { 4, 6, 1, 2, 5, 1, 8 };
    int n = 7;

    mergesort( data, n );

    for ( int index = 0; index < n; index++ )
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

    int middle = k / 2;

    int leftSize = middle;
    int rightSize = k - middle;

    int leftArray[ leftSize ];
    int rightArray[ rightSize ];

    for ( int leftIndex = 0; leftIndex < leftSize; leftIndex++ )
    {
        leftArray[ leftIndex ] = t[ leftIndex ];
    }

    for ( int rightIndex = 0; rightIndex < rightSize; rightIndex++ )
    {
        rightArray[ rightIndex ] = t[ middle + rightIndex ];
    }

    mergesort( leftArray, leftSize );
    mergesort( rightArray, rightSize );

    merge( leftArray, leftSize, rightArray, rightSize, t );
}

void merge( int *u, int m, int *v, int n, int *t )
{
    int leftIndex = 0;
    int rightIndex = 0;
    int mergedIndex = 0;

    while ( leftIndex < m && rightIndex < n )
    {
        if ( u[ leftIndex ] <= v[ rightIndex ] )
        {
            t[ mergedIndex ] = u[ leftIndex ];
            leftIndex++;
        }
        else
        {
            t[ mergedIndex ] = v[ rightIndex ];
            rightIndex++;
        }

        mergedIndex++;
    }

    while ( leftIndex < m )
    {
        t[ mergedIndex ] = u[ leftIndex ];
        leftIndex++;
        mergedIndex++;
    }

    while ( rightIndex < n )
    {
        t[ mergedIndex ] = v[ rightIndex ];
        rightIndex++;
        mergedIndex++;
    }
}