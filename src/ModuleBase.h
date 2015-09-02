#ifndef MODULE_BASE
#define MODULE_BASE

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
using std::string;

/**
   This is the base class for all modules.  Savant modules should be derived from 
   savant_ModuleBase.

*/

class ModuleBase {
public:
  /** @return a string saying what the module is for.  For example, it
   could return the name of the system for which this module was
   constructed. */
  virtual const string getModuleType() const = 0;

  /** @return the name of this particular module. */
  virtual const string getModuleName() const = 0;

  virtual ~ModuleBase()=0; 

  static const int moduleSignature();

  const int getModuleSignature();

protected:
  ModuleBase();
  int crap;
};



#endif
