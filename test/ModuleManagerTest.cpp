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

#include "ModuleManagerTest.h"
#include "ModuleManager.h"
#include "StringUtilities.h"
#include "Debug.h"
#include "ModuleBase.h"
#include "Greeter.h"

using std::endl;
using std::cout;
using std::cerr;;

ModuleManagerTest *
ModuleManagerTest::instance(){
  static ModuleManagerTest *myModuleManagerTest = new ModuleManagerTest();
  
  return myModuleManagerTest;
}

int 
ModuleManagerTest::instanceTest() const {
  int retval = 0;

  clutils::debug << "Starting instance test - ";

  const ModuleManager *fm1 = ModuleManager::instance();
  const ModuleManager *fm2 = ModuleManager::instance();

  if( fm1 == 0 || fm2 == 0 ){
    cerr << "Got a null instance for a ModuleManager!" << endl;
    retval = -1;
    goto end;
  }

  if( fm1 != fm2 ){
    cerr << "Got a two separate instances for ModuleManagers!" << endl;
    retval = -1;
    goto end;
  }

 end:
  if( retval == 0 ){
    clutils::debug << "passed." << endl;
  }

  return retval;
}

int
ModuleManagerTest::moduleListTest( const string &directory ) const {
  int retval = 0;

  clutils::debug << "Starting module list test - ";

  ModuleManager *mm = ModuleManager::instance();
  const vector<ModuleBase *> *moduleList = mm->getModuleList( directory );
  clutils::debug << "Found " << moduleList->size() << " modules" << endl;
  for( vector<ModuleBase *>::const_iterator i = moduleList->begin();
       i != moduleList->end();
       i++ ){
    ModuleBase *currentModule = *i;
    clutils::debug << "Found " << currentModule->getModuleName() << endl;
    Greeter *asGreeter = dynamic_cast<Greeter *>(currentModule);
    if( asGreeter == 0 ){
      clutils::debug << "Module loaded, but cast to Greeter * failed" << endl;
      retval = -1;
      break;
    }
    else{
      const string &greetings = asGreeter->getGreetings();
      clutils::debug << "Greetings = " << greetings << endl;
    }
  }

  if( retval == 0 ){
    clutils::debug << "passed." << endl;
  }

  return retval;
}

int 
ModuleManagerTest::regressionTest(){
  int status = instanceTest();
  const string directory = "modules";

  if( status != 0 ){
    goto end;
  }

  status = moduleListTest( directory );

 end:
  return status;
}
