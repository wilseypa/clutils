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

#include "ConfigurationScope.h"
#include "StringUtilities.h"
#include <string.h>

ConfigurationScope::ConfigurationScope( const string &scopeName ) : 
  myScopeName( scopeName ){}

ConfigurationScope::ConfigurationScope( const char *scopeName ) : 
  myScopeName( *new string( strdup(scopeName) ) ){}

ConfigurationScope::~ConfigurationScope()
{
	myNestedScopes.erase();
	myChoices.erase();
}

const ConfigurationScope *
ConfigurationScope::findScope( const string &scopeName ) const {
  return myNestedScopes.find( scopeName );
}

const ConfigurationChoice *
ConfigurationScope::findChoice( const string &choiceName ) const {
  return myChoices.find( choiceName );
}

const string
ConfigurationScope::getStringValue( const string &choiceName ) const {
  string retval("");

  const ConfigurationChoice *choice = findChoice( choiceName );
  if( choice != 0 ){
    const ConfigurationValue *value = choice->getConfigurationValue();
    if( value->getType() == ConfigurationValue::STRING ){
      const StringConfigurationValue *asString = 
	static_cast<const StringConfigurationValue *>(value);
      retval = asString->getStringValue();
    }
  }
  return retval;
}

int
ConfigurationScope::getIntValue( const string &choiceName ) const {
  const ConfigurationChoice *choice = findChoice( choiceName );
  if( choice != 0 ){
    const ConfigurationValue *value = choice->getConfigurationValue();
    if( value->getType() == ConfigurationValue::INT ){
      return dynamic_cast<const IntConfigurationValue *>(value)->getIntValue();
    }
  }
  return -1;
}

double
ConfigurationScope::getDoubleValue( const string &choiceName ) const {
  const ConfigurationChoice *choice = findChoice( choiceName );
  if( choice != 0 ){
    const ConfigurationValue *value = choice->getConfigurationValue();
    if( value->getType() == ConfigurationValue::DOUBLE ){
      return dynamic_cast<const DoubleConfigurationValue *>(value)->getDoubleValue();
    }
  }
  return -1;
}


void 
ConfigurationScope::addScope( const ConfigurationScope *toAdd ){
  myNestedScopes.insert( toAdd->getScopeName(), toAdd );
}

void 
ConfigurationScope::addChoice( const ConfigurationChoice *toAdd ){
  myChoices.insert( toAdd->getPropertyName(), toAdd );
}

const vector<const ConfigurationScope *> *
ConfigurationScope::getNestedScopes() const {
  const vector<const ConfigurationScope *> *retval = myNestedScopes.getElementVector();
  return retval;
}

  /**
     Returns the nested choices.
  */
const vector<const ConfigurationChoice *> *
ConfigurationScope::getNestedChoices() const {
  const vector<const ConfigurationChoice *> *retval = myChoices.getElementVector();
  return retval;    
}
