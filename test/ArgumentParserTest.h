#ifndef ARG_PARSER_TEST_H
#define ARG_PARSER_TEST_H

// Copyright (c) 2000-2003 Clifton Labs, Inc.  
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

#include <string>
using std::string;

class ArgumentParser;

class ArgumentParserTest {
public:
  /**
     This is a method that runs a self test to see if the ArgumentParser class
     is working as expected.

     @return 0 if passed, non zero if failed.
  */
  int regressionTest();
  
  /**
     Return the singleton test object.
  */
  static ArgumentParserTest *instance();

protected:
  /** Destructor */
  ~ArgumentParserTest(){}

private:
  /** Constructor */
  ArgumentParserTest() : boolArg(false), intArg(0), stringArg(""){}

  int testConstruction();
  int testNoneMatch();
  int testBoolMatch();
  int testIntMatch();
  int testStringMatch();
  int testMultiple();

  bool boolArg;
  int  intArg;
  string stringArg;

  ArgumentParser *getDefaultArgumentParser();
};
#endif
