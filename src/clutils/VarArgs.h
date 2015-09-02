#ifndef VARARGS_HH
#define VARARGS_HH

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

#include <clutils/VectorIterator.h>
#include <vector>
using std::vector;

template <typename Type>
class VarArgs {
public:
  VarArgs &add( Type item ){
    myData.push_back( item );
    return *this;
  }

  const VectorIterator<Type> iterator() const {
    return VectorIterator<Type>(myData);
  }

  VectorIterator<Type> iterator(){
    return VectorIterator<Type>(myData);
  }

  int length() const {
    return myData.size();
  }

  VarArgs &operator<<( Type item ){
    myData.push_back(item);
    return *this;
  }

  virtual ~VarArgs();

private:
  vector<Type> myData;
};

template<typename Type>
inline
VarArgs<Type>::~VarArgs(){}

#endif
