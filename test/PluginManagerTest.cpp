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

#include "PluginManagerTest.h"
#include <clutils/PluginManager.h>
#include <clutils/StringUtilities.h>
#include <clutils/Debug.h>
#include <clutils/PluginBase.h>
#include "Greeter.h"

using std::endl;
using std::cout;
using std::cerr;;

PluginManagerTest *
PluginManagerTest::instance(){
  static PluginManagerTest *myPluginManagerTest = new PluginManagerTest();
  
  return myPluginManagerTest;
}

int 
PluginManagerTest::instanceTest() const {
  int retval = 0;

  clutils::debug << "Starting instance test - ";

  const PluginManager *fm1 = PluginManager::instance();
  const PluginManager *fm2 = PluginManager::instance();

  if( fm1 == 0 || fm2 == 0 ){
    cerr << "Got a null instance for a PluginManager!" << endl;
    retval = -1;
    goto end;
  }

  if( fm1 != fm2 ){
    cerr << "Got a two separate instances for PluginManagers!" << endl;
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
PluginManagerTest::pluginListTest( const string &directory ) const {
  int retval = 0;

  clutils::debug << "Starting plugin list test - ";

  PluginManager *mm = PluginManager::instance();
  const vector<PluginBase *> *pluginList = mm->getPluginList( directory );
  clutils::debug << "Found " << pluginList->size() << " plugins" << endl;
  if( pluginList->size() > 0 ){
    for( vector<PluginBase *>::const_iterator i = pluginList->begin();
	 i != pluginList->end();
	 i++ ){
      PluginBase *currentPlugin = *i;
      clutils::debug << "Found " << currentPlugin->getPluginName() << endl;
      Greeter *asGreeter = static_cast<Greeter *>(currentPlugin);
      if( asGreeter == 0 ){
	clutils::debug << "Plugin loaded, but cast to Greeter * failed" << endl;
	retval = -1;
	break;
      }
      else{
	const string &greetings = asGreeter->getGreetings();
	clutils::debug << "Greetings = " << greetings << endl;
      }
    }
  }
  else{
    cerr << "Failed to find any plugins - something is wrong!" << endl;
    retval = -1;
  }
  if( retval == 0 ){
    clutils::debug << "passed." << endl;
  }

  return retval;
}

int 
PluginManagerTest::regressionTest(){
  int status = instanceTest();
  const string directory = "plugins";

  if( status != 0 ){
    goto end;
  }

  status = pluginListTest( directory );

 end:
  return status;
}
