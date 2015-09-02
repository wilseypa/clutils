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

#include "FrenchGreeter.h"

const string 
FrenchGreeter::getGreetings() const {
  static string myGreetings = "Bon Jour";
  return myGreetings;
}
  
const string 
FrenchGreeter::getModuleType() const {
  return "test";
}

const string 
FrenchGreeter::getModuleName() const {
  return "FrenchGreeter";
}


FrenchGreeter::FrenchGreeter(){}

FrenchGreeter::~FrenchGreeter(){}

extern "C"{
  void *allocateModule(){
    return new FrenchGreeter();
  }
}
