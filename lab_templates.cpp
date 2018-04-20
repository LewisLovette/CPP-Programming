#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
using namespace std;

/* COMPLETE ME - complete the template definition of the times()
    function.
    
    times() should take two parameters (a and b) of the same type and then 
    return a value of the same type that is equal a and b multiplied together.

    There is one special case, if a is a string and b is an int.
    In this case times() should return a value of a concatenated together b times. */


//Instead of writing multiple functions for different data types
//we instead make a teamplate with a new type that the compile will figure out
template<typename TYPE>
TYPE times(TYPE a, TYPE b){
        return a * b;//means we don't have to make multiple functions for different primatives
}

int main()
{
    int i = times( 42, -69 );
    float f = times( 1.23f, 4.56f );
    unsigned int ui = times( std::numeric_limits<int>::max()-1, 2 );

    int errors = 0;

    if( i != 42*-69 )
    {
        cout << "int times( int, int ) failed" << endl
            <<  "  expected " << 42*-46 << ", got " << i << endl;
        errors++;
    }

    if( f != 1.23f*4.56f )
    {
        cout << "float times( float, float ) failed" << endl
            <<  "  expected " << 1.23f*4.56f << ", got " << f << endl;
        errors++;
    }

    if( ui != (std::numeric_limits<int>::max()-1)*2 )
    {
        cout << "unsigned int times( unsigned int, unsigned int ) failed" << endl
             <<  "  expected " << (std::numeric_limits<int>::max()-1)*2 << ", got " << ui << endl;
        errors++;
    }

    cout << "There were " << errors << " errors" << endl;

    return errors;
}