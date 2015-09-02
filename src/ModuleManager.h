#ifndef _MODULE_MANAGER
#define _MODULE_MANAGER

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

#include <vector>
#include <string>

using std::vector;
using std::string;

class ModuleBase;

/**
   the purpose of this class is to manage module loading.
*/

class ModuleManager {

public:
  /**
     Returns the singleton instance of the ModuleManager.
   */
  static ModuleManager* instance();


  /**
     Determines a list of savant modules in dir. The file names are added to library_list
     inside of wrapper_container.
     @param dir Directory to look in for modules.
     @library_list: list where the filenames will be added.

     @return List of available modules if any are available, 0 otherwise.
   */
  const vector<ModuleBase *> *getModuleList( const string &dir );
  
  /**
     Returns the last error seen when attempting to load a module.  When a
     call fails, this method should be called to see what happened.
  */
  const string &getLastError() const;

  /**
     Load the named module.  Returns NULL if it couldn't be loaded, and
     "getLastError" will contain the reason.
  */
  ModuleBase *loadModule( const string &fileName );

protected:
  /**
     Destructor
   */
  ~ModuleManager();

private:
  /**
     Constructor
   */
  ModuleManager();

  /**
     Performs neccessary work to make sure filename is a valid SAVANT archieve.
     @param filename  Filename to check
     returns true if filename is a savant module otherwise false.
     
     To determine if filename is a savant archieve, it dlopens the file and calls allocate_module.
     It then casts the result to a ModuleBase, and calls ModuleBase:: module_type.  If 
     this matches savant_ModuleBase:: savant_module_type then filename is condidered to be a 
     savant module.
   */
  bool isValidModule( const string &fileName );
  string lastError;
};


#endif
