#ifndef STRING_HASH_MAP_H
#define STRING_HASH_MAP_H

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

#include "clutils-config.h"

#ifdef HAVE_HASH_MAP
#include <hash_map>
#else
#ifdef HAVE_EXT_HASH_MAP
#include <ext/hash_map>
#else
#error "Couldn't find #include<hash_map> or #include<ext/hash_map>"
#endif
#endif

#include "StringUtilities.h"

#include <string>
#include <vector>

using std::hash_map;
using std::string;
using std::vector;

class hashString {
public:
  size_t operator()( const string &s ) const;
};

class hashEqual {
public:
  bool operator()( const string &s1, const string &s2 ) const;
};


template <class toHash> class StringHashMap {

public:
  StringHashMap(){}
  ~StringHashMap(){}
  
  toHash find( const string &key ) const {
    toHash retval = 0;

    hash_map<string, toHash, hashString, hashEqual>::const_iterator found =
      myHashMap.find( key );
  
    if( found != myHashMap.end() ){
      retval = (*found).second;
    }
  
    return retval;
  }

  void insert( const string &key, toHash value ){
    myHashMap[ key ] = value;
  }


  const vector<toHash> *toVector() const {
    vector<toHash> *retval = new vector<toHash>();
    for( hash_map<string, toHash, hashString, hashEqual>::const_iterator i = myHashMap.begin();
	 i != myHashMap.end();
	 i++ ){
      retval->push_back( (*i).second );
    }

    return retval;
  }

private:
    hash_map<string, toHash, hashString, hashEqual> myHashMap;
};
#endif

