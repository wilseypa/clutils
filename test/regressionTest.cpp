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

#include <iostream.h>
#include "FileManagerTest.h"
#include "ModuleManagerTest.h"
#include "ConfigurationParserTest.h"

bool oneFailed = false;

void testFileManager(){
  int fileManagerStatus = FileManagerTest::instance()->regressionTest();
  if( fileManagerStatus != 0 ){
    cerr << "FileManager test failed." << endl;
    oneFailed = true;
  }
  else{
    cerr << "FileManager test passed." << endl;
  }
}

void testModuleManager(){
  int moduleManagerStatus = ModuleManagerTest::instance()->regressionTest();
  if( moduleManagerStatus != 0 ){
    cerr << "ModuleManager test failed." << endl;
    oneFailed = true;
  }
  else{
    cerr << "ModuleManager test passed." << endl;
  }
}

void testConfigurationParser(){
  int configurationParserStatus = ConfigurationParserTest::instance()->regressionTest();
  if( configurationParserStatus != 0 ){
    cerr << "ConfigurationParser test failed." << endl;
    oneFailed = true;
  }
  else{
    cerr << "ConfigurationParser test passed." << endl;
  }
}


int
main( int argc, char *argv[] ){
  testFileManager();
  testModuleManager();
  testConfigurationParser();

  if( oneFailed == true ){
    cerr << "WARNING - AT LEAST ONE TEST FAILED" << endl;
  }
  else{
    cerr << "All tests passed" << endl;
  }
}

