#ifndef STRING_UTILITIES_H
#define STRING_UTILITIES_H

// Copyright (c) 2000-2002 Clifton Labs.
// All rights reserved.

// Clifton Labs MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF 
// THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  Clifton Labs SHALL NOT BE LIABLE
// FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
// MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the
// U.S., and the terms of this license.

// Author: Dale E. Martin          dmartin@cliftonlabs.com

#include <string>
#include <strstream>

using std::string;

/** Uppercase the passed-in input string */
const string upperCase( const string &inputString );

/** Cut out all white spaces in passed-in input string */
const string trimWhiteSpaces( const string &inputString );

/**
   Return the integer passed in as a string.
*/
const string intToString( int input );

/**
   Take the string that represents an integer, and return an int.  Warning
   - no check is done to make sure that the string is really an integer.
   Undefined behavior will result in passing in a string that doesn't
   represent an integer.
*/
int stringToInt( const string &input );

/**
   Take the string containing a floating point value, and return a float.
   Warning - no check is done to make sure that the string is really an
   float.  Undefined behavior will result in passing in a string that
   doesn't represent a float.
*/
double stringToDouble( const string &input );

/**
   Compares if two strings are equal if one ignores case differences.
*/
bool stringCaseCompare( const string &s1, const string &s2 );


#endif
