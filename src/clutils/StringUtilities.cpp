// Copyright (c) 2000-2002 Clifton Labs, Inc.  
// All rights reserved.

// Clifton Labs MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF 
// THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  Clifton Labs SHALL NOT BE LIABLE
// FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
// RESULT OF USING, MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS
// DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the
// U.S., and the terms of this license.

// Authors: Dale E. Martin   dmartin@cliftonlabs.com

#include "StringUtilities.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
using std::ostringstream;
using std::istringstream;

/* This is here solely to make something we can check for from configure. */
extern "C" {
  int isClutils(){ return 0; }
}

const string upperCase( const string &inputString ){
  string retval;
  for(unsigned int i = 0; i < inputString.length(); i++){
    retval += toupper( inputString[i] );
  }
  return retval;
}

const string trimWhiteSpaces( const string &inputString ){
  string retval( inputString );
  char value = retval.find(" ");
  while( value != (char)string::npos ){
    retval.erase(value, strlen(" "));
    value = retval.find(" ");
  }
  return retval;
}

const string intToString( int input ){
  ostringstream stream;
  stream << input;
  return stream.str();
}

const string doubleToString( double input ){
  ostringstream stream;
  stream << input;
  return stream.str();
}

long
stringToLong( const string &input, int &endPos ){
  long retval = -1;

  char *endPtr = 0;
  retval = strtol( input.c_str(), &endPtr, 10 );
  endPos = endPtr - input.c_str();
  
  return retval;
}

double stringToDouble( const string &input, int &endPos ){
  double retval = -1;

  char *endPtr = 0;
  retval = strtod( input.c_str(), &endPtr );
  endPos = endPtr - input.c_str();
  
  return retval;
}

bool stringCaseCompare( const string &s1, const string &s2 ){
  bool retval = (upperCase( s1 ) == upperCase( s2 ));
  return retval;
}
