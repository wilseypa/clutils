#ifndef FIELD_ITERATOR_H
#define FIELD_ITERATOR_H

// Copyright (c) 2004 Clifton Labs. All rights reserved.

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

#include "clutils/Iterator.h"

#include <string>
using std::string;

class FieldIterator : public Iterator<string> {
public:
  FieldIterator();
  FieldIterator( const string &initString, const string &initDelimiter );
  FieldIterator( const FieldIterator &that );
  ~FieldIterator();

  FieldIterator &operator=( const FieldIterator &that );

  bool hasNext() const;
  const string next() const;
  string next();

private:
  string myString;
  string myDelimiter;
  size_t beginPos, endPos;
};

#endif
