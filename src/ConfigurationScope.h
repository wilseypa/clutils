#ifndef CONFIG_SCOPE_H
#define CONFIG_SCOPE_H

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
#include <vector>
#include "StringHashMap.h"
#include "ConfigurationChoice.h"
#include "ConfigurationValue.h"

class ConfigurationScope {
public:
  /**
     Constructor 
  */
  ConfigurationScope( const string &scopeName );

  /**
     Constructor 
  */
  ConfigurationScope( char *scopeName );

  /**
     Returns this ConfigurationScope's name.
  */
  const string &getScopeName() const { return myScopeName; }

  /**
     Finds the named ConfigurationScope that belongs to this scope.

     @param scopeName The name of the scope that is being sought.
     @return The named ConfigurationScope, if it exists, NULL otherwise.
  */
  const ConfigurationScope *findScope( const string &scopeName ) const;

  /**
     Finds the named ConfigurationChoice that belongs to this choice.

     @param choiceName The name of the choice that is being sought.
     @return The named ConfigurationChoice, if it exists, NULL otherwise.
  */
  const ConfigurationChoice *findChoice( const string &choiceName ) const;

  /**
     Returns the string value of the ConfigurationChoice name passed in.

     @param choiceName The name of the choice that is being sought.
     @return The value of the StringChoice, if found.  An empty string
     otherwise.
  */
  const string getStringValue( const string &choiceName ) const;

  /**
     Returns the int value of the ConfigurationChoice name passed in.

     @param choiceName The name of the choice that is being sought.
     @return The value of the IntChoice, if found.  -1 otherwise.
  */
  int getIntValue( const string &choiceName ) const;

  /**
     Returns the double value of the ConfigurationChoice name passed in.

     @param choiceName The name of the choice that is being sought.
     @return The value of the DoubleChoice, if found.  -1.0 otherwise.
  */
  double getDoubleValue( const string &choiceName ) const;

  
  /**
     Returns the nested scopes.
  */
  const vector<const ConfigurationScope *> *getNestedScopes() const;

  /**
     Returns the nested choices.
  */
  const vector<const ConfigurationChoice *> *getNestedChoices() const;

  /**
     Adds the ConfigurationScope to this ConfigurationScope's nested scopes.
  */
  void addScope( const ConfigurationScope *toAdd );

  /**
     Adds the ConfigurationChoice to this ConfigurationChoice's subchoices.
  */
  void addChoice( const ConfigurationChoice *toAdd );

private:
  const string &myScopeName;
  StringHashMap<const ConfigurationScope *> myNestedScopes;
  StringHashMap<const ConfigurationChoice *> myChoices;

};

#endif
