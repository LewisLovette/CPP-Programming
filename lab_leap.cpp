#include <iostream>
using namespace std;

bool leap_year( int year )
{
    // COMPLETE ME
    if(year%4 == 0 and (year != 1800 and year != 1900 and year != 2100)){
      return true;
    }
    return false;
}