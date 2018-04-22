#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
#include <list>
#include <array>
#include <iterator>
using namespace std;

/* COMPLETE ME - complete the template definition of the how_long()
    function.
    
    how_long() should take two iterators as its input parameters.
    These iterators represent the beginning and end of the sequence.
    how_long() should return an integer saying how long the input sequence is.
    */

template<typename Type>

int how_long(Type begin, Type end){
  int count = 0;
  for(Type it = begin; it != end; it = next(it)) count++;
  
  return count;
}


int main()
{
    int errors = 0;

    vector<int> intItems { 1, 2, 3, 4, 5 };
    array<float,6> floatItems { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
    list<unsigned int> uintItems { 858993455, 858993456, 858993457, 858993458, 858993459 };
    
    int intAnswer = how_long( intItems.begin(), intItems.end() );
    int intExpected = 5;
    if( intAnswer != intExpected )
    {
        cerr << "how_long() did not work correctly when tested with ints or vectors" << endl
            << "  Expected " << "" << " but recieved " << intAnswer << " instead" << endl;
        errors += 1;
    }

    int floatAnswer = how_long( floatItems.begin(), floatItems.end() );
    int floatExpected = 6;
    if( floatAnswer != floatExpected )
    {
        cerr << "how_long() did not work correctly when tested with floats or arrays" << endl
            << "  Expected " << "" << " but recieved " << floatAnswer << " instead" << endl;
        errors += 1;
    }

    int uintAnswer = how_long( uintItems.begin(), prev(uintItems.end()) );
    int uintExpected = 4;
    if( uintAnswer != uintExpected )
    {
        cerr << "how_long() did not work correctly when tested with uints or lists" << endl
            << "  Expected " << uintExpected << " but recieved " << uintAnswer << " instead" << endl;
        errors += 1;
    }

    cout << "There were " << errors << " errors." << endl;

    return errors;
}
