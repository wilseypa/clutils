#ifndef CONFIG_CHOICE_H
#define CONFIG_CHOICE_H

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

class ConfigurationValue;

class ConfigurationChoice {
public:
  /**
     Constructor
   */
  ConfigurationChoice( const string propertyName );
  
  /**
     Constructor
   */
  ConfigurationChoice( char *propertyName );

  /**
     Returns the property name.
   */
  const string &getPropertyName() const {
    return myPropertyName;
  }

  /** 
      If this is a string valued choice, the string value is returned.
      Else a runtime error is produced.
   */
  const string &getStringValue() const;

  int getIntValue() const;

  const ConfigurationValue *getConfigurationValue() const {
    return myConfigurationValue;
  }

  void setConfigurationValue( const ConfigurationValue *newValue ){
    myConfigurationValue = newValue;
  }

private:
  ConfigurationChoice( const ConfigurationChoice & ){ abort(); }
  ConfigurationChoice operator=( const ConfigurationChoice & ){ abort(); }


  const string myPropertyName;
  const ConfigurationValue *myConfigurationValue;
};

#endif
