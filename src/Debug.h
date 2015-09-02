#ifndef DEBUG_H
#define DEBUG_H

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

#include <iostream>

using std::ostream;
using std::streambuf;
using std::streamsize;

  
class EatEverythingBuf : public streambuf {
public:
  static EatEverythingBuf *instance();
  
  int sync (){ return 0; }
    
  int overflow(int ch){ return EOF + 1; }
  
  streamsize xsputn( char *s, streamsize n ){ return n; }
  
private:
  EatEverythingBuf(){}
};

namespace clutils {
  void enableDebug();
  void disableDebug();
  
  extern ostream debug;
}

#endif
