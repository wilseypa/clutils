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

#include "StringHashMap.h"

// template <bool caseSensitive>
// size_t
// HashString<caseSensitive>::operator()( const string &s ) const {
//   hash<const char *> H;
//   string toHash;
//   if( caseSensitive ){
//     toHash = s;
//   }
//   else{
//     toHash = upperCase(s);
//   }
//   return H( toHash.c_str() );
// }

// template <bool caseSensitive>
// bool 
// HashEqual<caseSensitive>::operator()( const string &s1, const string &s2 ) const{
//   if( caseSensitive ){
//     return s1 == s2;
//   }
//   else{
//     return stringCaseCompare(s1, s2);
//   }
// }
