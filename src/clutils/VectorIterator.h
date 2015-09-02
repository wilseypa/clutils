#ifndef VECTOR_ITERATOR_H
#define VECTOR_ITERATOR_H

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

#include <clutils/Iterator.h>
#include <vector>
using std::vector;

template <class Type>
class VectorIterator : public Iterator<Type> {
public:
  VectorIterator( const vector<Type> &initList ) :
    myIterator( initList.begin() ),
    myList( initList ){}
  
  bool hasNext() const { return myIterator < myList.end(); }

  const Type next() const { 
    return const_cast<VectorIterator<Type> *>(this)->next();
  }
  
  Type next(){ 
    Type retval = *myIterator;
    myIterator++;
    return retval;
  }

private:
  typename vector<Type>::const_iterator myIterator;
  const vector<Type> &myList;
};

#endif
