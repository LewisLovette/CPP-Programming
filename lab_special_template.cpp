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
    In this case times() should return a value of the a parameter repeated 
    b times. */

template <typename Type>
Type times(Type a, Type b){
  return a*b;
}

//Special case
string times(string a, int b){
  string c, temp = a;
  for(int i = 0; i < b; i++) c += temp;
  return c;
}


int main()
{
    int i = times( 42, 69 );
    float f = times( 1.23f, 4.56f );
    unsigned int ui = times( std::numeric_limits<int>::max()-1, 2 );
    string s = times( "hello", 3 );

    int errors = 0;

    if( i != 42*69 )
    {
        cout << "int times( int, int ) failed" << endl
            <<  "  expected " << 42*46 << ", got " << i << endl;
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

    if( s != "hellohellohello" )
    {
        cout << "string times( string, string ) failed" << endl
            <<  "  expected " << "hellohellohello" << ", got " << s << endl;
        errors++;
    }

    cout << "There were " << errors << " errors" << endl;

    return errors;
}