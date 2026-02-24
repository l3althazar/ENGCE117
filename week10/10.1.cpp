#include <stdio.h>

long SumLoop( int );
long SumRecur( int );

int main() {

    printf( "SumLoop(n) = %ld\n", SumLoop( 10 ) );
    printf( "SumRecur(n) = %ld", SumRecur( 10 ) );

    return 0;
}

long SumLoop( int n ) {

    long total = 0;
    int index;

    for ( index = 1; index <= n; index++ ) {
        total += index;
    }

    return total;
}

long SumRecur( int n ) {

    if ( n <= 1 ) {
        return n;
    }

    return n + SumRecur( n - 1 );
}