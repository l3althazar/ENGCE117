#include <stdio.h>

int BinSearch( int dataArray[], int arraySize, int targetValue );

int main()
{
    int data[ 6 ] = { 1, 2, 3, 4, 5, 7 };
    int n = 6;
    int find = 5;
    int pos = BinSearch( data, n, find );

    if ( pos != -1 )
    {
        printf( "Found %d at %d", find, pos );
    }
    else
    {
        printf( "Not found" );
    }

    return 0;
}

int BinSearch( int dataArray[], int arraySize, int targetValue )
{
    int leftIndex = 0;
    int rightIndex = arraySize - 1;
    int middleIndex;

    while ( leftIndex <= rightIndex )
    {
        middleIndex = ( leftIndex + rightIndex ) / 2;

        if ( dataArray[ middleIndex ] == targetValue )
        {
            return middleIndex;
        }
        else if ( dataArray[ middleIndex ] < targetValue )
        {
            leftIndex = middleIndex + 1;
        }
        else
        {
            rightIndex = middleIndex - 1;
        }
    }

    return -1;
}