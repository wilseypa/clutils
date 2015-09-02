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
#include <string.h>
#include <strstream>
using std::ostrstream;
using std::istrstream;
using std::ends;

/* This is here solely to make something we can check for from configure. */
extern "C" {
  int fake(){ return 0; }
}

const string upperCase( const string &inputString ){
  string retval;
  for(unsigned int i = 0; i < inputString.length(); i++){
    retval += toupper( inputString[i] );
  }
  return retval;
}

const string trimWhiteSpaces( const string &inputString ){
  string retval;
  unsigned char value;
  while((value = retval.find(" ")) != string::npos){
    retval.erase(value, strlen(" "));
  }
  return retval;
}

const string intToString( int input ){
  string retval;
  ostrstream stream;
  stream << input << ends;
  char *asChar = stream.str();
  retval = asChar;
  stream.rdbuf()->freeze(0);
  return retval;
}

int stringToInt( const string &input ){
  int retval = -1;

  istrstream is( input.c_str() );
  is >> retval;
  
  return retval;
}

double stringToDouble( const string &input ){
  double retval = 0.0;

  istrstream is( input.c_str() );
  is >> retval;
  
  return retval;
}

bool stringCaseCompare( const string &s1, const string &s2 ){
  bool retval = (upperCase( s1 ) == upperCase( s2 ));
  return retval;
}
