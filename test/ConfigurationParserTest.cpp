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

#include "Debug.h"
#include "tokens.h"
#include "ConfigurationParserTest.h"
#include "ConfigurationParserHandle.h"
#include "StringUtilities.h"
#include <fstream.h>
#include <stdio.h>

ConfigurationParserTest *
ConfigurationParserTest::instance(){
  static ConfigurationParserTest *myConfigurationParserTest = new ConfigurationParserTest();
  
  return myConfigurationParserTest;
}

int 
ConfigurationParserTest::parseFileTest(){
  int retval = 0;

  const string testFileName = "configurationParserTest.cfg";
  const ConfigurationScope *outerScope = ConfigurationParserHandle::parseFile( testFileName );
  
  if( outerScope == 0 ){
    retval = -1;
  }

  return retval;
}


// int 
// ConfigurationParserTest::instanceTest() const {
//   int retval = 0;

//   debug << "Starting instance test - ";

//   const ConfigurationParser *fm1 = ConfigurationParser::instance();
//   const ConfigurationParser *fm2 = ConfigurationParser::instance();

//   if( fm1 == 0 || fm2 == 0 ){
//     cerr << "Got a null instance for a ConfigurationParser!" << endl;
//     retval = -1;
//     goto end;
//   }

//   if( fm1 != fm2 ){
//     cerr << "Got a two separate instances for ConfigurationParsers!" << endl;
//     retval = -1;
//     goto end;
//   }

//  end:
//   if( retval == 0 ){
//     debug << "passed." << endl;
//   }

//   return retval;
// }


int 
ConfigurationParserTest::regressionTest(){
  int retval = 0;

  clutils::enableDebug();

  retval = parseFileTest();
  if( retval != 0 ){
    goto end;
  }

 end:
  return retval;
}
