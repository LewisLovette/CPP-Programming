#include <iostream>
#include <tuple>
#include <vector>
#include <bitset>
#include <math.h>
using namespace std;

int harmony( int a, int b )
{
    // convert to binary
    bitset<8> aBinary( a ); //automatically transforms to 8 bits
    bitset<8> bBinary( b );

    // count number of bits set
    // standard for loop to check if they're even
    int count = 0;
    for( int i=0; i<8; ++i )
    {
        if( aBinary[i] == bBinary[i] )
        {
            ++count;
        }
    }

    // convert to percentage
    // would've created int then returned int but this is neater
    return nearbyint( count /8.0 * 100.0 );
}