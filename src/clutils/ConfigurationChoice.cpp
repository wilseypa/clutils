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

#include <assert.h>
#include <string.h>
#include "ConfigurationValue.h"
#include "ConfigurationChoice.h"
#include "StringUtilities.h"

ConfigurationChoice::ConfigurationChoice( const string propertyName ): 
  myPropertyName( propertyName ), myConfigurationValue( 0 ){}

ConfigurationChoice::ConfigurationChoice( const char *propertyName ): 
  myPropertyName( *new string( strdup(propertyName) ) ), myConfigurationValue( 0 ){}

const string &
ConfigurationChoice::getStringValue() const {
  assert( myConfigurationValue != 0 );
  return myConfigurationValue->getStringValue();
}

int 
ConfigurationChoice::getIntValue() const {
  assert( myConfigurationValue != 0 );
  return myConfigurationValue->getIntValue();
}
