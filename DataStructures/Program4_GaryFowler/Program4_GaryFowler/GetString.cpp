//------------------------------------------------------------------------------
// This function will read from the parameter file fn (from the keyboard or from 
// a user-defined text file) up to the parameter length number of characters to 
// be assigned to the parameter string s.
// It will start with the current cursor position and will leave the cursor at 
// the next position following the last character read.  Blanks are significant
// characters which will be read.  Input stops:
// 1) if the end-of-line marker is encountered, or
// 2) if the end-of-file marker is encountered, or
// 3) when the number of characters read is equal to the parameter length 
//------------------------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int GetString (ifstream & fn, string & s, int length)
{
   int  charCount;
   char ch;
   
   s.erase();             // Start with an empty string
   
   for (charCount = 0; charCount < length; charCount++)
   {  
      // Stop if there are fewer chars to be read than expected
      if (fn.peek() == '\n' || fn.peek() == EOF)  
         break;               
      else
      {
         ch = fn.get();   // Read next char (including blanks)
         s = s + ch;      // and append it to the string
      }
   }
   return charCount;      // Return actual count of chars read
}

