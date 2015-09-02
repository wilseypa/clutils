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

#include "ModuleManager.h"
#include "ModuleBase.h"
#include "FileManager.h"
#include <strstream.h>
#include <assert.h>
#include <iostream.h>
#include <ltdl.h>

ModuleManager * 
ModuleManager::instance(){
  static ModuleManager *instance = new ModuleManager();
  return instance;
}

ModuleManager::ModuleManager(){
  lt_dlinit();
}

ModuleManager::~ModuleManager(){}

const vector<ModuleBase *> *
ModuleManager::getModuleList( const string &dir ){
  vector<ModuleBase *> *retval = new vector<ModuleBase *>;

  //get a file manager
  const FileManager* filemanager = FileManager::instance();

  //pointer to the allocate function in every library
  const vector<string> *fileList = filemanager->getAllFiles( ".*la$", dir );
  if( fileList != 0 ){
    string currentFile;
    for( vector<string>::const_iterator i = fileList->begin();
	 i != fileList->end();
	 i++ ){
      currentFile = *i;
      ModuleBase *currentModule = loadModule( currentFile );
      if( currentModule != 0 ){
	retval->push_back( currentModule );
      }
      else{
	cerr << "Error loading module " << *i << ", error was \"" << lastError << "\"" << endl;
      }
    }
  }

  return retval;
}

ModuleBase *
ModuleManager::loadModule( const string &fileName ){
  ModuleBase *retval = 0;

  lt_dlhandle lib_handle;
  //try to dlopen
  lib_handle = lt_dlopenext( fileName.c_str() );
  if( lib_handle == 0 ){
    lastError = lt_dlerror();
  }
  else{
    //get the allocate funcation
    void* (* allocateFunction)()=0;

    allocateFunction = (void *(*)())lt_dlsym(lib_handle, "allocateModule");
    const char *error = lt_dlerror();
    if( error != 0 ){       
      lastError = error;
      lt_dlclose(lib_handle);
    }     
    else{
      //cast to savant_ModuleBase
      retval = static_cast<ModuleBase *>((*allocateFunction)());
      if( retval->getModuleSignature() != ModuleBase::moduleSignature() ){
	lastError = "invalid module signature";
      }
      //      dlclose(lib_handle);
    }
  }

  return retval;
}

const string &
ModuleManager::getLastError() const {
  return lastError;
}


bool 
ModuleManager::isValidModule( const string &fileName ){
  bool retval = false;
  ModuleBase *module = loadModule( fileName );
  if( module != 0 ){
    retval = true;
    delete module;
  }
  return retval;
}

