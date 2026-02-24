#include <stdio.h>
#include <stdlib.h>

int *Dijkstra( int *L, int n );

int main()
{
    int n = 5;
    int rowIndex = 0;
    int columnIndex = 0;
    int *d;
    int *g;

    g = (int *)malloc( n * n * sizeof( int ) );

    for ( rowIndex = 0; rowIndex < n; rowIndex++ )
    {
        for ( columnIndex = 0; columnIndex < n; columnIndex++ )
        {
            g[ rowIndex * n + columnIndex ] = -1;
        }
    }

    g[ 0 * n + 1 ] = 100;
    g[ 0 * n + 2 ] = 80;
    g[ 0 * n + 3 ] = 30;
    g[ 0 * n + 4 ] = 10;

    g[ 1 * n + 2 ] = 20;
    g[ 3 * n + 1 ] = 20;
    g[ 3 * n + 2 ] = 20;
    g[ 4 * n + 3 ] = 10;

    d = Dijkstra( g, n );

    for ( rowIndex = 0; rowIndex < n - 1; rowIndex++ )
    {
        printf( "%d ", d[ rowIndex ] );
    }

    free( g );
    free( d );

    return 0;
}

int *Dijkstra( int *L, int n )
{
    int *distance;
    int *visited;
    int nodeIndex;
    int neighborIndex;
    int minimumDistance;
    int selectedNode;
    int iteration;

    distance = (int *)malloc( ( n - 1 ) * sizeof( int ) );
    visited = (int *)malloc( n * sizeof( int ) );

    for ( nodeIndex = 0; nodeIndex < n; nodeIndex++ )
    {
        visited[ nodeIndex ] = 0;
    }

    for ( nodeIndex = 1; nodeIndex < n; nodeIndex++ )
    {
        distance[ nodeIndex - 1 ] = L[ 0 * n + nodeIndex ];
    }

    visited[ 0 ] = 1;

    for ( iteration = 1; iteration < n; iteration++ )
    {
        minimumDistance = 1000000;
        selectedNode = -1;

        for ( nodeIndex = 1; nodeIndex < n; nodeIndex++ )
        {
            if ( visited[ nodeIndex ] == 0 )
            {
                if ( distance[ nodeIndex - 1 ] != -1 &&
                     distance[ nodeIndex - 1 ] < minimumDistance )
                {
                    minimumDistance = distance[ nodeIndex - 1 ];
                    selectedNode = nodeIndex;
                }
            }
        }

        if ( selectedNode == -1 )
        {
            break;
        }

        visited[ selectedNode ] = 1;

        for ( neighborIndex = 1; neighborIndex < n; neighborIndex++ )
        {
            if ( visited[ neighborIndex ] == 0 )
            {
                if ( L[ selectedNode * n + neighborIndex ] != -1 )
                {
                    int newDistance =
                        minimumDistance +
                        L[ selectedNode * n + neighborIndex ];

                    if ( distance[ neighborIndex - 1 ] == -1 ||
                         newDistance < distance[ neighborIndex - 1 ] )
                    {
                        distance[ neighborIndex - 1 ] = newDistance;
                    }
                }
            }
        }
    }

    free( visited );

    return distance;
}