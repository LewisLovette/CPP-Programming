#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Morseifier
{
private:  //Setting up dictionary again ;-;
    map<char,string> morse { {'A', ".-"},
                             {'B', "-..."},
                             {'C', "-.-."},
                             {'D', "-.."},
                             {'E', "."},
                             {'F', "..-."},
                             {'G', "--."},
                             {'H', "...."},
                             {'I', ".."},
                             {'J', ".---"},
                             {'K', "-.-"},
                             {'L', ".-.."},
                             {'M', "--"},
                             {'N', "-."},
                             {'O', "---"},
                             {'P', ".--."},
                             {'Q', "--.-"},
                             {'R', ".-."},
                             {'S', "..."},
                             {'T', "-"},
                             {'U', "..-"},
                             {'V', "...-"},
                             {'W', ".--"},
                             {'X', "-..-"},
                             {'Y', "-.--"},
                             {'Z', "--.."},
                             {'0', "-----"},
                             {'1', ".----"},
                             {'2', "..---"},
                             {'3', "...--"},
                             {'4', "....-"},
                             {'5', "....."},
                             {'6', "-...."},
                             {'7', "--..."},
                             {'8', "---.."},
                             {'9', "----."},
                             {' ', "/"} };
    //Swapping values and pairs again
    map<string, char> unmorse;// = { value: key for key, value in morse.items() }

public:
    Morseifier()
    {
        // create the morse code to english lookup map by simply iterating over the morse map and swapping the keys and values
        for( auto character : morse )
        {
            unmorse.insert( make_pair( character.second, character.first ) );
        }
    }

    /* A function that takes a string as input and 
        translates it into morse code before returning it */
    string translate( string text ) //changing to morse
    {
        string answer = "";
        // convert each letter to morse
        for( char c : text )
        {
            answer += morse[toupper(c)] + " ";
        }

        // remove the trailing space
        if( !answer.empty() and answer.back() == ' ' )
        {
            answer.pop_back();
        }

        return answer;
    }

    /* A function  that takes a string as input and
        translates it from morse code before returning it */
    string untranslate( string morse )  //opposie of above
    {
        string answer = "";
        istringstream iss( morse );

        // convert each section of morse to a letter
        do
        {
            string m;
            iss >> m;

            if( m.empty() ) continue;

            answer += unmorse[m];
        }
        while( iss );
        
        return answer;
    }
};