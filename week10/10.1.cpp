#include <stdio.h>

long SumLoop( int );
long SumRecur( int );

int main() {

    printf( "SumLoop(n) = %d", SumLoop( 10 ) );
    printf( "\nSumRecur(n) = %d", SumRecur( 10 ) );

    return 0;
}

long SumLoop( int n ) {

    long sum = 0;
    int i;

    for ( i = 1; i <= n; i++ ) {
        sum += i;
    }

    return sum;
}

long SumRecur( int n ) {

    if ( n <= 1 ) {
        return n;
    }

    return n + SumRecur( n - 1 );
}